//GM when? 
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

const int inf=1e18;
const int M=410;
int n,m,a[M][M],sum[M][M];

int query(int X1,int Y1,int X2,int Y2){return sum[X2][Y2]+sum[X1-1][Y1-1]-sum[X1-1][Y2]-sum[X2][Y1-1];}

signed main()
{
	WT
	{
		n=read(),m=read();int ans=inf;
		for (int i=1;i<=n;i++)
		{
			string s;cin>>s;
			for (int j=1;j<=m;j++)
				a[i][j]=s[j-1]-'0',sum[i][j]=a[i][j];
		}
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
		for (int i=1;i<=n;i++)
			for (int j=i+4;j<=n;j++)
			{
				int minn=query(i+1,2,j-1,3)+(j-i-1)-query(i+1,1,j-1,1);
				minn+=(a[i][2]^1)+(a[i][3]^1)+(a[j][2]^1)+(a[j][3]^1);
				ans=min(ans,minn+(j-i-1)-query(i+1,4,j-1,4));
				for (int k=5;k<=m;k++)
				{
					minn=min(minn+query(i+1,k-1,j-1,k-1)+(a[i][k-1]^1)+(a[j][k-1]^1),
					query(i+1,k-2,j-1,k-1)+(j-i-1)-query(i+1,k-3,j-1,k-3)+
					(a[i][k-1]^1)+(a[i][k-2]^1)+(a[j][k-1]^1)+(a[j][k-2]^1));
					ans=min(ans,minn+(j-i-1)-query(i+1,k,j-1,k));
				}
			}
		cout<<ans<<endl;
	}
	return 0;
}