// This amazing code is by Eric Sunli Chen.
#include<bits/stdc++.h>
#include<vector>
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
typedef vector<int> vi;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

const int maxn=100111;

struct node
{
	int key,sz,ls,rs,dlt;
	node(){key=sz=ls=rs=dlt=0;}
	node(int key)
	{
		this->key=key;
		sz=1;ls=rs=dlt=0;
	}
	void add(int v){dlt+=v;key+=v;}
};
node a[maxn];
void pull(int o){a[o].sz=a[a[o].ls].sz+a[a[o].rs].sz+1;}
void push(int o)
{
	if(a[o].dlt)
	{
		if(a[o].ls)a[a[o].ls].add(a[o].dlt);
		if(a[o].rs)a[a[o].rs].add(a[o].dlt);
		a[o].dlt=0;
	}
}
int merge(int u,int v)
{
	if(!u||!v)return u|v;
	if(a[u].key>a[v].key)swap(u,v);
	push(u);
	a[u].rs=merge(a[u].rs,v);
	if(a[a[u].ls].sz<a[a[u].rs].sz)swap(a[u].ls,a[u].rs);
	pull(u);
	return u;
}
int pop(int x)
{
	push(x);
	return merge(a[x].ls,a[x].rs);
}

struct edge
{
	int u,v,w;
	edge(){u=v=w=0;}
	edge(int k1,int k2,int k3){u=k1;v=k2;w=k3;}
};
edge e[maxn];
int n,m,rt,f[maxn],ans_e[maxn],h[maxn];
LL ans;
inline int gf(int x){return x==f[x]?x:f[x]=gf(f[x]);}

int stk[maxn],top;
bool use[maxn],inst[maxn];

vector<int> g[maxn];
void set_e(int edge)
{
	ans+=a[edge].key;
	g[e[edge].v].pb(edge);
}

bool go(int x)
{
	stk[top=1]=x;
	while(true)
	{
		x=stk[top];
		while(h[x]&&gf(e[h[x]].v)==x)h[x]=pop(h[x]);
		if(!h[x])return false;
		int nxt=gf(e[h[x]].v);
		set_e(h[x]);
		a[h[x]].add(-a[h[x]].key);
		if(use[nxt])
		{
			while(top)use[stk[top--]]=1;
			return true;
		}
		if(!inst[nxt])
		{
			stk[++top]=nxt;
			inst[nxt]=1;
		}
		else
		{
			while(top&&stk[top]!=nxt)
			{
				f[gf(stk[top])]=gf(nxt);
				h[nxt]=merge(h[nxt],h[stk[top]]);
				top--;
			}
		}
	}
	return true;
}

void dfs(int x)
{
	use[x]=1;
	for(int i=0;i<(int)g[x].size();i++)
	{
		int edge=g[x][i];
		if(!use[e[edge].u])
		{
			ans_e[e[edge].u]=edge;
			dfs(e[edge].u);
		}
	}
}

bool Minimal_Arborescence(int rt)
{
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++)
	{
		a[i]=node(e[i].w);
		h[e[i].u]=merge(h[e[i].u],i);
	}
	use[rt]=1;
	for(int i=1;i<=n;i++)if(!use[i]&&!go(i))return false;
	return true;
}

int main()
{
#ifndef EEEEEericKKK
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	get2(n,m);rt=1;
	for(int i=1,u,v,w;i<=m;i++)
	{
		get3(u,v,w);swap(u,v);
		e[i]=edge(u,v,w);
		a[i]=node(w);
	}
	
	if(!Minimal_Arborescence(rt))
	{
		puts("-1");
		return 0;
	}
	printf("%lld\n",ans);
	memset(use,0,sizeof(use));dfs(1);
	for(int i=1;i<=n;i++)if(ans_e[i]&&e[ans_e[i]].w)printf("%d ",ans_e[i]);
	return 0;
}