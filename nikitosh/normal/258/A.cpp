#include<cstdio>
#include<cstring>

int len, boo, l;
char s[200000];

int main()
{
	gets(s);
	len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		if (s[i] == '0')
		{
			boo = 1;
			l = i;
			break;
		}
	}
	if (boo == 1)
	{
		for (int i = 0; i < len; i++)
			if (i != l)
				printf("%c", s[i]);
		return 0;
	}
	for (int i = 0; i < len - 1; i++)
		printf("1");
	return 0;
}