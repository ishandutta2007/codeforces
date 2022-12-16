#include <cstdio>

using namespace std;

long long N;
long long Dp[1100000] = {0};

int main ()
{
	scanf ("%I64d", &N);
	for (long long i = 0; i < N; i++)
	{
		long long a;
		scanf ("%I64d", &a);
		Dp[a]++;
	}
	long long ans = 0;
	for (long long i = 0; i < 1000100; i++)
	{
		Dp[i + 1] += Dp[i] / 2;
		ans += Dp[i] % 2;
	}
	printf ("%I64d\n", ans);
}