#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<bitset>
typedef long long ll;
typedef std::pair<int,int> pii;
int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll min(ll a,ll b){return a<b?a:b;}
ll max(ll a,ll b){return a>b?a:b;}
template<typename T> bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T> bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}
/**********/
const int MAXN = 1011;
typedef std::bitset<MAXN> bits;
bits a[MAXN],res[MAXN],st[MAXN];
int cap[MAXN][MAXN],sz[MAXN],T;
bool used[MAXN],vis[MAXN];
int fa[MAXN],node[MAXN],dep[MAXN];
std::vector<int>leaves,rest,nxt;
void addedge(int u,int v){res[u][v]=res[v][u]=1;}
int main()
{
	int n=read();
	for(int i=1;i<=n;++i)
	{
		int l=read();
		sz[i]=l;
		while(l--)a[i][read()]=1;
	}
	for(int x=1;x<=n;++x)
		for(int y=x+1;y<=n;++y)cap[x][y]=(a[x]&a[y]).count(),cap[y][x]=cap[x][y];
	bool flag=0;
	for(int u=1;u<=n;++u)
	{
		int cnt=0,p=0;
		for(int v=1;v<=n;++v)
			if(sz[v]>sz[u]&&cap[u][v]==sz[u])
			{
				++cnt;
				if(!p||sz[v]<sz[p])p=v;
			}
		if(cnt==2)
		{
			flag=1;
			int p1=0,p2=0;
			for(int v=1;v<=n;++v)
				if(cap[u][v]==1)p1=v;
				else if(cap[u][v]==2)p2=v;
			//printf("u=%d,[%d,%d]\n",u,p1,p2);
			if(!p1)
			{
				bits cur=a[u]&a[p2],left=a[u]^cur;
				int s=0,t=0;
				for(int x=1;x<=n;++x)
					if(cur[x])
					{
						if(!s)s=x;
						else t=x;
					}
				printf("%d %d\n",s,t);
				for(int x=1;x<=n;++x)
					if(left[x])printf("%d %d\n",x,s);
				for(int x=1;x<=n;++x)
					if(!left[x]&&x!=s&&x!=t)printf("%d %d\n",x,t);
				return 0;
			}
		}
	}
	if(!flag)
	{
		for(int i=2;i<=n;++i)printf("1 %d\n",i);
		return 0;
	}
	for(int u=1;u<=n;++u)
	{
		int cnt=0,p=0;
		for(int v=1;v<=n;++v)
			if(sz[v]>sz[u]&&cap[u][v]==sz[u])
			{
				++cnt;
				if(!p||sz[v]<sz[p])p=v;
			}
		if(cnt==2)
		{
			int p1=0,p2=0;
			for(int v=1;v<=n;++v)
				if(cap[u][v]==1)p1=v;
				else if(cap[u][v]==2)p2=v;
			bits S2=a[u]&a[p2],S1=a[u]&a[p1],left=a[u]^S2;
			int s=0,t=0;
			for(int x=1;x<=n;++x)
				if(S1[x])t=x;
			for(int x=1;x<=n;++x)
				if(S2[x]&&x!=t)s=x;
			addedge(s,t);
			for(int x=1;x<=n;++x)
				if(left[x]&&!vis[x])
				{
					addedge(x,s),dep[x]=1,st[x]=a[u],vis[x]=1,used[u]=1;
					break;
				}
		}
		else if(cnt>2)
		{
			bits S1=a[u],left=a[u];
			for(int v=1;v<=n;++v)
				if(cap[u][v]==2)S1&=a[v],left&=~a[v];
			int s=0;
			for(int x=1;x<=n;++x)
				if(S1[x])
				{
					if(s)
					{
						fprintf(stderr,"ERR!");
						exit(-5);
					}
					s=x;
				}
			for(int x=1;x<=n;++x)
				if(left[x]&&!vis[x])
				{
					addedge(x,s),dep[x]=1,st[x]=a[u],vis[x]=1, used[u]=1;
					break;
				}
		}
	}
	T=1;
	for(int x=1;x<=n;++x)
		if(dep[x]==1)leaves.push_back(x);
		else if(!dep[x])rest.push_back(x);
	while(leaves.size())
	{
		++T;
		for(auto s:leaves)
			for(auto t:rest)
			{
				if(res[s][t])
				{
					int d=0;
					for(int x=1;x<=n;++x)
						if(st[s][x]&&x!=t&&(!dep[x]||dep[x]==T))
						{
							res[t][x]=res[x][t]=1;
							++d;
						}
					if(d==1)
					{
						dep[t]=T;
						if(!vis[t])
						{
							vis[t]=1;
							int mx=0,p=0;
							for(int u=1;u<=n;++u)
								if(!used[u])
								{
									int c=(st[s]&a[u]).count();
									if(c>mx||(c==mx&&sz[u]<sz[p]))mx=c,p=u;
								}
							used[p]=1,st[t]=a[p];
						}
					}
					break;
				}
			}
		leaves.clear(),rest.clear();
		for(int x=1;x<=n;++x)
			if(dep[x]==T)leaves.push_back(x);
			else if(!dep[x])rest.push_back(x);
	}
	for(int x=1;x<=n;++x)
		for(int y=x+1;y<=n;++y)
			if(res[x][y])printf("%d %d\n",x,y);
	return 0;
}