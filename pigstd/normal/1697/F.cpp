#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
#define WT int TT=read();while(TT--)
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
inline void ckmax(int &a,int b){a=(a>b?a:b);}
inline void ckmin(int &a,int b){a=(a<b?a:b);}

const int M=4e5+10;
int n,m,k,ti,dfn[M],low[M],col[M],st[M],top,tot,vis[M];
vector<int>e[M];

void add(int u,int v){e[u].pb(v);}

inline int F(int i,int j,int w){return (i-1)*(k-1)+j-1+w*n*(k-1);}

void tarjan(int u)
{
	dfn[u]=low[u]=++ti,st[++top]=u;vis[u]=1;
	for (auto v:e[u])
	{
		if (!dfn[v])tarjan(v),ckmin(low[u],low[v]);
		else if (vis[v])ckmin(low[u],low[v]);
	}
	if (low[u]==dfn[u])
	{
		tot++;
		while(st[top]!=u)
			col[st[top]]=tot,vis[st[top]]=0,top--;
		col[st[top]]=tot,vis[st[top]]=0,top--;
	}
}

void solve()
{
	n=read(),m=read(),k=read();
	for (int i=1;i<=2*n*(k-1);i++)col[i]=dfn[i]=low[i]=0,e[i].clear();
	for (int i=1;i<=n;i++)for (int j=2;j<k;j++)add(F(i,j+1,1),F(i,j,1)),add(F(i,j,0),F(i,j+1,0));
	for (int i=1;i<n;i++)for (int j=2;j<=k;j++)add(F(i,j,1),F(i+1,j,1)),add(F(i+1,j,0),F(i,j,0));
	while(m--)
	{
		int opt=read();
		if (opt==1)
		{
			int pos=read(),x=read();
			if (x==1)add(F(pos,2,0),F(pos,2,1));
			else if (x==k)add(F(pos,k,1),F(pos,k,0));
			else add(F(pos,x,1),F(pos,x+1,1)),add(F(pos,x+1,0),F(pos,x,0));
		}
		else if (opt==2)
		{
			int i=read(),j=read(),x=read();
			for (int p=2;p<=k;p++)
			{
				if (x-p>=k)continue;
				if (x-p<1)add(F(i,p,1),F(i,p,0)),add(F(j,p,1),F(j,p,0));
				else add(F(i,p,1),F(j,x-p+1,0)),add(F(j,x-p+1,1),F(i,p,0));
			}
		}
		else
		{
			int i=read(),j=read(),x=read();
			for (int p=1;p<k;p++)
			{
				if (x-p<=1)continue;
				if (x-p>k)add(F(i,p+1,0),F(i,p+1,1)),add(F(j,p+1,0),F(j,p+1,1));
				else add(F(i,p+1,0),F(j,x-p,1)),add(F(j,x-p,0),F(i,p+1,1));
			}
		}
	}
	ti=top=tot=0;
	for (int i=1;i<=2*n*(k-1);i++)if (!dfn[i])tarjan(i);
	for (int i=1;i<=n*(k-1);i++)if (col[i]==col[i+n*(k-1)])return puts("-1"),void();
	for (int i=1;i<=n;i++)
	{
		int ans=1;
		for (int j=2;j<=k;j++)
		{
			if (col[F(i,j,1)]<col[F(i,j,0)])ans=j;
//			cerr<<(col[F(i,j,1)]<col[F(i,j,0)])<<(j==k?'\n':' ');
		}
		cout<<ans<<' ';
	}
	cout<<'\n';
}

signed main()
{
	WT solve();
	return 0;
}