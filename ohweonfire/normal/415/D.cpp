#include <stdio.h>
#include <cstdlib>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
int dp[2002][2002];
ll solve(int n,int k)
{
if(dp[n][k]!=0)
return dp[n][k];
 	if(n==1)return 1;
 	if(k==1)return n;
 	ll res=0;
 	for(int i=1;i<=n;i++)res=(res+solve(n/i,k-1))%MOD;
 	return dp[n][k]=res;
}
int main()
{
 	int n,k;
 	scanf("%d%d",&n,&k);
 	printf("%d\n",solve(n,k));
 	//system("pause");
 	return 0;
}