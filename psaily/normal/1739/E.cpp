#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,n,a) for (int i=(n)-1;i>=(a);i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define make_unique(x) { sort(all(x)); x.resize(unique(all(x))-x.begin()); }
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
mt19937 mrand(time(0));
typedef long long ll;
typedef double db;
typedef pair<int,int> PII;
typedef vector<int> VI;
const int inf=1<<30;
const int mod=998244353;
// head
const int N=2e6+10;
int n,a[2][N];
char s[2][N];
int dp[2][N];

void Max(int &a,int b) {a=max(a,b);}

void solve() {
	scanf("%d",&n);
	rep(i,0,2) scanf("%s",s[i]+1);
	rep(i,0,2) rep(j,1,n+1) a[i][j]=s[i][j]-'0';

	rep(i,0,n+2) rep(j,0,2) dp[j][i]=-inf;
	dp[0][0]=0;

	rep(i,0,n+1) rep(j,0,2) {
		Max(dp[j][i+1],dp[j][i]+a[j][i+1]);

		if (a[!j][i]) {
			int t=min(n+1,i+2);
			Max(dp[!j][t],dp[j][i]+a[!j][i]+a[!j][i+1]+a[!j][t]);
		}
	}


	//rep(i,0,n+2) rep(j,0,2) printf("dp[%d][%d]=%d\n",j,i,dp[j][i]);

	printf("%d\n",max(dp[0][n+1],dp[1][n+1]));
}

int main() {
	 //freopen("data.in","r",stdin);
  	// freopen("1.out","w",stdout);
	int tt=1;
	while (tt--) {
		solve();
	}
	return 0;
}