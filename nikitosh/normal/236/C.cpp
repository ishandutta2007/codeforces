#include<cstdio>
#include<algorithm>

using namespace std;

long long l, ans, max1 = (long long) -1;
int N;    

long long gcd (long long a, long long b) 
{
	if (b == 0)
		return a;
	else
		return gcd (b, a % b);
}
int main()
{
	scanf("%d", &N);
	if (N == 1)
	{
		printf("%d\n", 1);
		return 0;
	} 
	if (N == 2)
	{
		printf("%d\n", 2);
		return 0;
	}
	for (int i = N; i >= max(1, N - 100); i--)
		for (int j = N; j >= max(1, N - 100); j--)
			for (int g = N; g >= max (1, N - 100); g--)
			{
				l = (long long) i * (long long) j / gcd(i, j);
				ans = l * (long long) g / gcd(l , g);
				max1 = max(max1, ans);
			}
	printf("%I64d\n", max1);
	return 0;
}