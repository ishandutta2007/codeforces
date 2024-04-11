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

const int N=2005;

int n,t;
db p,dp[N][N];

int main() {
	scanf("%d%lf%d",&n,&p,&t);
	dp[0][0]=1;
	rep(i,0,t) rep(j,0,n+1) {
		dp[i+1][j]+=dp[i][j]*(1-p);
		if (j<n) dp[i+1][j+1]+=dp[i][j]*p;
		else dp[i+1][n]+=dp[i][j]*p;
		// printf("dp[%d][%d]=%lf\n",i,j,dp[i][j]);
	}
	db ans=0;
	rep(i,1,n+1) ans+=i*dp[t][i];
	printf("%.10lf\n",ans);
	return 0;	
}