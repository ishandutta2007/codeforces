#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--) 
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
const int mod=998244353,inf=1<<30;
// head
const int N=2e5+5;
int n;

void solve() {
	scanf("%d",&n);
	vector<int> a(n),xs;
	rep(i,0,n) scanf("%d",&a[i]),xs.pb(a[i]);
	make_unique(xs);
	int m=SZ(xs);
	// debug(m);
	vector<int> cnt(m);
	rep(i,0,n) a[i]=lower_bound(all(xs),a[i])-xs.begin(),cnt[a[i]]++;

	vector<int> sum(m),rsum(m);
	rep(i,0,m) {
		int t=0;
		if (cnt[i]>1) t=2; else t=1;
		sum[i]=(i>0?sum[i-1]:0)+t;
	}
	per(i,m,0) {
		int t=0;
		if (cnt[i]>1) t=2; else t=1;
		rsum[i]=(i<m-1?rsum[i+1]:0)+t;
		// bug(i),debug(rsum[i]);
	}

	int ans=max(rsum[0]/2,sum[m-1]/2);
	ans=max(ans,1);
	rep(i,0,m) {
		int res=1;
		if (i>0) res+=sum[i-1]/2;
		if (i<m-1) res+=rsum[i+1]/2;
		ans=max(ans,res);
	}
	printf("%d\n",ans);
}

int main() {
	int _;
	for (scanf("%d",&_);_;_--) {
		solve();
	}

	return 0;
}