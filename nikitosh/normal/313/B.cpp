#include<cstdio>
#include<cstring>

using namespace std;

int len, m, k, l, used[200000], sum[200000];
char s[200000];

int main()
{
	gets(s);
	len = strlen(s);
	for (int i = 0; i < len - 1; i++)
		if (s[i] == s[i + 1])
			used[i] = 1;
   	sum[1] = used[0];
   	for (int i = 2; i < len; i++)
   		sum[i] = sum[i - 1] + used[i - 1];
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &k, &l);
		printf("%d\n", sum[l - 1] - sum[k - 1]);
	}
	return 0;
}