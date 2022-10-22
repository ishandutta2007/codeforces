#include<bits/stdc++.h>
//#define int long long
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

const int inf=1e18;
const int M=1e6+10;
int n,m,ans[M];
pair<int,int>p[M];
vector<int>a[M],b[M],min1[M],max1[M],min2[M],max2[M];

signed main()
{
	WT
	{
		n=read(),m=read();
		for (int i=1;i<=n;i++)
		{
			a[i].clear();a[i].pb(0);
			for (int j=1;j<=m;j++)
				a[i].pb(read());
			p[i]=mp(a[i][1],i);
		}sort(p+1,p+1+n);
		for (int i=1;i<=n;i++)b[i]=a[p[i].y];
		//puts("??");
		for (int i=1;i<=n;i++)
		{
			max1[i].clear();max1[i].pb(0);
			for (int j=1;j<=m;j++)
			{
				if (i==1)max1[i].pb(max(max1[i][j-1],b[i][j]));
				else max1[i].pb(max(max(max1[i][j-1],max1[i-1][j]),b[i][j]));
			}
		}//puts("??");
		for (int i=n;i>=1;i--)
		{
			min1[i].clear();min1[i].pb(inf);
			for (int j=1;j<=m;j++)
			{
				if (i==n)min1[i].pb(min(min1[i][j-1],b[i][j]));
				else min1[i].pb(min(min(min1[i][j-1],min1[i+1][j]),b[i][j]));
			}
		}//puts("??");
		for (int i=1;i<=n;i++)
		{
			min2[i].clear();min2[i].resize(m+2);min2[i][m+1]=inf;
			for (int j=m;j>=1;j--)
			{
				if (i==1)min2[i][j]=min(min2[i][j+1],b[i][j]);
				else min2[i][j]=min(min(min2[i][j+1],min2[i-1][j]),b[i][j]);
			}
		}//puts("??");
		for (int i=n;i>=1;i--)
		{
			max2[i].clear();max2[i].resize(m+2);
			for (int j=m;j>=1;j--)
			{
				if (i==n)max2[i][j]=max(max2[i][j+1],b[i][j]);
				else max2[i][j]=max(max(max2[i][j+1],max2[i+1][j]),b[i][j]);
			}
		}//puts("??");
		int k=-1;for (int i=1;i<=n;i++)ans[i]=0;
		for (int i=1;i<n;i++)
		{
			if (k!=-1)break;
			for (int j=1;j<m;j++)
				if (max1[i][j]<min1[i+1][j]&&max2[i+1][j+1]<min2[i][j+1])
				{
					k=j;
					for (int w=1;w<=i;w++)ans[p[w].y]=1;
					break;
				}
		}
		if (k==-1){NO continue;}
		YES
		for (int i=1;i<=n;i++)if (ans[i])printf("B");else printf("R");
		printf(" %d\n",k);
	}
	return 0;
}