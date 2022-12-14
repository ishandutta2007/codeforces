#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char s[1000005];
int len, ans, max1 = -1, d[1000005];

int main()
{
	gets(s);
	len = strlen(s);
	s[len] = '(';
	for (int i = len - 1; i >= 0; i--)
	{
		if (s[i] == ')')
			d[i] = 0;
		if (s[i] == '(')
		{
			if (s[i + 1] == ')')
				d[i] = d[i + 2] + 2;
			if (s[i + 1] == '(')
			{
            	if (s[i + 1 + d[i + 1]] == '(')
            		d[i] = 0;
            	else
            		d[i] = d[i + 1] + 2 + d[i + 1 + d[i + 1] + 1];
            }
		}
	}
	for (int i = 0; i < len; i++)
		max1 = max(max1, d[i]);
	for (int i = 0; i < len; i++)
		if (d[i] == max1)
			ans++;
   	if (max1 == 0)
   		printf("0 1\n");
   	else
   		printf("%d %d\n", max1, ans);
	return 0;
}