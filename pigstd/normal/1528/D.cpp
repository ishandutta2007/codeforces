#pragma GCC diagnostic error "-std=c++14"
#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--) 
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

const int inf=4557430888798830399;
const int M=610;
int n,m,u,v,w,dis[M],ww[M],vis[M];
struct edge
{
	int to,next,w;
}e[M*M];int cnt,head[M];
void add(int u,int to,int w)
{
	e[++cnt].to=to,e[cnt].w=w,e[cnt].next=head[u],head[u]=cnt;
}

inline int min(int a,int b){return a>b?b:a;}
//inline int f(int x){return x>=n?x-n:x;}

void dij(int s)
{
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;int k=n;
	while(k--)
	{
		int minp=-1;
		for (int i=0;i<n;i++)
			if (!vis[i]&&(minp==-1||dis[i]<dis[minp]))
				minp=i;
		vis[minp]=1;
		for (int i=0;i<n;i+=8)
			ww[i]=ww[i+1]=ww[i+2]=ww[i+3]=
			ww[i+4]=ww[i+5]=ww[i+6]=ww[i+7]=inf;
		for (int i=head[minp];i;i=e[i].next)
		{
			int to=(e[i].to+dis[minp])%n,w=e[i].w;
			ww[to]=w;
		}
		ww[0]=min(ww[n-1]+1,ww[0]);
		for (int i=1;i<n;i++)ww[i]=min(ww[i-1]+1,ww[i]);
		ww[0]=min(ww[n-1]+1,ww[0]);
		for (int i=1;i<n;i++)ww[i]=min(ww[i-1]+1,ww[i]);
		for (int i=0;i<n;i++)
			dis[i]=min(dis[i],ww[i]+dis[minp]);
	}
	for (int i=0;i<n;i++)
		printf("%lld ",dis[i]);
	puts("");
}

signed main()
{
//	freopen("233.in","r",stdin);
//	freopen("2.out","w",stdout);
	n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		u=read(),v=read(),w=read(),
		add(u,v,w);
	}
	for (int i=0;i<n;i++)
		dij(i);
	return 0;
}