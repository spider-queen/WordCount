#include<stdio.h> 
#include<stdlib.h>
#include<ctype.h>
#include <string.h>


int countc(char*file);
int countw(char*file);
int main(int argc, char *argv[])
{
	char data;
	FILE *fb=fopen(argv[2],"r");
	if(!fb)
	{
		printf("�ļ���ȡʧ��\n");
		return -1;
	}
	if(!strcmp(argv[1],"-c"))
	{
		countc(argv[2]);
	}
	else if(!strcmp(argv[1],"-w"))
	{
		countw(argv[2]);
	}
	else
	{
		printf("�������\n");
	}
	return 0;
}
int countc(char*file)
{
	FILE *fb;
	fb=fopen(file,"r");
	char temp;
    int num = 0;
    temp = fgetc(fb); 
    while( temp != EOF )
	{
		temp = fgetc(fb);
    	num++;
    }
	printf("���ı��ļ����ַ���Ϊ��%d\n",num);
}
int countw(char*file)
{
	FILE *fb=fopen(file,"r");
	int w = 0;
    char a = fgetc(fb);
	while(a!= EOF)
	{
		if((a >='a' && a <='z') || ( a >='A' && a <='Z') || ( a >='0' && a <='9'))
		{
				w++;
			while((a >='a' && a <='z') || ( a >='A' && a <='Z') || ( a >='0' && a <='9'))
			{
				a =fgetc(fb);
            }
        }
		else
		{
			a =fgetc(fb);
		}
	}
		printf("���ı��ļ��ĵ�����Ϊ��%d\n",w);
}
