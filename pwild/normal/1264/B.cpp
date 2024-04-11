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
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define TR(X) ({ if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })

void base(vl cnt, vl path) {
	vl z(3);
	FOR(i,0,3) {
		z[i] = min(cnt[i],cnt[i+1]);
		cnt[i] -= z[i];
		cnt[i+1] -= z[i];
	}

	FOR(i,0,4) if (cnt[i]) return;
	
	vl res;
	for (ll i: path) {
		res.pb(i);
		while (i < 3 && z[i]) {
			res.pb(i+1);
			res.pb(i);
			z[i]--;
		}
		while (i > 0 && z[i-1]) {
			res.pb(i-1);
			res.pb(i);
			z[i-1]--;
		}
	}
	
	FOR(i,0,3) if (z[i]) return;
	
	cout << "YES" << endl;
	for (ll x: res) cout << x << " ";
	cout << endl;
	exit(0);
}

void rec(ll i, vl cnt, vl path) {
	if (sz(path) >= 10) return;
	
	base(cnt,path);
	
	if (i < 3 && cnt[i+1]) {
		cnt[i+1]--, path.pb(i+1);
		rec(i+1, cnt, path);
		cnt[i+1]++, path.pop_back();
	}
	if (i > 0 && cnt[i-1]) {
		cnt[i-1]--, path.pb(i-1);
		rec(i-1, cnt, path);
		cnt[i-1]++, path.pop_back();
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	vl cnt(4);
	FOR(i,0,4) cin >> cnt[i];

	FOR(i,0,4) if (cnt[i]) {
		cnt[i]--;
		rec(i,cnt,{i});
		cnt[i]++;
	}
	cout << "NO" << endl;
}