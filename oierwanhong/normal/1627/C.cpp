#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
typedef long long ll;
ll read()
{
	ll f=1,x=0;int c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template<typename T> inline bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
template<typename T> inline bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
/**********/
const int MAXN = 1000011;
struct edge{int v,nxt;}e[MAXN<<1|1];
int cnt=1,last[MAXN],res[MAXN],deg[MAXN];
void adde(int u,int v){e[++cnt].v=v,++deg[v],e[cnt].nxt=last[u],last[u]=cnt;}
void dfs(int u,int fa=0,bool type=0)
{
	for(int i=last[u];i;i=e[i].nxt)
		if(e[i].v!=fa)
		{
			res[i>>1]= type?3:2;
			dfs(e[i].v,u,!type);
		}
}
int main()
{
	int task=read();
	while(task--)
	{
		cnt=1;
		int n=read();
		for(int i=1;i<=n;++i)last[i]=0,deg[i]=0;
		for(int i=1;i<n;++i){int u=read(),v=read();adde(u,v),adde(v,u);}
		bool fail=0;
		for(int i=1;i<=n;++i)
			if(deg[i]>2)fail=1;
		if(fail){puts("-1");continue;}
		for(int i=1;i<=n;++i)
			if(deg[i]==1)
			{
				dfs(i);break;
			}
		for(int i=1;i<n;++i)printf("%d ",res[i]);
		puts("");
	}
	return 0;
}