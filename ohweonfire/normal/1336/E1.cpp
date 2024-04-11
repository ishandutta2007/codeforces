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

const int maxn = 200111;
const int mod = 998244353;
int qpow(int x, int y)
{
	int ret = 1;
	while(y)
	{
		if(y&1) ret = 1ll * ret * x % mod;
		x = 1ll * x * x % mod;
		y >>= 1;
	}
	return ret;
}
LL a[maxn], b[111];
int n, m, tot, ans[111], id[111], c[111], dp[55][1 << 17], ndp[55][1 << 17];
inline void add(int &x, int y) { x += y; if(x >= mod) x -= mod; }
int main()
{
	get2(n, m);
	for(int i=1; i<=n; i++)
	{
		get1(a[i]);
		for(int j=0; j<tot; j++) if(a[i] & b[j] & -b[j]) a[i] ^= b[j];
		if(!a[i]) continue;
		for(int j=0; j<tot; j++) if(a[i] & b[j] & -a[i]) b[j] ^= a[i];
		b[tot++] = a[i];
	}
	
	if(tot <= 18)
	{
		for(int i=0; i<(1<<tot); i++)
		{
			LL now = 0;
			for(int j=0; j<tot; j++) if((i >> j) & 1) now ^= b[j];
			ans[__builtin_popcountll(now)]++;
		}
	}
	else
	{
		for(int j=0; j<tot; j++)
		{
			int v = __builtin_ctzll(b[j]);
			id[v] = -1;
		}
		int cnt = 0;
		for(int j=0; j<m; j++) if(id[j] != -1) id[j] = cnt++;
		for(int j=0; j<tot; j++)
		{
			for(int k=0; k<m; k++) if(id[k] != -1 && ((b[j] >> k) & 1))
				c[j] |= 1 << id[k];
		}
		dp[0][0] = 1;
		for(int j=0; j<tot; j++)
		{
			memset(ndp, 0, sizeof(ndp));
			for(int k=0; k<=j; k++) for(int t=0; t<(1<<cnt); t++) ndp[k+1][t ^ c[j]] = dp[k][t];
			for(int k=0; k<=j+1; k++) for(int t=0; t<(1<<cnt); t++)
				add(dp[k][t], ndp[k][t]);
		}
		for(int i=0; i<=tot; i++) for(int j=0; j<(1<<cnt); j++) add(ans[i + __builtin_popcount(j)], dp[i][j]);
	}
	
	int coef = qpow(2, n - tot);
	for(int i=0; i<=m; i++)
	{
		ans[i] = 1ll * ans[i] * coef % mod;
		printf("%d ", ans[i]);
	}
	return 0;
}