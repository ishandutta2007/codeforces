#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<ctime>
using namespace std;

#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
#define fi first
#define se second
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;

const int maxn=2005;
const int mod=1e9+7;

int n,k,ans;
char str[maxn];

void add(ll &a,ll b){(a+=b)%=mod;}

ll dp[maxn][maxn],sum[maxn];

void solve(){
	dp[0][0]=sum[0]=1;
	for(int i=1;i<=n;i++){
		int len=n-i+1;
		for(int j=0;j<=k;j++){
			for(int p=i-1;p>=0&&(i-p)*len<=j;p--)add(dp[i][j],dp[p][j-(i-p)*len]);
			dp[i][j]=dp[i][j]*('z'-str[i])%mod;	
		}
		for(int j=0;j<=k;j++){
			add(dp[i][j],sum[j]*(str[i]-'a')%mod);
			add(sum[j],dp[i][j]);
			//debug(sum[j]);
		}
	}
	printf("%lld\n",sum[k]);
}

int main(){
	scanf("%d%d%s",&n,&k,str+1);
	solve();
	return 0;
}