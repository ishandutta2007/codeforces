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
LL calc(int i, int j, int k, int *a, int *b, int *c)
{
	return 1ll * (a[i] - b[j]) * (a[i] - b[j]) + 1ll * (b[j] - c[k]) * (b[j] - c[k]) + 1ll * (c[k] - a[i]) * (c[k] - a[i]);
}
LL ans;
void work(int n, int m, int k, int a[maxn], int b[maxn], int c[maxn])
{
	for(int i=1; i<=n; i++)
	{
		if(a[i] >= b[1] && a[i] <= c[k])
		{
			int j = std::upper_bound(b+1, b+m+1, a[i]) - b - 1;
			int q = std::lower_bound(c+1, c+k+1, a[i]) - c;
			ans = std::min(ans, calc(i, j, q, a, b, c));
		}
		if(a[i] >= c[1] && a[i] <= b[m])
		{
			int q = std::upper_bound(c+1, c+k+1, a[i]) - c - 1;
			int j = std::lower_bound(b+1, b+m+1, a[i]) - b;
			ans = std::min(ans, calc(i, j, q, a, b, c));
		}
	}
}

int n, m, k, a[maxn], b[maxn], c[maxn];
void solve()
{
	get3(n, m, k);
	for(int i=1; i<=n; i++) get1(a[i]);
	for(int i=1; i<=m; i++) get1(b[i]);
	for(int i=1; i<=k; i++) get1(c[i]);
	std::sort(a+1, a+n+1);
	std::sort(b+1, b+m+1);
	std::sort(c+1, c+k+1);
	ans = calc(1, 1, 1, a, b, c);
	work(n, m, k, a, b, c);
	work(m, k, n, b, c, a);
	work(k, n, m, c, a, b);
	printendl(ans);
}

int main()
{
	int tc;
	get1(tc);
	while(tc--) solve();
	return 0;
}