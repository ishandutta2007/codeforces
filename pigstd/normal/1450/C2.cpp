#include<bits/stdc++.h>
using namespace std;

const int M=305;
int T,n,m,a[M][M],ans[M][M]; 

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

void solve(int ii,int jj,int kk,int &cnt)
{
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		{
			if (a[i][j]==0){ans[i][j]=0;continue;}
			if ((i+j)%3==ii)ans[i][j]=a[i][j];
			else if ((i+j)%3==jj)ans[i][j]=1;
			else ans[i][j]=2;
		}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (a[i][j]!=ans[i][j])cnt++;
}

signed main()
{
	cin>>T;
	while(T--)
	{
		cin>>n,m=n;int sum=0;
		for (int i=1;i<=n;i++)
		{
			string s;cin>>s;
			for (int j=1;j<=m;j++)
				if (s[j-1]=='.')a[i][j]=0;
				else if (s[j-1]=='X')a[i][j]=1,sum++;
				else a[i][j]=2,sum++;
		}bool f=0;
		for (int i=0;i<3;i++)
			for (int j=0;j<3;j++)
				for (int k=0;k<3;k++)
				{
					if (f)continue;
					if (i==j||i==k||j==k)continue;
					int cnt=0;
					solve(i,j,k,cnt);
					if (cnt<=sum/3)
						f=1;
				}
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
				if (ans[i][j]==0)cout<<'.';
				else if (ans[i][j]==1)cout<<'X';
				else cout<<'O';
			puts("");
		}
	}
	return 0;
}