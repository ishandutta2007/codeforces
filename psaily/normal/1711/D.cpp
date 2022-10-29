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
int x[N],p[N];

void solve() {
	vector<int> xs;
	scanf("%d%d",&n,&m);
	rep(i,1,n+1) {
		scanf("%d%d",&x[i],&p[i]);
		xs.pb(x[i]),xs.pb(x[i]+p[i]),xs.pb(x[i]-p[i]);
	}
	make_unique(xs);
	vector<ll> sum(SZ(xs));

	rep(i,1,n+1) {
		int l=lower_bound(all(xs),x[i]-p[i])-xs.begin();
		int r=lower_bound(all(xs),x[i]+p[i])-xs.begin();
		int md=lower_bound(all(xs),x[i])-xs.begin();
		sum[l]++,sum[md]-=2,sum[r]++;
	}

	ll res=0,k=0;
	vector<ll> val(SZ(xs)+1);
	vector<int> tmp,ptmp;

	rep(i,0,SZ(xs)) {
		val[i]=res;
		k+=sum[i];
		if (i!=SZ(xs)-1) res+=k*(xs[i+1]-xs[i]);
		// (i,val[i])
		//bug(i),bug(xs[i]),debug(val[i]);
		if (val[i]>m) {
			//bug(i),bug(xs[i]),debug(val[i]);
			tmp.pb(i);
			ptmp.pb(xs[i]);
			val[i]-=m;

		}
	}

	vector<ll> lsum(SZ(xs)),rsum(SZ(xs));

	rep(i,0,SZ(tmp)) {
		int x=tmp[i];
		lsum[i]=val[x]-xs[x];
		if (i) lsum[i]=max(lsum[i],lsum[i-1]);
	}
	per(i,SZ(tmp),0) {
		int x=tmp[i];
		rsum[i]=val[x]+xs[x];
		if (i!=SZ(tmp)-1) rsum[i]=max(rsum[i],rsum[i+1]);
	}

	if (!SZ(tmp)) {
		rep(i,1,n+1) printf("1");
		puts("");
		return;
	}

	rep(i,1,n+1) {
		if (xs[tmp[0]]<=x[i]-p[i]||xs[tmp[SZ(tmp)-1]]>=x[i]+p[i]) printf("0");
		else {
			// bug(i),debug(x[i]);
			int rp=lower_bound(all(ptmp),x[i])-ptmp.begin();
			int lp=rp-1;
			bool ok=1;

			// bug(lp),debug(rp);

			if (lp>=0) {
				if (lsum[lp]>p[i]-x[i]) ok=0;
			}

			if (rp!=SZ(tmp)) {
				//debug(rsum[rp]);
				if (rsum[rp]>p[i]+x[i]) ok=0;
			}

			if (ok) printf("1"); else printf("0");
		}
	}
	puts("");
}

int main() {
	int _;
	for (scanf("%d",&_);_;_--) {
		solve();
	}
	return 0;
}
/*
1
3 6
1 5
5 5
3 4
*/