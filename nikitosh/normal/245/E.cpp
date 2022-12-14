#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int len, sum1 = 0, sum2 = 0, max1 = (int) - 1e9, ans = 0;
char s[1000];

int main()
{
	gets(s);
	len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		if (s[i] == '+')
		{
			if (sum2 > 0)
				sum2--;
			else
				ans++;
			sum1++;
		}
		else
		{
			if (sum1 > 0)
				sum1--;
			else
				ans++;
			sum2++;
		}	
	}	
	printf("%d\n", ans);
}