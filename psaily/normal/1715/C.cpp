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

int n,m;
int a[N];

ll getval(int x) {
	if (a[x]==a[x-1]) {
		return n-x+1;
	} else {
		return 1ll*x*(n-x+1);
	}
}

void solve() {
	scanf("%d%d",&n,&m);
	rep(i,1,n+1) scanf("%d",&a[i]);

	ll ans=0;

	rep(i,1,n+1) {
		ans+=getval(i);
	}

	while (m--) {
		int x,v;

		scanf("%d%d",&x,&v);
		
		int mn=max(1,x-2);
		int mx=min(n,x+2);

		rep(i,mn,mx+1) ans-=getval(i);
		a[x]=v;
		rep(i,mn,mx+1) ans+=getval(i);

		printf("%lld\n",ans);

	}

}


int main() {
	solve();


	return 0;
}