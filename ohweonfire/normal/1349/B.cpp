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

int n, k, a[maxn], p[maxn];

void solve()
{
	get2(n, k);
	for(int i=1; i<=n; i++) get1(a[i]);
	if(n == 1)
	{
		if(a[1] == k) puts("yes");
		else puts("no");
		return;
	}
	bool have = 0;
	for(int i=1; i<=n; i++) have |= (a[i] == k);
	if(!have)
	{
		puts("no");
		return;
	}
	
	int mn = inf;
	for(int i=1; i<=n; i++)
	{
		p[i] = p[i-1];
		if(a[i] >= k) p[i]++;
		if(i >= 2) mn = std::min(mn, p[i-2] * 2 - (i-2));
		if(p[i] * 2 - i > mn)
		{
			puts("yes");
			return;
		}
	}
	puts("no");
}

int main()
{
	int tc;
	get1(tc);
	while(tc--) solve();
	return 0;
}