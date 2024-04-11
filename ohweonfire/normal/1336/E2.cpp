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

const int maxn = 100111;
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

inline void add(int &x, int y) { x += y; if(x >= mod) x -= mod; }
int n, m, tot, coef;
LL a[111], b[111];

int cnt[111], ans[111];
void work()
{
	LL now = 0; cnt[0] = 1;
	for(int i=1; i<(1<<tot); i++)
	{
		now ^= a[__builtin_ctz(i)];
		cnt[__builtin_popcountll(now)]++;
	}
}

int main()
{
	get2(n, m);
	coef = 1;
	while(n--)
	{
		LL x; get1(x);
		for(int i=0; i<tot; i++) if(a[i] & -a[i] & x) x ^= a[i];
		if(!x)
		{
			add(coef, coef);
			continue;
		}
		for(int i=0; i<tot; i++) if(a[i] & x & -x) a[i] ^= x;
		a[tot++] = x;
	}
	
	if(tot <= m / 2)
	{
		work();
		for(int i=0; i<=m; i++) ans[i] = 1ll * cnt[i] * coef % mod;
	}
	else
	{
		static int seq[111], have[111], c[111][111], ntot;
		for(int i=0; i<=m; i++)
		{
			c[i][0] = 1;
			for(int j=1; j<=m; j++) c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
		}
		for(int i=0; i<tot; i++) have[__builtin_ctzll(a[i])] = 1;
		for(int i=0; i<m; i++) if(!have[i])
		{
			seq[ntot++] = i;
			if(coef & 1) coef += mod;
			coef >>= 1;
		}
		for(int i=0; i<ntot; i++)
		{
			b[i] = 1ll << m - i;
			for(int j=0; j<tot; j++) if((a[j] >> seq[i]) & 1) b[i] |= 1ll << j;
		}
		tot = ntot; memcpy(a, b, sizeof(a));
		
		work();
		for(int i=0; i<=m; i++)
		{
			for(int j=0; j<=m; j++)
			{
				int sum = 0;
				for(int k=0; k<=j; k++)
				{
					int now = 1ll * c[j][k] * c[m-j][i-k] % mod;
					if(k % 2 == 0) add(sum, now);
					else add(sum, mod - now);
				}
				add(ans[i], 1ll * sum * cnt[j] % mod);
			}
			ans[i] = 1ll * ans[i] * coef % mod;
		}
	}
	for(int i=0; i<=m; i++) printf("%d%c", ans[i], i==m ? '\n':' ');
	return 0;
}