#include<cstdio>
#include<cstring>

int len, l;
char s[200];

int main()
{
	gets(s);
	len = strlen(s);
	if (s[0] == 'h')
	{
		printf("http://");
		printf("%c", s[4]); 
		for (int i = 5; i < len - 1; i++)
		{
			if (s[i] == 'r' && s[i + 1] == 'u')
			{
				l = i;
				break;
			}
			printf("%c", s[i]);
		}
		printf(".ru");
		if (l != len - 2)
		{
			printf("/");
			for (int i = l + 2; i < len; i++)
				printf("%c", s[i]); 		
		}
	}
	else
	{
		printf("ftp://");
		printf("%c", s[3]);
		for (int i = 4; i < len - 1; i++)
		{
			if (s[i] == 'r' && s[i + 1] == 'u')
			{
				l = i;
				break;
			}
			printf("%c", s[i]);
		}
		printf(".ru");
		if (l != len - 2)
		{
			printf("/");
			for (int i = l + 2; i < len; i++)
				printf("%c", s[i]); 		
		}
	}
	return 0;
}