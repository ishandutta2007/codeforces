#include<bits/stdc++.h>
#define int long long
#define MAXN 1145141919180
using namespace std;

const int M=3*1e5+10;
int f[M],n,k,a[M];

struct node{int to,next;}e[M*2];
int cnt,head[M];
void add(int u,int to)
{e[++cnt].to=to,e[cnt].next=head[u],head[u]=cnt;}

int dfs(int u,int fa)
{
	if (a[u]==1)f[u]=MAXN;
	int sum=0;
	for (int i=head[u];i;i=e[i].next)
		if (fa!=e[i].to)
		{
			sum++;
			dfs(e[i].to,u);
			if (a[u]==1)f[u]=min(f[u],f[e[i].to]);
			else f[u]+=f[e[i].to];
		}
	if (sum==0)k++,f[u]=1;
}

signed main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=2;i<=n;i++)
	{
		int a;
		cin>>a;
		add(a,i),add(i,a);
	}
	dfs(1,-1);
	cout<<k-f[1]+1;
	return 0;
}