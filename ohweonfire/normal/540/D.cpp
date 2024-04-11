#include <bits/stdc++.h>
using namespace std;
const int maxn=105;
const int R=0,S=1,P=2;
double dp[maxn][maxn][maxn][3];
int main()
{
	int r,s,p;
	cin>>r>>s>>p;
	dp[1][0][0][R]=dp[0][1][0][S]=dp[0][0][1][P]=1.0;
	for(int sum=2;sum<=r+s+p;sum++)
		for(int i=0;i<=r;i++)
			for(int j=0;j<=s&&i+j<=sum;j++)
			{
				int k=sum-i-j;
				double cnt=i*j+j*k+i*k;
				if(i*j+j*k+i*k==0)
				{
					if(i>0)dp[i][j][k][0]=1.0;
					if(j>0)dp[i][j][k][1]=1.0;
					if(k>0)dp[i][j][k][2]=1.0;
					continue;
				}
				double cnti=k*1.0*i/cnt,cntj=i*1.0*j/cnt,cntk=j*1.0*k/cnt;
				if(i>0)
					for(int t=0;t<3;t++)dp[i][j][k][t]+=dp[i-1][j][k][t]*cnti;
				if(j>0)
					for(int t=0;t<3;t++)dp[i][j][k][t]+=dp[i][j-1][k][t]*cntj;
				if(k>0)
					for(int t=0;t<3;t++)dp[i][j][k][t]+=dp[i][j][k-1][t]*cntk;
			}
	for(int i=0;i<3;i++)printf("%.12lf ",dp[r][s][p][i]);
	return 0;
}