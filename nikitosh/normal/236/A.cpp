#include<cstdio>
#include<cstring>

int len, ans = 0, a[100];
char s[1000];

int main()
{
	gets(s);
	len = strlen(s);
	for (int i = 0; i < len; i++)
		a[s[i] - 'a'] = 1;
	for (int i = 0; i < 30; i++)
		if (a[i] != 0)
			ans++;
	if (ans % 2 == 0)
		printf("CHAT WITH HER!\n");
	else
		printf("IGNORE HIM!\n");
	return 0;
}