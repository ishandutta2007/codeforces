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

const int M=110;
int ans[M][M];

signed main()
{
	WT
	{
		int n=read();
		for (int i=1;i<=n;i++)for (int j=1;j<=n;j++)ans[i][j]=0;
		if (n&1)
		{
			for (int i=2;i+1<=n;i+=2)
			{
				int x=i,y=i+1;
				for (int j=1;j<=i/2;j++)ans[j][x]=1;
				for (int j=i/2+1;j<i;j++)ans[j][x]=-1;
				ans[x][y]=1;
				for (int j=1;j<=i/2;j++)ans[j][y]=-1;
				for (int j=i/2+1;j<i;j++)ans[j][y]=1;
			}
		}
		else
		{
			for (int i=3;i+1<=n;i+=2)
			{
				int x=i,y=i+1;
				for (int j=1;j<=i/2;j++)ans[j][x]=1,ans[j][y]=-1;
				for (int j=i/2+1;j<i;j++)ans[j][y]=1,ans[j][x]=-1;
			}
		}
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)cout<<ans[i][j]<<' ';
		puts(""); 
	}
	return 0;
}