#include<iostream>
#include<cstdio>
using namespace std;

typedef long long ll;

const int N=1e5+1e3+7;

int n,cnt,dep[N],head[N];

struct nd{
	int ne,to;
}edg[N*2+1];

void build(int u,int v)
{
	cnt++;
	edg[cnt].to=v;
	edg[cnt].ne=head[u];
	head[u]=cnt;
}

int dfs(int i,int fa)
{
	for(int tmp=head[i];tmp;tmp=edg[tmp].ne)
	{
		int v=edg[tmp].to;
		if(v==fa)
			continue;
		dep[v]=dep[i]+1;
		dfs(v,i);
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		build(u,v);
		build(v,u);
	}
	dep[1]=0;
	dfs(1,0);
	ll cnt1=0,cnt2=0;
	for(int i=1;i<=n;++i)
		if(dep[i]&1)
			cnt1++;
		else    
			cnt2++;
	cout<<(ll)cnt1*cnt2-((ll)n-1);
}