#include<cstdio>
#include<cstring>

int N, ans = 0, len;
char s[10];

int main()
{
	scanf("%d\n", &N);
	for (int i = 0; i < N; i++)
	{
		gets(s);
		len = strlen(s);
		for (int j = 0; j < len; j++)
		{
			if (s[j] == '+')
				ans++;
			if(s[j] == '-')
				ans--;
		}
	}
	printf("%d\n", ans / 2);
	return 0;
}