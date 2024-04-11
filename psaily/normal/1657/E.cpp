#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define fi first
#define se second
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl

typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef double db;
const int mod=998244353,inf=1<<30;
// head 
const int N=255;
int n,k;
ll dp[N][N],comb[N][N],sum[N][N];
void add(ll &a,ll b) {(a+=b)%=mod;}
ll powmod(ll x,ll k) {ll res=1; for (;k;k>>=1,x=x*x%mod) if (k&1) res=res*x%mod; return res;}

int main() {
	rep(i,1,N) {
		comb[i][0]=comb[i][i]=1;
		rep(j,1,i) comb[i][j]=(comb[i-1][j-1]+comb[i-1][j])%mod;
	}
	scanf("%d%d",&n,&k); n--;
	dp[0][0]=1;
	rep(i,0,k+1) sum[0][i]=1;
	rep(i,1,n+1) {
		rep(j,1,k+1) {
			rep(h,1,i+1) {// (k-j+1)^h [h,i-h]
				add(dp[i][j],comb[n-(i-h)][h]*powmod(k-j+1,(h*(i-h)+h*(h-1)/2))%mod*sum[i-h][j-1]);
			}
			sum[i][j]=(sum[i][j-1]+dp[i][j])%mod;
			// printf("dp[%d][%d]=%lld\n",i,j,dp[i][j]);
			// printf("sum[%d][%d]=%lld\n",i,j,sum[i][j]);
		}
	}
	ll ans=0;
	rep(i,1,k+1) add(ans,dp[n][i]);
	printf("%lld\n",ans);
	return 0;	
}