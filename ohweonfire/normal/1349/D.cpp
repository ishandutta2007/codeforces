#include <bits/stdc++.h>

namespace IO
{
char gc()
{
#ifdef FREAD
	static char buf[1<<21], *P1 = buf, *P2 = buf;
	if(P1 == P2)
	{
		P1 = buf;
		P2 = buf + fread(buf, 1, 1<<21, stdin);
		if(P1 == P2) return EOF;
	}
	return *(P1++);
#else
	return getchar();
#endif
}
template<typename Tp> bool get1(Tp &x)
{
	bool neg = 0;
	char c = gc();
	while( c != EOF && (c < '0' || c > '9') && c != '-' ) c = gc();
	if(c == '-') c = gc(), neg = 1;
	if(c == EOF) return false;
	x = 0;
	for(; c>='0' && c<='9'; c = gc()) x = x*10 + c - '0';
	if(neg) x = -x;
	return true;
}
template<typename Tp> void printendl(Tp x)
{
	if(x<0)putchar('-'),x=-x;
	static short a[40], sz;
	sz = 0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
	puts("");
}
} // namespace IO
using IO::get1;
using IO::printendl;
#define get2(x,y) get1(x) && get1(y)
#define get3(x,y,z) get2(x,y) && get1(z)
#define get4(x,y,z,w) get3(x,y,z) && get1(w)
#define pb push_back
#define mp std::make_pair
#define ff first
#define ss second
typedef long long LL;
typedef unsigned long long uLL;
typedef std::pair<int,int> pii;
const int inf = 0x3f3f3f3f;
const LL Linf = 1ll<<61;

const int mod = 998244353;
int qpow(int x, int y)
{
	int ret = 1;
	while(y)
	{
		if(y & 1) ret = 1ll * ret * x % mod;
		x = 1ll * x * x % mod;
		y >>= 1;
	}
	return ret;
}

const int maxn = 300111;

int n, a[maxn], m, dp[maxn];

int main()
{
	get1(n);
	for(int i=1; i<=n; i++)
	{
		get1(a[i]);
		m += a[i];
	}
	int last = 0, inv = qpow(1ll * m * (n - 1) % mod, mod - 2);
	for(int i=0; i<m; i++) // i to i + 1
	{
		LL A = m - i, B = 1ll * i * (n - 1);
		A = (A % mod) * inv % mod;
		B = (B % mod) * inv % mod;
		dp[i] = (B * last + 1) % mod * qpow(A, mod - 2) % mod;
		last = dp[i];
	}
	
	for(int i=m-1; i>=0; i--) dp[i] = (dp[i] + dp[i+1]) % mod;
	int ans = 0;
	for(int i=1; i<=n; i++)
	{
		ans += dp[a[i]];
		if(ans >= mod) ans -= mod;
	}
	ans = (ans + 1ll * (mod + 1 - n) * dp[0]) % mod;
	ans = 1ll * ans * qpow(n, mod - 2) % mod;
	printendl(ans);
	return 0;
}