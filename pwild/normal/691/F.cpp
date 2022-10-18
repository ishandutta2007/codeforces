#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
#define sz(c) ll((c).size())
#define all(c) begin(c), end(c)
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define FORD(i,a,b) for (ll i = (b)-1; i >= (a); i--)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define has(c,i) ((c).find(i) != end(c))
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

const ll m = 3e6 + 10;
int a[m];
ll cnt[m], cnt2[m];

int main() {
	int n; scanf("%d", &n);
	FOR(i,0,n) {
		scanf("%d", &a[i]);
		cnt[a[i]]++;
	}
	ll total = 0;
	FOR(i,1,m) for (ll j = 1; i*j < m; j++) {
		ll cur = (i != j) ? cnt[i]*cnt[j] : cnt[i]*(cnt[i]-1);
		total += cur, cnt2[i*j] += cur;
	}
	cnt2[m-1] += ll(n)*(n-1) - total;
	FORD(i,0,m-1) cnt2[i] += cnt2[i+1];
	
	int q; scanf("%d", &q);
	while (q--) {
		int p; scanf("%d", &p);
		printf("%lld\n", cnt2[p]);
	}

}