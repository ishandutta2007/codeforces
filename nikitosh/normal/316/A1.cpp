#include<cstdio>
#include<cstring>

using namespace std;

char s[200005];
int len, used[100], cnt = 0;
long long ans = 1;

int main()
{
	gets(s);
	len = strlen(s);
	if (s[0] == '?' || (s[0] >= 'A' && s[0] <= 'J'))
	{
		ans *= 9;
		if (s[0] != '?')
		{
			used[s[0] - 'A'] = 1;
			cnt++;
		}
	}
	for (int i = 1; i < len; i++)
	{
		if (s[i] == '?')
			ans *= 10;
		if (s[i] >= 'A' && s[i] <= 'J')
		{
			if (used[s[i] - 'A'] == 0)
			{
				ans *= (long long) (10 - cnt);
				used[s[i] - 'A'] = 1;
				cnt++;
			}
		}
	}
	printf("%I64d\n", ans);
	return 0;
}