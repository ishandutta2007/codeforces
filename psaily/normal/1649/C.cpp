#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define SZ(x) ((int)x.size())
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fi first
#define se second
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long double db;
typedef unsigned long long ull;
// head

const int N=1e5+5;
int n,m;
VI x[N],y[N];
ll ans;

void solve(int x,vector<int>&v) {
	static ll sum[N];
	sort(all(v));
	rep(i,0,SZ(v)) {
		int s=v[i];
		if (i) {
			ans+=(1ll*s*i-sum[i-1]);
			sum[i]=sum[i-1]+v[i];
		}else sum[i]=v[i];
	}
}

int main() {
	scanf("%d%d",&n,&m);
	vector<VI> a(n+1);
	rep(i,1,n+1) {
		a[i].resize(m+1);
		rep(j,1,m+1) {
			scanf("%d",&a[i][j]);
			x[a[i][j]].pb(i); y[a[i][j]].pb(j);
		}
	}
	rep(i,0,N) {
		solve(i,x[i]),solve(i,y[i]);
	}
	printf("%lld\n",ans);
	return 0;	
}