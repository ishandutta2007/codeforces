#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
  
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define mp make_pair
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef unsigned long long ull;
// head

const int M=4005;
const int mod=1e9+7;
int n;
int dp[M][M],comb[M][M];

void init() {
	rep(i,0,M) {
		comb[i][0]=comb[i][i]=1;
		rep(j,1,i) comb[i][j]=(comb[i-1][j]+comb[i-1][j-1])%mod;
	}
}

int main() {
	init();
	scanf("%d",&n);
	dp[0][0]=1;
	rep(i,0,n) rep(j,0,i+1) if (dp[i][j]) {
		(dp[i+1][j]+=1ll*dp[i][j]*j%mod)%=mod;
		(dp[i+1][j+1]+=1ll*dp[i][j])%=mod;
	}
	int ans=1;
	rep(i,1,n) rep(j,0,i+1) if (dp[i][j]) {
		(ans+=1ll*dp[i][j]*comb[n][i]%mod)%=mod;
	}
	printf("%d\n",ans);
	return 0;	
}