//AFO countdown:9 Days
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

const int M=4e5+10;
int n,m,u[M<<2],v[M<<2],in[M],Cnt,c[M];
vector<int>a[M],b[M],e[M];
int ti,cnt,dfn[M],low[M],vis[M],z[M],top;

void tarjan(int u)
{
	dfn[u]=low[u]=++ti,vis[u]=1,z[++top]=u;
	for (int i=0;i<e[u].size();i++)
	{
		int to=e[u][i];
		if (!dfn[to])tarjan(to),low[u]=min(low[u],low[to]);
		else if (vis[to])low[u]=min(low[u],low[to]);
	}
	if (dfn[u]==low[u])
	{
		++Cnt;
		while(z[top]!=u)
			c[z[top]]=Cnt,vis[z[top]]=0,top--;
		c[z[top]]=Cnt,vis[z[top]]=0,top--;
	}
}

int F(int x,int y){return (x-1)*m+y;}

signed main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)
	{
		string s;cin>>s;
		a[i].pb(0);
		for (int j=1;j<=m;j++)
			if (s[j-1]=='#')a[i].pb(1);
			else a[i].pb(0);
	}
	for (int i=n;i>=1;i--)
		for (int j=1;j<=m;j++)
			if (a[i][j])b[j].pb(i);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) 
		{
			if (!a[i][j])continue;
			if (i!=1&&a[i-1][j])
				e[F(i,j)].pb(F(i-1,j)),u[++cnt]=F(i,j),v[cnt]=F(i-1,j);
			if (b[j][0]>i)
			{
				int tl=0,tr=b[j].size()-1,p;
				while(tl<=tr)
				{
					int Mid=(tl+tr)>>1;
					if (b[j][Mid]>i)p=Mid,tl=Mid+1;
					else tr=Mid-1;
				}
				e[F(i,j)].pb(F(b[j][p],j));
				u[++cnt]=F(i,j),v[cnt]=F(b[j][p],j);
			}
			if (j!=1&&b[j-1].size()!=0&&b[j-1][0]>=i)
			{
				int tl=0,tr=b[j-1].size()-1,p;
				while(tl<=tr)
				{
					int Mid=(tl+tr)>>1;
					if (b[j-1][Mid]>=i)p=Mid,tl=Mid+1;
					else tr=Mid-1;
				}e[F(i,j)].pb(F(b[j-1][p],j-1));
				u[++cnt]=F(i,j),v[cnt]=F(b[j-1][p],j-1);
			}
			if (j!=m&&b[j+1].size()!=0&&b[j+1][0]>=i)
			{
				int tl=0,tr=b[j+1].size()-1,p;
				while(tl<=tr)
				{
					int Mid=(tl+tr)>>1;
					if (b[j+1][Mid]>=i)p=Mid,tl=Mid+1;
					else tr=Mid-1;
				}e[F(i,j)].pb(F(b[j+1][p],j+1));
				u[++cnt]=F(i,j),v[cnt]=F(b[j+1][p],j+1);
			}
		}int res=0;
//	for (int i=1;i<=cnt;i++)cout<<u[i]<<' '<<v[i]<<endl;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (a[i][j]&&!dfn[F(i,j)])tarjan(F(i,j));//,cout<<"q";
//	for (int i=1;i<=n;i++)
//		for (int j=1;j<=m;j++)
//			if (a[i][j])cout<<c[F(i,j)]<<' ';
//	cout<<Cnt<<endl;
	for (int i=1;i<=cnt;i++)
		if (c[u[i]]!=c[v[i]])in[c[v[i]]]++;
	for (int i=1;i<=Cnt;i++)
		if (in[i]==0)res++;//,cout<<i<<' ';
	cout<<res<<endl;
	return 0;
}