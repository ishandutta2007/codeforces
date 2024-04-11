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

const int maxn = 2200111;

int h, g, n, a[maxn], can[maxn], mx[maxn], pos[maxn];

void recalc(int x)
{
	if(a[x*2] == 0 && a[x*2+1] == 0) can[x] = ((x>>g) > 0);
	else if(a[x*2] > a[x*2+1]) can[x] = can[x*2];
	else can[x] = can[x*2+1];
	if(can[x]) mx[x] = a[x];
	else mx[x] = std::max(mx[x*2], mx[x*2+1]);
}

void del(int x)
{
	if(a[x*2] == 0 && a[x*2+1] == 0)
	{
		can[x] = mx[x] = pos[a[x]] = 0;
		a[x] = 0;
		return;
	}
	if(a[x*2] > a[x*2+1])
	{
		std::swap(a[x], a[x*2]);
		std::swap(pos[a[x]], pos[a[x*2]]);
		del(x*2);
	}
	else
	{
		std::swap(a[x], a[x*2+1]);
		std::swap(pos[a[x]], pos[a[x*2+1]]);
		del(x*2+1);
	}
	recalc(x);
}

void solve()
{
	get2(h, g); n = (1<<h) - 1;
	for(int i=1; i<=n; i++)
	{
		get1(a[i]);
		pos[a[i]] = i;
	}
	for(int i=n+1; i<=n+n+1; i++) a[i] = mx[i] = can[i] = 0;
	for(int i=n; i>=1; i--) recalc(i);
	std::vector<int> op;
	while(mx[1])
	{
		int cur = pos[mx[1]];
		op.pb(cur);
		del(cur);
		while(cur > 1)
		{
			cur /= 2;
			recalc(cur);
		}
	}
	LL sum = 0;
	for(int i=1; i<(1<<g); i++) sum += a[i];
	printendl(sum);
	for(int i=0; i<op.size(); i++) printf("%d%c", op[i], i==(int)op.size()-1 ? '\n':' ');
	for(int i=1; i<=n; i++) pos[a[i]] = 0;
}

int main()
{
	int tc;
	get1(tc);
	while(tc--) solve();
	return 0;
}