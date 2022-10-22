#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=1e5+10;
int sum[M],n,x,ans,out[M],f[M];

struct node{int next,to;}e[M<<1];int head[M],cnt;
void add(int u,int to){e[++cnt].to=to,e[cnt].next=head[u],head[u]=cnt;}

void dfs(int u,int fa)
{
	if (out[u]==1&&u!=x){f[u]=0;return;}
	priority_queue<int> q;
	for (int i=head[u];i;i=e[i].next)
		if (e[i].to!=fa&&sum[e[i].to]!=0)
			sum[e[i].to]--,dfs(e[i].to,u),q.push(f[e[i].to]);
	while(sum[u]>=1&&!q.empty())
		f[u]+=2+q.top(),q.pop(),sum[u]--;
	for (int i=head[u];i;i=e[i].next)
		if (e[i].to!=fa)
			f[u]+=min(sum[u],sum[e[i].to])*2,sum[u]-=min(sum[u],sum[e[i].to]);
	return;
}

signed main()
{
//	freopen("tongue.in","r",stdin);
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>sum[i];
	for (int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y),add(y,x);out[x]++,out[y]++;
	}
	cin>>x;
	dfs(x,0);
	cout<<f[x];
//	for (int i=1;i<=n;i++)cout<<i<<' '<<f[i]<<"  ";
	return 0;
}