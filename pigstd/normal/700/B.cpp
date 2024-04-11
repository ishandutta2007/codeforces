#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=200010;
int num[M],d[M],n,k,ans;

struct node
{
	int to,next;
}e[M*2];int head[M],cnt;
void add(int u,int to)
{
	e[++cnt].to=to,e[cnt].next=head[u],head[u]=cnt;
}

void dfs(int u,int fa)
{
	d[u]=d[fa]+1;
	for (int i=head[u];i;i=e[i].next)
		if (e[i].to!=fa)
			dfs(e[i].to,u),num[u]+=num[e[i].to];
}

signed main()
{
	cin>>n>>k;
	for (int i=1;i<=k*2;i++)
	{
		int x;
		cin>>x;
		num[x]=1;
	}
	for (int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y),add(y,x);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
	{
    	for(int j=head[i];j;j=e[j].next)
		{
        	int to=e[j].to;
        	if(d[to]<d[i])
            	to=i;
            ans+=min(k*2-num[to],num[to]);
        }
    }
    cout<<ans/2;
    return 0;
}