#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define make_unique(x) {sort(all(x)); x.resize(unique(all(x))-x.begin());} 
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
 
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef double db;
const int mod=1e9+7,inf=1<<30;
// head 
const int N=2e5+5;
int n;
ll a[N],sum[N],w[2][N];

void solve() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	rep(i,1,n+1) sum[i]=sum[i-1]+a[i];
	rep(i,1,n+1) {
		w[0][i]=w[0][i-1]+a[1]*a[i];
		w[1][i]=w[1][i-1]+a[n]*a[i];		
	}
	
	ll ans=-1e18,k=0,v=0;
	
	rep(i,2,n+1) {
		k+=a[1]+a[i];
		v+=a[1]*a[i];	
	}
	if (k>0) {
		puts("INF");
		return;	
	}
	ans=max(ans,v+k*(-a[1]));
	// debug(ans);
	k=v=0;
	rep(i,1,n) {
		k+=a[n]+a[i];
		v+=a[n]*a[i];
	}
	if (k<0) {
		puts("INF");
		return;
	}
	ans=max(ans,v+k*(-a[n]));
	rep(i,1,n) {
		// [1,i] [i+1,n]
		// -t [a[i],a[2]]	
		ll ret=0;
		k=(a[n]*i+sum[i]-sum[0])+(a[1]*(n-i)+sum[n]-sum[i])-a[1]-a[n];
		ret+=w[0][n]-w[0][i];
		ret+=w[1][i]-w[1][0];
		ret-=a[1]*a[n];
		ans=max(ans,ret-min(a[i],a[i+1])*k);
	}
	printf("%lld\n",ans);
}

int main() {
	int _;
	for (scanf("%d",&_);_;_--) {
		solve();	
	}
	return 0;	
}