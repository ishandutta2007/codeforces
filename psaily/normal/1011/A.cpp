#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
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
// head

const int N=55;

int n,k,m,cnt;
int a[N];
char str[N];
int dp[N][N][N];

void chkmin(int &a,int b) {if (a>b) a=b;}

int main() {
	scanf("%d%d%s",&n,&k,str+1);
	rep(i,1,n+1) a[i]=str[i]-'a'+2;
	sort(a+1,a+1+n);
	n=unique(a+1,a+1+n)-a-1;
	if (n<k) return puts("-1"),0;
	memset(dp,inf,sizeof(dp));
	dp[0][0][0]=0;
	rep(i,1,n+1) {
		int up=a[i];
		// bug(i),debug(up);
		rep(j,0,k+1) rep(h,0,28) dp[i][j][h]=dp[i-1][j][h];
		rep(j,1,k+1) rep(h,0,up-1) chkmin(dp[i][j][up],dp[i-1][j-1][h]+up-1);
		// rep(j,0,k+1) rep(h,0,27) if (dp[i][j][h]<inf) printf("dp[%d][%d][%d]=%d\n",i,j,h,dp[i][j][h]);
	}
	int ans=inf;
	rep(i,0,28) chkmin(ans,dp[n][k][i]);
	printf("%d\n",ans==inf?-1:ans);
	return 0;	
}