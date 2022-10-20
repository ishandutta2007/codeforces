#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 110
#define M 300010
using namespace std;
ll n,m,dp[M][N];
bool vis[11];
vector<ll> plc;
int main(){
	ll i,j,k;
	cin>>n>>m;
	while(n!=0)
	{
		plc.push_back(n%10);
		n/=10;
	}
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(i=0;i<(1<<(ll)plc.size());i++)
	{
		for(j=0;j<m;j++)
		{
			memset(vis,false,sizeof(vis));
			for(k=0;k<plc.size();k++)
			{
				if(vis[plc[k]]||(i&(1<<k))||(i==0&&plc[k]==0))
				{
					continue;
				}
				dp[i|(1<<k)][(j*10+plc[k])%m]+=dp[i][j];
				vis[plc[k]]=true;
			}
		}
	}
	cout<<dp[(1<<plc.size())-1][0]<<endl;
	return 0;
}