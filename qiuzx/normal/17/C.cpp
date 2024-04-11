#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 51123987
#define F first
#define S second
#define ll int
#define N 152
using namespace std;
ll dp[N][N-99][N-99][N-99],n,nxt[N][3],ans=0;
string s;
int main(){
	ll i,j,k,l;
	cin>>n>>s;
	nxt[n][0]=nxt[n][1]=nxt[n][2]=n;
	for(i=n-1;i>=0;i--)
	{
		nxt[i][0]=nxt[i+1][0];
		nxt[i][1]=nxt[i+1][1];
		nxt[i][2]=nxt[i+1][2];
		nxt[i][s[i]-'a']=i;
	}
	dp[0][0][0][0]=1;
	for(i=0;i<n;i++)
	{
		for(j=0;j*3<=n+3;j++)
		{
			for(k=0;k*3<=n+3;k++)
			{
				for(l=0;l*3<=n+3;l++)
				{
					if(j+k+l==n&&abs(j-k)<=1&&abs(k-l)<=1&&abs(j-l)<=1)
					{
						ans=(ans+dp[i][j][k][l])%mod;
					}
					dp[nxt[i][0]][j+1][k][l]=(dp[nxt[i][0]][j+1][k][l]+dp[i][j][k][l])%mod;
					dp[nxt[i][1]][j][k+1][l]=(dp[nxt[i][1]][j][k+1][l]+dp[i][j][k][l])%mod;
					dp[nxt[i][2]][j][k][l+1]=(dp[nxt[i][2]][j][k][l+1]+dp[i][j][k][l])%mod;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}