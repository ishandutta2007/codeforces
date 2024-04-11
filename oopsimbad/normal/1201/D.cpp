#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define f first
#define s second
#define mp make_pair
#define pb push_back
 
///
ll alot = 987654321123456789LL;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
	int n, m, k, q; cin >> n >> m >> k >> q;
	vector<vi> v(n);
	F0R(i, k) {
		int a, b; cin >> a >> b;
		v[a-1].pb(b);
	}
	v[0].pb(1);
	F0R(i, n) sort(v[i].begin(), v[i].end());
	vector<pair<int,ll>> pts;
	pts.pb(mp(1,0));
	set<int> cols;
	F0R(i, q) {
		int a; cin >> a;
		cols.insert(a);
	}
	int stop = n-1;
	while(v[stop].empty()) stop--;
	int prow = 0;
	F0R(i, n) {
		if(v[i].empty()) continue;
		int nl = v[i][0], nr = v[i][v[i].size()-1];
		ll nld = alot, nrd = alot;
		for(auto p : pts) {
			nrd = min(nrd,p.s+abs(p.f-nl)+nr-nl);
			nld = min(nld,p.s+abs(p.f-nr)+nr-nl);
		}
		nld += i-prow;
		nrd += i-prow;
		if(stop==i) {
			cout << min(nld,nrd) << endl;
			break;
		}
		pts.clear();
		auto lp1 = cols.upper_bound(nl);
		auto lp2 = lp1--;
		if(lp2 != cols.end()) pts.pb(mp(*lp2,abs(nl-*lp2)+nld));
		if(lp2 != cols.begin()) pts.pb(mp(*lp1,abs(nl-*lp1)+nld));
		lp1 = cols.upper_bound(nr);
		lp2 = lp1--;
		if(lp2 != cols.end()) pts.pb(mp(*lp2,abs(nr-*lp2)+nrd));
		if(lp2 != cols.begin()) pts.pb(mp(*lp1,abs(nr-*lp1)+nrd));
		prow = i;
	}
///
	return 0;
}