#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
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
const int MAXN = 600011;
struct edge{int v,nxt;}e[MAXN<<1|1];
int cnt=1,last[MAXN];
void adde(int u,int v){e[++cnt].v=v,e[cnt].nxt=last[u],last[u]=cnt;}

bool del[MAXN];
int dir[MAXN],stk[MAXN],top;
int delta[MAXN];
int deg[MAXN];
std::set<int>odd;
std::vector<int>g[MAXN],seq;
void dfs(int u)
{
	for(int &i=last[u];i;i=e[i].nxt)
	{
		int v=e[i].v,tp=i>>1;
		if(del[i>>1])continue;
		del[i>>1]=1;
		dfs(v);
		stk[++top]=tp;//,printf("Stk[%d]=%d\n",top,stk[top]);
	}
}
int main()
{
	int n=2e5,m=read();
	for(int i=1;i<=m;++i)
	{
		int x=read(),y=n+read();
		adde(x,y),adde(y,x);
		++deg[x],++deg[y];
	}
	for(int i=1;i<=n+n;++i)
		if(deg[i]&1)odd.insert(i);
	while(odd.size())
	{
		int x=*odd.begin();odd.erase(odd.begin());
		int &i=last[x];
		while(del[i>>1])i=e[i].nxt;
		seq.emplace_back(i>>1),del[i>>1]=1;
		int y=e[i].v;
		if(deg[y]&1)odd.erase(y);
		else odd.insert(y);
		--deg[x],--deg[y];
		i=e[i].nxt;
	}
	for(int u=1;u<=n+n;++u)dfs(u);
	//printf("top=%d\n",top);
	for(int i=1;i<=top;++i)
	{
		if(i&1)dir[stk[i]]=1;//,printf("%d -> %d\n",e[stk[i]<<1].v,e[stk[i]<<1|1].v);
		else dir[stk[i]]=2;//,printf("%d <- %d\n",e[stk[i]<<1|1].v,e[stk[i]<<1].v);
	}
	//printf("SEQ:\n");
	std::reverse(seq.begin(),seq.end());
	for(auto i:seq)
	{
		int x=e[i<<1].v,y=e[i<<1|1].v;
		if(delta[x]>0)--delta[x],++delta[y],dir[i]=1;
		else if(delta[x]==0)
		{
			if(delta[y]>0)++delta[x],--delta[y],dir[i]=2;
			else --delta[x],++delta[y],dir[i]=1;
		}
		else ++delta[x],--delta[y],dir[i]=2;
	}
	for(int i=1;i<=m;++i)putchar(dir[i]==1?'r':'b');
	puts("");
	return 0;
}