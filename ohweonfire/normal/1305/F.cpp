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

using namespace std;

const int maxn = 1000111;
int n, ord[maxn];
LL a[maxn], ans;

bool isp[maxn];
int pr[maxn], tot;

void checkp(LL p)
{
	static set<LL> have;
	if(have.count(p))return;
	LL sum = 0;
	for(int i=1; i<=n; i++)
	{
		if(a[i] <= p) sum += p-a[i];
		else sum += min(a[i] % p, p - a[i] % p);
	}
	ans = min(ans, sum);
}
void checkv(LL x)
{
	if(!x) return;
	for(int i=1; i<=tot && 1ll*pr[i]*pr[i] <= x; i++)if(x % pr[i] == 0)
	{
		checkp(pr[i]);
		while(x % pr[i] == 0) x /= pr[i];
	}
	if(x > 1) checkp(x);
}
void check(int p)
{
	checkv(a[p]);
	checkv(a[p]+1);
	checkv(a[p]-1);
}

int main()
{
	for(int i=2; i<maxn; i++) isp[i] = 1;
	for(int i=2; i<maxn; i++) if(isp[i])
	{
		pr[++tot] = i;
		for(int j=i+i;j<maxn; j+=i) isp[j] = 0;
	}
	get1(n);
	for(int i=1; i<=n; i++) get1(a[i]);
	mt19937 rng(chrono::high_resolution_clock().now().time_since_epoch().count());
	for(int i=1; i<=n; i++) ord[i] = i;
	shuffle(ord+1, ord+n+1, rng);
	ans = n;
	for(int i=1; i<=n; i++)
	{
		if(1.0*clock()/CLOCKS_PER_SEC > 2.1) break;
		check(ord[i]);
	}
	printf("%lld\n", ans);
	return 0;
}