#include <bits/stdc++.h>
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
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl

typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
typedef vector<int> vi;

const int N=2005;
const int mod=1e9+7;
int n,k;
ll dp[N][N];

int main() {
	scanf("%d%d",&n,&k);
	rep(i,1,n+1) dp[1][i]=1;
	rep(i,1,k) {
		rep(j,1,n+1) {
			for (int k=j;k<=n;k+=j) (dp[i+1][k]+=dp[i][j])%=mod;	
		}
	}
	ll ans=0;
	rep(i,1,n+1) ans=(ans+dp[k][i])%mod;
	printf("%lld\n",ans);
	
	return 0;	
}