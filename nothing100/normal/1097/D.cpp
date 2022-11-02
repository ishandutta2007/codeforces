#include <bits/stdc++.h>
using namespace std;

const int P = 1000000007;

long long n, p[21];
int K, q[21], Ans, cnt, ny[51];
int a[21], f[51][10001];

vector <int> sub;

int Pow(int a, int b)
{
	int ans = 1;
	for (; b; b >>= 1)
	{
		if (b & 1) ans = 1ll * ans * a % P;
		a = 1ll * a * a % P;
	}
	return ans;
}

int main()
{
//	freopen("1.in", "r", stdin);
	
	scanf("%lld%d", &n, &K);
	
	ny[0] = 1;
	for (int i = 1; i <= 50; ++ i) ny[i] = Pow(i, P - 2);


	for (long long i = 2; i <= n / i; ++ i)
		if (n % i == 0)
		{
			p[++ cnt] = i; q[cnt] = 0;
			while (n % i == 0)
			{
				++ q[cnt];
				n /= i;
			}
		}
	if (n != 1)
	{
		p[++ cnt] = n % P;
		q[cnt] = 1;
	}
	
	Ans = 1;
	for (int i = 1; i <= cnt; ++ i)
	{
		
		for (int j = 0; j <= q[i]; ++ j)
			for (int k = 0; k <= K; ++ k) f[j][k] = 0;
		
		for (int j = 0; j <= q[i]; ++ j)
			f[j][0] = Pow(p[i], j);
		for (int k = 1; k <= K; ++ k)
		{
			for (int j = 0; j <= q[i]; ++ j)
				for (int l = 0; l <= j; ++ l)
					f[j][k] = (f[j][k] + 1ll * ny[j + 1] * f[l][k - 1]) % P;
		}
		
//		printf("%d\n", f[q[i]][K]);
		
		Ans = 1ll * Ans * f[q[i]][K] % P;
	}
	printf("%d\n", Ans);
	return 0;
}