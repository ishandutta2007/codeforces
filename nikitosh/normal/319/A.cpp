#include<cstdio>
#include<cstring>

using namespace std;

int two[20000], len, ans = 0;
char s[1000];

int main()
{
	two[0] = 1;
	for (int i = 1; i < 10000; i++)
		two[i] = (two[i - 1] * 2) % 1000000007;
	gets(s);
	len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		if (s[i] == '1')
			ans = (ans + two[2 * (len - i - 1) + i]) % 1000000007; 
	}
	printf("%d\n", ans);
	return 0;
}