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
std::vector<int> g[maxn];
int n, m, k, a[maxn], d1[maxn], d2[maxn];
void bfs(int s,int*d)
{
	static int q[maxn];
	static bool use[maxn];
	int fr=0,rr=0;
	memset(use, 0, sizeof(use));
	q[rr++] = s;d[s] = 0;
	use[s] = 1;
	for(;fr<rr;fr++)
	{
		int x=q[fr];
		for(int i=0; i<(int)g[x].size(); i++) if(!use[g[x][i]])
		{
			d[g[x][i]] = d[x] + 1;
			use[g[x][i]] = 1;
			q[rr++] = g[x][i];
		}
	}
}

int main()
{
	get3(n,m,k);
	for(int i=1;i<=k;i++)get1(a[i]);
	for(int i=1,u,v;i<=m;i++)
	{
		get2(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}
	bfs(1,d1);
	bfs(n,d2);
	std::sort(a+1,a+k+1, [](int x,int y){return d1[x]+d2[y] < d1[y]+d2[x];});
	
	int ans = 0, cur = -inf;
	for(int i=1; i<=k; i++)
	{
		int x = a[i];
		ans = std::max(ans, d2[x] + cur + 1);
		cur = std::max(cur, d1[x]);
	}
	cur = -inf;
	for(int i=k; i>=1; i--)
	{
		int x = a[i];
		ans = std::max(ans, d1[x] + cur + 1);
		cur = std::max(cur, d2[x]);
	}
	
	ans = std::min(d1[n], ans);
	printendl(ans);
	return 0;
}