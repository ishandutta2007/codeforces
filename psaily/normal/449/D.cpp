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

const int mod=1e9+7;
const int maxn=1e6+5;

int n;
int a[maxn];
int dp[(1<<21)][21];

ll powmod(ll x,ll y,ll m){
	ll z=x%m;
	if(!y)return 1;
	if(y&1)return z*powmod(z*z,(y-1)/2,m)%m;
	else return powmod(z*z,y/2,m)%m;
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int i=0;i<n;i++)dp[a[i]][0]++;
	for(int i=1;i<21;i++){
		for(int j=0; j<(1<<21);j++){
			if((j>>(i-1))&1)dp[j][i]=dp[j][i-1];
			else dp[j][i]=dp[j][i-1]+dp[j+(1<<(i-1))][i-1];
		}
	}
	ll ans=0;
	for(int i=0;i<(1<<21);i++){
		ll cur=powmod(2,dp[i][20],mod)-1;
		if(__builtin_popcount(i)&1)cur=-cur;
		ans+=cur+mod;
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}