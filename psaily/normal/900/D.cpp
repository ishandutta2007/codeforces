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
const int maxn=2005;

int A[maxn];
int x,y;
int fac[maxn],cnt;
ll dp[maxn];

ll fast_mod(ll x,int k){
	ll res=1;
	while(k){
		if(k&1)res=res*x%mod;
		x=x*x%mod,k>>=1;
	}
	return res;
}

int main(){
	scanf("%d%d",&x,&y);
	for(int i=1;i*i<=y;i++){
		if(y%i==0){
			if(i%x==0)fac[++cnt]=i;
			if(i*i!=y&&y/i%x==0)fac[++cnt]=y/i;
		}
	}
	sort(fac+1,fac+1+cnt);
	for(int i=cnt;i>=1;i--){
		int T=y/fac[i];
		dp[i]=fast_mod(2,T-1);
		for(int j=i+1;j<=cnt;j++)if(fac[j]%fac[i]==0){
			dp[i]-=dp[j];
			if(dp[i]<0)dp[i]+=mod;
		}
	}
	printf("%lld\n",dp[1]);
	return 0;
}