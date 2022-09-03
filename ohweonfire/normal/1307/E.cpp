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

const int maxn=5111;
const int mod=1e9+7;
int qpow(int x, int y)
{
	int ret = 1;
	while(y)
	{
		if(y&1) ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;
		y>>=1;
	}
	return ret;
}

int n,m,s[maxn],f[maxn],h[maxn], lv[maxn], rv[maxn];

int ans, ways;
void update(int k1, int k2)
{
	if(ans < k1)
	{
		ans = k1;
		ways = k2;
	}
	else if(ans == k1)
	{
		ways += k2;
		if(ways >= mod) ways -= mod;
	}
}

int main()
{
	get2(n,m);
	for(int i=1;i<=n;i++)get1(s[i]);
	for(int i=1;i<=m;i++)get2(f[i],h[i]);
	
	for(int i=1; i<=m; i++)
	{
		int tmp = h[i];
		for(int j=1; j<=n; j++)
		{
			if(s[j] == f[i]) tmp--;
			if(tmp == 0)
			{
				lv[i] = j;
				break;
			}
		}
		if(tmp) lv[i] = rv[i] = -1;
		tmp = h[i];
		for(int j=n; j>=1; j--)
		{
			if(s[j] == f[i]) tmp--;
			if(tmp == 0)
			{
				rv[i] = j;
				break;
			}
		}
	}
	ans = -inf;
	//have something on left
	int cl[maxn], cr[maxn], cc[maxn];
	for(int fir=1; fir<=m; fir++) if(lv[fir] != -1)
	{
		for(int i=1; i<=n; i++) cl[i] = cr[i] = cc[i] = 0;
		for(int i=1; i<=m; i++) if(i != fir && lv[i] != -1)
		{
			int num = 0;
			if(f[i] != f[fir] && lv[i] <= lv[fir])
			{
				cl[f[i]]++;
				num++;
			}
			if(rv[i] > lv[fir])
			{
				cr[f[i]]++;
				num++;
			}
			if(num == 2) cc[f[i]]++;
		}
		int ans = 1, ways = 1;
		for(int i=1; i<=n; i++)
		{
			int c1 = cl[i] + cr[i], c2 = cl[i] * cr[i] - cc[i];
			if(!c1) continue;
			if(c2)
			{
				ans += 2;
				ways = 1ll * ways * c2 % mod;
			}
			else if(c1)
			{
				ans++;
				ways = 1ll * ways * c1 % mod;
			}
		}
		update(ans, ways);
	}
	// no left
	for(int i=1; i<=n; i++) cl[i] = cr[i] = cc[i] = 0;
	for(int i=1; i<=m; i++) if(lv[i] != -1) cc[f[i]]++;
	int k1 = 0, k2 = 1;
	for(int i=1; i<=n; i++) if(cc[i])
	{
		k1++;
		k2 = 1ll * k2 * cc[i] % mod;
	}
	update(k1, k2);
	printf("%d %d\n", ans, ways);
	return 0;
}