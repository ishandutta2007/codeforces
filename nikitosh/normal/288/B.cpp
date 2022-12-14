#include<cstdio>

long long n, k, ans;

int main()
{
	scanf("%I64d%I64d", &n, &k);
	ans = 1;
	for (int i = 0; i < k - 1; i++)
	{
		ans = (ans * k) % 1000000007;
   	}
	for (int i = 0; i < n - k; i++)
	{
		ans = (ans * (n - k)) % 1000000007;
   	}
   	printf("%I64d\n", ans);
	return 0;
}