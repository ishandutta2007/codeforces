#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<set>
using namespace std;

const int N=1e5+1e3+7;

struct node{
	int ne,to;
}edg[N*2+1];

int n,head[N],cnt,col[N],flag;

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
		int v=edg[tmp].to;
		if(v==f)
			continue;
		dfs(v,i);
		if(col[v]!=col[i]&&f!=0)
			flag=false;
	}
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
	for(int i=1;i<=n;i++)
		cin>>col[i];
	for(int i=1;i<=n;i++)
		for(int tmp=head[i];tmp;tmp=edg[tmp].ne)
		{
			int v=edg[tmp].to;
			if(col[i]!=col[v])
			{
				flag=true;
				dfs(i,0);
				if(flag)
				{
					cout<<"YES"<<endl<<i;
					return 0;
				}
				flag=true;
				dfs(v,0);
				if(flag)
				{
					cout<<"YES"<<endl<<v;
					return 0;
				}
				cout<<"NO";
				return 0;
			}
		}
	cout<<"YES"<<endl<<1;
}