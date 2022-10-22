#include<bits/stdc++.h>
#define int long long
#define pb push_back
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

const int M=510;
int a[M][M],ans[M][M],n,m;

signed main()
{
	int T;cin>>T;while(T--)
	{
		cin>>n>>m;
		for (int i=1;i<=n;i++)
		{
			string s;cin>>s;
			for (int j=1;j<=m;j++)
				a[i][j]=ans[i][j]=s[j-1]=='.'?0:1;
		}
		if (n==1)
		{
			for (int i=1;i<=m;i++)cout<<"X";
			puts("");
			continue;
		}
		if (m==1)
		{
			for (int i=1;i<=n;i++)puts("X");
			continue;
		}
		for (int i=1;i<=n;i+=3)
			for (int j=1;j<=m;j++)
				ans[i][j]=1;
		for (int i=1;i<=n;i+=3)
		{
			if (i+1==n)break;
			if (ans[i+1][2])ans[i+2][2]=1;
			else if (ans[i+2][2])ans[i+1][2]=1;
			else ans[i+1][1]=ans[i+2][1]=1;
		}
		if (n%3==0)
		{
			for (int j=1;j<=m;j++)
				if (ans[n][j])ans[n-1][j]=1;
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
				if (ans[i][j])cout<<"X";
				else cout<<".";
			puts("");
		}
		for (int i=1;i<=n+3;i++)
			for (int j=1;j<=m+3;j++)
				a[i][j]=ans[i][j]=0;
	}
	return 0;
}