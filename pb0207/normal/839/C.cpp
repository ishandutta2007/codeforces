#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=1e5+1e3+7;

struct node{
	int ne,to,w;
}edg[N*2+1];

int n,cnt,head[N],dep[N],sz[N];

double v[N],ans;

void build(int u,int v)
{
	++cnt;
	edg[cnt].to=v;
	edg[cnt].ne=head[u];
	head[u]=cnt;
}

void dfs(int i,int f)
{
	for(int tmp=head[i];tmp;tmp=edg[tmp].ne)
	{
		int vv=edg[tmp].to;
		if(vv==f)
			continue;
		dep[vv]=dep[i]+1;
		sz[i]++;
		dfs(vv,i);
	}
}

void calc(int i,int f)
{
	int flag=false;
	for(int tmp=head[i];tmp;tmp=edg[tmp].ne)
	{
		int vv=edg[tmp].to;
		if(vv==f)
			continue;
		flag=true;
		v[vv]=1.0/sz[i]*v[i];
		calc(vv,i);
	}
	if(!flag)
		ans+=(double)dep[i]*v[i];
}

int main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		build(u,v);
		build(v,u);
	}
	dfs(1,0);
	v[1]=1.0;
	calc(1,0);
	printf("%.10lf",ans);
}