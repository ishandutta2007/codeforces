#include <bits/stdc++.h>

const int mod = 1e9 + 7;
const int N = 1e6 + 50;

int fact[N], inv[N];

inline int inc(int x, int y) { x += y - mod; return x + (x >> 31 & mod); }
inline int dec(int x, int y) { x -= y; return x + (x >> 31 & mod); }
inline int mul(int x, int y) { return 1ll * x * y % mod; }

inline int fastpow(int x, int p)
{
	int r = 1;
	while (p)
	{
		if (p & 1) r = mul(r, x);
		x = mul(x, x);
		p >>= 1;
	}
	return r;
}

inline void init(int n = 2e5)
{
	fact[0] = 1;
	for (int i = 1; i <= n; ++i) fact[i] = mul(i, fact[i - 1]);
	inv[n] = fastpow(fact[n], mod - 2);
	for (int i = n - 1; i >= 0; --i) inv[i] = mul(i + 1, inv[i + 1]);
}

inline int comb(int n, int m)
{
	if (n < m) return 0;
	return mul(mul(fact[n], inv[m]), inv[n - m]);
}

int main()
{
	init();
	int t;scanf("%d",&t);
	while (t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		if(n&1)
		{
			int w=1;
			for (int i=0;i<n;i+=2)
				w=inc(w,comb(n,i));
			printf("%d\n",fastpow(w,k));
		}
		else
		{
			int same=0;
			for (int i=0;i<n;i+=2)
				same=inc(same,comb(n,i));
			int total=fastpow(2,n);
			int ans=fastpow(same,k);
			for (int i=1;i<=k;++i)
			{
				int x=fastpow(same,i-1);
				int y=1;
				int z=fastpow(total,k-i);
				ans=inc(ans,mul(x,z));
			}
			printf("%d\n",ans);
		}

	}
	return 0;
}