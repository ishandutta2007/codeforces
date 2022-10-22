#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define ins insert
#define del erase
#define WT int T=read();while(T--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=1e5+10;
int n,m,dp[M],x,vis[M],p[M],ans[M],fa[M],cntt,idx,que[M];
struct edge{int to,next;}e[M<<1];int cnt,head[M];
void add(int u,int to){e[++cnt].to=to,e[cnt].next=head[u],head[u]=cnt;}

int max(int a,int b){return a>b?a:b;}

void dfs(int u)
{
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].to;
		if(v==fa[u])continue;
		fa[v]=u;
		dfs(v);
	}que[++idx]=u;
}
inline int getans(int k)
{
	int sum=0;
	for (int i=1;i<=n;i++)dp[i]=1;
	for (int i=1;i<=n;i++)
	{
		int u=que[i];
		if(!fa[u]||dp[u]==-1||dp[fa[u]]==-1)continue;
		if(dp[u]+dp[fa[u]]>=k)sum++,dp[fa[u]]=-1;
		else dp[fa[u]]=max(dp[fa[u]],dp[u]+1);
	}return sum;
}

int find(int x)
{
	int tl=1,tr=n,p=0;
	while(tl<=tr)
	{
		int Mid=(tl+tr)>>1;
		if (getans(Mid)>=x)tl=Mid+1,p=Mid;
		else tr=Mid-1;
	}return p;
}

signed main()
{
	n=read();int BL=sqrt(n*log2(n));
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		add(u,v),add(v,u);
	}dfs(1);ans[1]=n;
	for (int i=2;i<=BL;i++)
		ans[i]=getans(i);
	for (int i=1;i<=ans[BL];i++)
	{
		int p=find(i),k=find(i+1);
		for (int j=k+1;j<=p;j++)
			ans[j]=max(ans[j],i);
	}
//	puts("qwq");
	for (int i=1;i<=n;i++)
		printf("%lld\n",max(0ll,ans[i]));
//	cout<<cntt<<endl;
	return 0;
}