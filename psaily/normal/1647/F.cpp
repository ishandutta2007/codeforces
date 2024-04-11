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
const int mod=1e9+7,inf=1<<30;
// head 
const int N=5e5+5;
int n,ans,a[N];
int f[N],g[N],dp[N][2];
int q[2];


void solve() {
	int mxpos=max_element(a+1,a+1+n)-a;
	// [Linflection, mxpos]
	// f pre[i]'s min , g suf[i]'s max
	
	q[1]=q[0]=0;
	rep(i,1,n+1) f[i]=g[i]=-1;
	rep(i,1,mxpos) {
		if (a[i]>q[1]) q[1]=a[i],f[i]=q[0];
		else if (a[i]>q[0]) q[0]=a[i],f[i]=q[1];
		else {f[i]=-1; break;}
	}
	q[1]=q[0]=0;
	per(i,n+1,mxpos) {
		if (a[i]>q[1]) q[1]=a[i],g[i]=q[0];
		else if (a[i]>q[0]) q[0]=a[i],g[i]=q[1];
		else {g[i]=-1; break;}
	}
	int s=g[mxpos];
	if (s==-1) return;
	// debug(s);
	// [] -> [s,t]
	dp[mxpos][1]=s,dp[mxpos][0]=s;
	
	per(i,mxpos,1) {
		dp[i][1]=inf,dp[i][0]=0;
		// f[i][1]
		if (a[i]<a[i+1]) dp[i][1]=min(dp[i][1],dp[i+1][1]);
		if (a[i]<dp[i+1][0]) dp[i][1]=min(dp[i][1],a[i+1]);
		// f[i][0]
		if (a[i]>a[i+1]) dp[i][0]=max(dp[i][0],dp[i+1][0]);
		if (a[i]>dp[i+1][1]) dp[i][0]=max(dp[i][0],a[i+1]);
		// i as inflection
		if (~f[i]) {
			if (dp[i][0]&&f[i]<dp[i][0]) ans++;
		}
	}
}

int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",&a[i]);
	solve();
	reverse(a+1,a+1+n);
	solve();
	printf("%d\n",ans);
	return 0;	
}