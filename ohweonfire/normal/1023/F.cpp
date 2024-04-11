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
#define pb push_back
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

int f[500111],tf[500111];
int gf(int x,int*f=::f){return x==f[x]?x:f[x]=gf(f[x],f);}

int n,m,k,eu[500111],ev[500111],ew[500111];

int head[500111],nxt[1000111],to[1000111],etot=1;
void addedge(int u,int v)
{
	nxt[++etot]=head[u];head[u]=etot;to[etot]=v;
	nxt[++etot]=head[v];head[v]=etot;to[etot]=u;
}
int fa[500111],fe[500111],dep[500111];
void dfs(int x)
{
	for(int i=head[x];i;i=nxt[i])if(to[i]!=fa[x])
	{
		fa[to[i]]=x;dep[to[i]]=dep[x]+1;fe[to[i]]=i>>1;
		dfs(to[i]);
	}
}

int merge(int u,int v)
{
	int ret=0,fu,fv;
	while(true)
	{
		fu=gf(u,tf);fv=gf(v,tf);
		if(fu==fv)return ret;
		if(dep[fu]>dep[fv])
		{
			u=tf[fu]=fa[fu];
			ret+=(fe[fu]<=k);
		}
		else
		{
			v=tf[fv]=fa[fv];
			ret+=(fe[fv]<=k);
		}
	}
}

int tot;LL ans;
bool tree[500111];

int main()
{
	get3(n,k,m);
	for(int i=1;i<=n;i++)f[i]=tf[i]=i;
	for(int i=1,u,v;i<=k;i++)
	{
		get2(u,v);
		addedge(u,v);
		f[gf(u)]=gf(v);
	}
	
	for(int i=1;i<=m;i++)
	{
		get3(eu[i],ev[i],ew[i]);
		if(gf(eu[i])==gf(ev[i]))continue;
		tree[i]=1;addedge(eu[i],ev[i]);
		f[gf(eu[i])]=gf(ev[i]);
	}
	for(int i=1;i<=n;i++)if(!fa[i])dfs(i);
	
	for(int i=1;i<=m;i++)if(!tree[i])
	{
		int e=merge(eu[i],ev[i]);
		ans+=1ll*ew[i]*e;
		tot+=e;
	}
	
	if(tot!=k)puts("-1");
	else printendl(ans);
	return 0;
}