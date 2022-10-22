#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
typedef unsigned un;
typedef long long ll;
typedef std::pair<int,int> pii;
ll read(){ll x=0;bool f=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f?-x:x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template<typename T> inline bool umin(T& a,T b){if(b<a)return a=b,1;return 0;}
template<typename T> inline bool umax(T& a,T b){if(b>a)return a=b,1;return 0;}
/**********/
const int MAXN = 400011;
std::vector<int>g[MAXN];
std::vector<int>seq[2];
void dfs(int u,int fa,int type)
{
	seq[type].emplace_back(u);
	for(auto v:g[u])
		if(v!=fa)dfs(v,u,!type);
}
int res[MAXN];
bool used[MAXN];
int main()
{
	int task=read();
	while(task--)
	{
		seq[0].clear(),seq[1].clear();
		int n=read();
		for(int i=1;i<=n;++i)g[i].clear(),used[i]=0,res[i]=0;
		for(int i=1;i<n;++i){int u=read(),v=read();g[u].emplace_back(v),g[v].emplace_back(u);}
		dfs(1,0,0);
		int h=0,rest=0;
		while((1<<(h+1))<=n)++h;
		rest=n-(1<<h)+1;
		int m=seq[0].size(),it=0;
		if(m>=rest)
		{
			m-=rest;
			for(int st=(1<<h);st<=n;++st)
				res[seq[0][it]]=st,used[st]=1,++it;
		}
		for(int i=0;i<20;++i)
			if(m&(1<<i))
			{
				for(int st=1<<i;st<(1<<(i+1));++st)
					res[seq[0][it]]=st,used[st]=1, ++it;
			}
		it=0;
		for(int i=1;i<=n;++i)
			if(!used[i])res[seq[1][it]]=i,++it;
		for(int i=1;i<=n;++i)printf("%d ",res[i]);
		puts("");
		for(int i=1;i<=n;++i)g[i].clear(),res[i]=used[i]=0;
	}
	return 0;
}