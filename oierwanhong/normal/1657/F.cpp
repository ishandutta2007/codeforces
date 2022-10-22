#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
typedef long long ll;
typedef unsigned un;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
ll read()
{
	ll f=1,x=0;int c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
ll abs(ll x){return x>0?x:-x;}
template<typename T> inline bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
template<typename T> inline bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
/**********/
const int MAXN = 1600011;
struct DSU
{
	int fa[MAXN];
	void init(int n){for(int i=1;i<=n;++i)fa[i]=i;}
	int find(int x)
	{
		if(fa[x]==x)return x;
		return fa[x]=find(fa[x]);
	}
	void uni(int x,int y){fa[find(x)]=find(y);}
	bool same(int x,int y){return find(x)==find(y);}
}dsu;
std::vector<int>T[MAXN];
std::vector<int>C[MAXN];
int fa[MAXN],dep[MAXN];
char s[MAXN];
int sp[MAXN];
void dfs(int u)
{
	for(auto v:T[u])
	{
		if(v==fa[u])continue;
		fa[v]=u,dep[v]=dep[u]+1, dfs(v);
	}
}
std::vector<int> get_chain(int u,int v)
{
	std::vector<int>C,R;
	while(dep[u]>dep[v])C.emplace_back(u),u=fa[u];
	while(dep[v]>dep[u])R.emplace_back(v),v=fa[v];
	while(u!=v)C.emplace_back(u),u=fa[u],R.emplace_back(v),v=fa[v];
	C.emplace_back(u);
	std::reverse(R.begin(),R.end());
	for(auto x:R)C.emplace_back(x);
	return C;
}
char state[MAXN][2];
void NO()
{
	puts("NO");
	exit(0);
}
const int K = 800000;
void link(int x,bool p,int y,bool q)
{
	//printf("X[%d]=%d <=> X[%d]=%d\n",x,p,y,q);
	dsu.uni(x+p*K,y+q*K);
	dsu.uni(x+(!p)*K,y+(!q)*K);
}

int res[MAXN];
int main()
{
	int n=read(),m=read();
	dsu.init(K+K);
	for(int i=1;i<n;++i){int u=read(),v=read();T[u].emplace_back(v),T[v].emplace_back(u);}
	dfs(1);
	for(int w=n+1;w<=n+m;++w)
	{
		int x=read(),y=read();
		int start=sp[w-1];
		scanf("%s",s+start);
		int len=strlen(s+start);
		sp[w]=start+len;
		C[w]=get_chain(x,y);
		for(int i=0;i<len;++i)
		{
			int u=C[w][i];
			char a=s[start+i],b=s[start+len-i-1];
			//f[u]=a or f[u]=b
			if(a==b)
			{
				if(state[u][0]==0)state[u][0]=state[u][1]=a;
				else if(state[u][0]!=a&&state[u][1]!=a)NO();
				else state[u][0]=state[u][1]=a;
			}
			else
			{
				if(state[u][0]==0)state[u][0]=a,state[u][1]=b;
				else
				{
					if(state[u][0]==a)
					{
						if(state[u][1]!=b)state[u][0]=state[u][1]=a;
					}
					else if(state[u][0]==b)
					{
						if(state[u][1]!=a)state[u][0]=state[u][1]=b;
					}
					else
					{
						if(state[u][1]==a)state[u][0]=state[u][1]=a;
						else if(state[u][1]==b)state[u][0]=state[u][1]=b;
						else NO();
					}
				}
			}
		}
	}
	for(int w=n+1;w<=n+m;++w)
	{
		int start=sp[w-1],len=sp[w]-sp[w-1];
		for(int i=0;i<len;++i)
		{
			int u=C[w][i];
			char a=s[start+i],b=s[start+len-i-1];
			if(a==b)continue;
			if(state[u][0]==state[u][1])
			{
				if(state[u][0]==a)link(u,0,w,0);
				else link(u,0,w,1);
			}
			else
			{
				if(state[u][0]==a)link(u,0,w,0);
				else link(u,0,w,1);
				if(state[u][1]==a)link(u,1,w,0);
				else link(u,1,w,1);
			}
		}
	}
	//for(int u=1;u<=n;++u)printf("u=%d,F[u]=%c or %c\n",u,state[u][0],state[u][1]);
	for(int u=1;u<=n+m;++u)
		if(dsu.same(u,u+K))NO();
	memset(res,-1,sizeof res);
	for(int u=1;u<=n;++u)
		if(state[u][0]==state[u][1])
		{
			int r=dsu.find(u),flag=0;
			if(r>K)r-=K,flag=1;
			if(res[r]!=-1&&res[r]!=flag)NO();
			res[r]=flag;
		}
	for(int u=1;u<=n;++u)
	{
		int r=dsu.find(u),rev=0;
		if(r>K)r-=K,rev=1;
		if(res[r]==-1)res[r]=rev;
		res[u]=res[r]^rev;
	}
	puts("YES");
	for(int u=1;u<=n;++u)putchar(state[u][0]? state[u][res[u]]:'a');
	puts("");
	return 0;
}