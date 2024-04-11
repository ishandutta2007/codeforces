#include<cstdio>
#include<cstring>

using namespace std;

char s[100005], s2[100005], t1[105], t2[105];
int n, len1, len2, boo, boo2, a1 = 0, a2 = 0, l1, l2;

int main()
{
	gets(s);
	gets(t1);
	gets(t2);
	n = strlen(s);
	len1 = strlen(t1);
	len2 = strlen(t2);
	l1 = n;
	l2 = 0;
	for (int i = 0; i <= n - len1; i++)
	{
		boo = 0;
		for (int j = 0; j < len1; j++)
			if (s[i + j] != t1[j])
			{
				boo = 1;
				break;
			}
		if (boo == 0)
		{
			l1 = i;
			break;
		}
	}
	for (int i = 0; i <= n - len2; i++)
	{
		boo = 0;
		for (int j = 0; j < len2; j++)
			if (s[i + j] != t2[j])
			{
				boo = 1;
				break;
			}
		if (boo == 0)
			l2 = i;
	}
	//printf("%d %d\n", l1, l2);
	if (l1 + len1 <= l2)
		a1 = 1;
	for (int i = 0 ; i < n; i++)
		s2[i] = s[n - i - 1];
	l1 = n;
	l2 = 0;
	for (int i = 0; i <= n - len1; i++)
	{
		boo = 0;
		for (int j = 0; j < len1; j++)
			if (s2[i + j] != t1[j])
			{
				boo = 1;
				break;
			}
		if (boo == 0)
		{
			l1 = i;
			break;
		}
	}
	for (int i = 0; i <= n - len2; i++)
	{
		boo = 0;
		for (int j = 0; j < len2; j++)
			if (s2[i + j] != t2[j])
			{
				boo = 1;
				break;
			}
		if (boo == 0)
			l2 = i;
	}
	if (l1 + len1 <= l2)
		a2 = 1;
	if (a1 * a2 == 1)
	{
		puts("both");
		return 0;
	}
	if (a1 == 1)
	{
		puts("forward");
		return 0;
	}
	if (a2 == 1)
	{
		puts("backward");
		return 0;
	}
	puts("fantasy");
	return 0;
}