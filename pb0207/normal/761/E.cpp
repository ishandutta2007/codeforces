#include<cstdio>
#include<map>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

const long long N=31;

struct node{
	long long ne,to;
}edg[N*2+1];

long long n,head[N],cnt,deg[N],vis[N][5];

pair<long long,long long>ans[N];

int dx[5]={0,1,0,-1},dy[5]={1,0,-1,0};

void build(long long u,long long v)
{
	++cnt;
	edg[cnt].ne=head[u];
	edg[cnt].to=v;
	head[u]=cnt;
}

void dfs(long long i,long long fa,long long len,long long nowx,long long nowy,int ld)
{
	if(i!=1)
		vis[i][ld]=true;	
	ans[i].first=nowx,ans[i].second=nowy;
	for(long long tmp=head[i];tmp;tmp=edg[tmp].ne)
	{
		long long v=edg[tmp].to;
		if(v==fa)
			continue;
		for(int j=0;j<4;j++)
			if(!vis[i][j])
			{
				vis[i][j]=true;
				dfs(v,i,len>>1,nowx+len*dx[j],nowy+len*dy[j],(j+2)%4);
				break;
			}
	}
}

int main()
{
	cin>>n;
	for(long long i=1;i<n;i++)
	{
		long long u,v;
		cin>>u>>v;
		deg[u]++;
		deg[v]++;
		build(u,v);
		build(v,u);
	}
	for(long long i=1;i<=n;i++)
		if(deg[i]>4)
		{
			cout<<"NO";
			return 0;
		}
	dfs(1,0,1ll<<(51),0,0,0);
	cout<<"YES"<<endl;
	for(long long i=1;i<=n;i++)
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
}