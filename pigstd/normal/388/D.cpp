#include<bits/stdc++.h>
#define int long long
using namespace std;

const int Mod=1e9+7;
int n,ans;
int dp[35][35][2];

void add(int &a,int b){a+=b;if (a>Mod)a%=Mod;}// 
int geteven(int i){return i?(1ll<<(i-1))%Mod:1;} 
int getodd(int i){return i?(1ll<<(i-1))%Mod:0;}

signed main()
{
	cin>>n;dp[30][0][1]=1;
	for (int i=30;i>=1;i--)
	{
		for (int j=30;j>=0;j--)
		{
			add(dp[i-1][j+1][0],dp[i][j][0]),
			add(dp[i-1][j][0],(1<<j)%Mod*dp[i][j][0]%Mod);
			if ((n>>(i-1))&1)//i 1
			{
				add(dp[i-1][j+1][1],dp[i][j][1]),
				add(dp[i-1][j][0],dp[i][j][1]*geteven(j));
				add(dp[i-1][j][1],dp[i][j][1]*getodd(j));
			}
			else add(dp[i-1][j][1],dp[i][j][1]*geteven(j));
		}
//		cout<<i<<endl;
	}
	for (int i=0;i<=30;i++)add(ans,dp[0][i][1]+dp[0][i][0]);
	cout<<ans;
	return 0;
}