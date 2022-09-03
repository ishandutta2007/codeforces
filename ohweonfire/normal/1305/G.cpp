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

const int maxn = 300111;
int n, a[maxn], f[maxn];
int gf(int x){return x==f[x]?x:f[x]=gf(f[x]);}

int cnt[maxn];
LL ans;
void unite(int x, int y)
{
	if(gf(x) == gf(y)) return;
	ans += 1ll * (x+y) * (cnt[x] + cnt[y] - 1);
	f[f[x]] = f[y];
	cnt[x] = cnt[y] = 1;
}

int main()
{
	get1(n);
	for(int i=1; i<=n; i++) get1(a[i]);
	a[++n] = 0;
	
	for(int i=1; i<=n; i++)
	{
		cnt[a[i]]++;
		ans -= a[i];
	}
	for(int i=0; i<(1<<18); i++) f[i] = i;
	for(int i=(1<<18)-1; i>=0; i--) for(int j=i;;j=(j-1)&i)
	{
		if(cnt[j] && cnt[i^j]) unite(j, i^j);
		if(j==0) break;
	}
	printendl(ans);
	return 0;
}