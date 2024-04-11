#include<bits/stdc++.h>
#define MAXN 1e8
using namespace std;

const int M=2e5+10;
int T,n,ans;
int a[M],dp[M][3][3];
string s;

void DP()
{
	dp[1][0][1]=(a[1]==1);
	dp[1][1][2]=dp[1][1][1]=MAXN,dp[1][0][2]=MAXN;
	for (int i=2;i<=n;i++)
		dp[i][1][1]=min(dp[i-1][0][1],dp[i-1][0][2])+(a[i]==0),
		dp[i][1][2]=dp[i-1][1][1]+(a[i]==0),
		dp[i][0][1]=min(dp[i-1][1][1],dp[i-1][1][2])+(a[i]==1),
		dp[i][0][2]=dp[i-1][0][1]+(a[i]==1);
	int cnt=min(dp[n][1][1],dp[n][1][2]);
	ans=min(ans,cnt);
}

int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n>>s;ans=MAXN;
		for (int i=1;i<=n;i++)a[i]=s[i-1]=='L'?1:0;
		DP();
		int tmp=a[1];for (int i=1;i<n;i++)a[i]=a[i+1];a[n]=tmp;
		DP();
		tmp=a[1];for (int i=1;i<n;i++)a[i]=a[i+1];a[n]=tmp;
		DP();
		tmp=a[1];for (int i=1;i<n;i++)a[i]=a[i+1];a[n]=tmp;
		DP();
		cout<<ans<<endl;
	}
	return 0;
}