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

const int maxn=300111;
int n,k,c[maxn],q1[maxn],q2[maxn];
std::vector<int> vs[maxn];

int f[maxn], ft[maxn], sz[maxn][2], mustv[maxn], ans;
int gf(int x)
{
	if(x==f[x])return x;
	gf(f[x]);
	ft[x] ^= ft[f[x]];
	return (f[x] = f[f[x]]);
}
int getval(int x)
{
	if(mustv[x]!=-1) return sz[x][mustv[x]];
	else return std::min(sz[x][0], sz[x][1]);
}
void link(int u, int v, int c)
{
	gf(u);gf(v);if(f[u]==f[v])return;
	ans -= getval(f[u])+getval(f[v]);
	c^=ft[u]^ft[v];u=f[u];v=f[v];
	sz[u][0] += sz[v][c];
	sz[u][1] += sz[v][c^1];
	if(mustv[v]!=-1 && mustv[u]==-1) mustv[u] = mustv[v]^c;
	f[v] = u;
	ft[v] = c;
	ans += getval(u);
}
void setmust(int u,int c)
{
	gf(u);
	ans -= getval(f[u]);
	c^=ft[u];u=f[u];
	if(mustv[u]==-1)mustv[u] = c;
	ans += getval(u);
}
char s[maxn];
int main()
{
	get2(n,k);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)c[i]=s[i]-'0';
	for(int i=1;i<=k;i++)
	{
		int sz,x;get1(sz);
		while(sz--)
		{
			get1(x);
			vs[i].pb(x);
			if(!q1[x])q1[x]=i;
			else q2[x]=i;
		}
	}
	for(int i=1;i<=k;i++)
	{
		f[i]=i;
		sz[i][1]=1;
		mustv[i]=-1;
	}
	for(int i=1;i<=n;i++)
	{
		if(q1[i] && q2[i]) link(q1[i], q2[i], c[i]^1);
		else setmust(q1[i], c[i]^1);
		printendl(ans);
	}
	return 0;
}