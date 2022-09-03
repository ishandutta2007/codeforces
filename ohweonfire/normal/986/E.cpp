// This amazing code is by Eric Sunli Chen.
#include<bits/stdc++.h>
using namespace std;
template<typename T> bool get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'&&t!=EOF; t=getchar());
	if(t=='-')neg=true,t=getchar();if(t==EOF)return false;
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;return true;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb emplace_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) (get1(a)&&get1(b))
#define get3(a,b,c) (get1(a)&&get2(b,c))
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

const int maxv=10000111;
const int maxn=100111;
const int mod=1e9+7;

int power(int x,int y){int ret=1;do{if(y&1)ret=1ll*ret*x%mod;x=1ll*x*x%mod;}while(y>>=1);return ret;}

vector<int>g[maxn];
int f[20][maxn],dfn[maxn],edfn[maxn],timer,dep[maxn];

void dfs(int x)
{
	dfn[x]=++timer;
	for(int i=1;i<20;i++)f[i][x]=f[i-1][f[i-1][x]];
	for(auto&v:g[x])if(v!=f[0][x])
	{
		f[0][v]=x;dep[v]=dep[x]+1;
		dfs(v);
	}
	edfn[x]=timer;
}
int getlca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	for(int i=19;i>=0;i--)if(dep[x]-dep[y]>>i)x=f[i][x];
	if(x==y)return x;
	for(int i=19;i>=0;i--)if(f[i][x]!=f[i][y])
	{
		x=f[i][x];
		y=f[i][y];
	}
	return f[0][x];
}

namespace BIT
{
	int bit[30][maxn],mark[30][maxn],timer;
	void add(int x,int y,int v)
	{
		for(;y<maxn;y+=y&-y)
		{
			if(mark[x][y]!=timer)
			{
				mark[x][y]=timer;
				bit[x][y]=0;
			}
			bit[x][y]+=v;
		}
	}
	int query(int x,int y)
	{
		int ret=0;
		for(;y;y-=y&-y)if(mark[x][y]==timer)ret+=bit[x][y];
		return ret;
	}
};

int n,q,tu[maxn],tv[maxn],ans[maxn];

int pr[maxv],id[maxv],pw[maxv],pre[maxv],tot,val[700111];
vector<pii>vs[700111],vq[700111];

int main()
{
	for(int i=2;i<maxv;i++)
	{
		if(!pr[i])pr[i]=i;
		
		if(pr[i]!=pr[i/pr[i]])
		{
			pre[i]=i/pr[i];
			pw[i]=1;
		}
		else
		{
			pre[i]=pre[i/pr[i]];
			pw[i]=pw[i/pr[i]]+1;
		}
		
		if(pr[i]!=i)continue;
		id[i]=++tot;val[tot]=i;
		if(1ll*i*i>=maxv)continue;
		for(int j=i*i;j<maxv;j+=i)
			if(!pr[j])pr[j]=i;
	}
	
	get1(n);
	for(int i=1,u,v;i<n;i++)
	{
		get2(u,v);
		g[u].pb(v);g[v].pb(u);
	}
	dfs(1);
	for(int i=1,x;i<=n;i++)
	{
		get1(x);
		while(x!=1)
		{
			vs[id[pr[x]]].pb(mp(pw[x],i));
			x=pre[x];
		}
	}
	
	get1(q);
	for(int i=1,u,v,w;i<=q;i++)
	{
		get3(u,v,w);if(dfn[u]>dfn[v])swap(u,v);
		tu[i]=u;tv[i]=v;ans[i]=1;
		while(w!=1)
		{
			vq[id[pr[w]]].pb(mp(pw[w],i));
			w=pre[w];
		}
	}
	
	for(int _=1;_<=tot;_++)
	{
		if((int)vs[_].size()==0||(int)vq[_].size()==0)continue;
		BIT::timer++;
		for(auto&v:vs[_])
		{
			BIT::add(v.ff,dfn[v.ss],1);
			BIT::add(v.ff,edfn[v.ss]+1,-1);
		}
		puts("");
		for(auto&v:vq[_])
		{
			int i=v.ss,sum=0,cur=0,lca=getlca(tu[i],tv[i]);
			for(int j=1;j<30;j++)
			{
				cur=BIT::query(j,dfn[tv[i]])-BIT::query(j,dfn[f[0][lca]]);
				if(lca!=tu[i])cur+=BIT::query(j,dfn[tu[i]])-BIT::query(j,dfn[lca]);
				sum+=min(j,v.ff)*cur;
			}
			if(sum<0)continue;
			ans[i]=1ll*ans[i]*power(val[_],sum)%mod;
		}
	}
	
	for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
	
	return 0;
}