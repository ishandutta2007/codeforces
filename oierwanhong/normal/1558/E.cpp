#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
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
const int MAXN = 200011;
std::vector<int>g[MAXN];
bool used[MAXN];
int a[MAXN],b[MAXN];
int pre[MAXN],Q[MAXN],cur[MAXN],maxA;
int Expand(int u,int v)//s-> u, t-> v
{
	int all=cur[u];
	while(!used[u])used[u]=1,u=pre[u];
	while(!used[v])used[v]=1,all=min(maxA,all+b[v]),v=pre[v];
	return all;
}
int main()
{
	int task=read();
	while(task--)
	{
		int n=read(),m=read();
		maxA=0;
		for(int i=1;i<=n;++i)g[i].clear();
		for(int i=2;i<=n;++i)a[i]=read(),umax(maxA,a[i]+1);
		for(int i=2;i<=n;++i)b[i]=read();
		while(m--){int u=read(),v=read();g[u].push_back(v),g[v].push_back(u);}
		int l=0,r=maxA;
		while(l<r)
		{
			int mid=(l+r)>>1,all=mid,rest=n-1;
			for(int i=2;i<=n;++i)used[i]=0;
			used[1]=1;
			cur[1]=mid;
			while(rest)
			{
				int h=0,t=0,flag=0;
				for(int i=1;i<=n;++i)
					if(used[i])Q[t++]=i,pre[i]=-1,cur[i]=all;
					else pre[i]=0;
				while(h<t&&!flag)
				{
					int u=Q[h++];
					for(auto v:g[u])
						if(cur[u]>a[v]&&v!=pre[u])
						{
							if(!pre[v])pre[v]=u,cur[v]=min(maxA,cur[u]+b[v]),Q[t++]=v;
							else if(pre[u]!=-1&&pre[v])
							{
								all=Expand(u,v);flag=1;break;
							}
						}
				}
				if(!flag)break;
				rest=0;
				for(int i=1;i<=n;++i)
					if(!used[i])++rest;
			}
			if(rest)l=mid+1;
			else r=mid;
		}
		printf("%d\n",l);
	}
	return 0;
}