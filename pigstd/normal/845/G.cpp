#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=2*1e5+10;
int jd[100],n,m,jl[M];
bool vis[M];

int head[M],cnt;
struct node
{
	int to,w,next;
}b[M];

int ws(int k)//k 
{
	int sum=0;
	while(k)
		sum++,k/=2;
	return sum;
}

void adde(int u,int to,int w)
{
	b[++cnt].w=w,b[cnt].to=to,b[cnt].next=head[u],head[u]=cnt;
}

void addj(int k)//k
{
	while(jd[ws(k)]!=0)
		k^=jd[ws(k)];
	jd[ws(k)]=k;
}

int findmin(int k)
{
	for (int i=90;i>=0;i--)
		k=min(k,k^jd[i]);
	return k;
}

void dfs(int k,int ans)
{
	vis[k]=1,jl[k]=ans;
	for (int i=head[k];i;i=b[i].next)
	{
		if (!vis[b[i].to])
			dfs(b[i].to,ans^b[i].w);
		else
			addj(jl[b[i].to]^(ans^b[i].w));
	}
}

signed main()
{
	scanf("%lld%lld",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		adde(a,b,c);
		adde(b,a,c);
	}
	dfs(1,0);
	cout<<findmin(jl[n]);
	return 0;
}