#include <bits/stdc++.h>

using namespace std;

long long n,m,dh[41][41],dp[41][41][41][41];
bitset<41> a[41];

int main()
{
	long long t,rr,i,j,r,ii,jj,mn,y,x,y2,x2;
	string s;
	
	scanf("%lld%lld%lld",&n,&m,&t);
	for(i=1;i<=n;i++)
	{
		cin>>s;
		for(j=1;j<=m;j++)
		{
			a[i][j]=s[j-1]-'0';
			dh[i][j]=(dh[i-1][j]+1)*!a[i][j];
		}
	}
	for(ii=1;ii<=n;ii++)
	{
		for(jj=1;jj<=m;jj++)
		{
			for(i=ii;i<=n;i++)
			{
				for(j=jj;j<=m;j++)
				{
					dp[ii][jj][i][j]=dp[ii][jj][i-1][j]+dp[ii][jj][i][j-1]-dp[ii][jj][i-1][j-1];
					mn=i-ii+1;
					for(r=j;r>=jj;r--)
					{
						mn=min(mn,dh[i][r]);
						dp[ii][jj][i][j]+=mn;
					}
				}
			}
		}
	}
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld",&y,&x,&y2,&x2);
		printf("%lld\n",dp[y][x][y2][x2]);
	}
}