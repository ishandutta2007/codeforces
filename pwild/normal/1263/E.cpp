#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
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

template<typename T>
struct segtree {
	ll n;
	vector<T> value;

	segtree<T>(vector<T> leaves): n(sz(leaves)) {
		value.resize(2*n);
		copy(all(leaves),begin(value)+n);
		FORD(i,1,n) value[i] = value[2*i] + value[2*i+1];
	}
	
	void update(ll i, T v) {
		i += n;
		value[i] = v;
		for (i /= 2; i; i /= 2) value[i] = value[2*i] + value[2*i+1];
	}
	
	T query(ll i, ll j) {
		i += n, j += n;
		T resl, resr;
		for (; i < j; i /= 2, j /= 2) {
			if (i & 1) resl = resl + value[i++];
			if (j & 1) resr = value[--j] + resr;
		}
		return resl + resr;
	}
};

struct node {
	ll dh = 0, hmin = 0, hmax = 0;
	node operator+(node n) {
		return {dh+n.dh, min(hmin,dh+n.hmin), max(hmax,dh+n.hmax)};
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	vector<node> leaves(n+5);
	segtree<node> S(leaves);

	ll pos = 0;
	FOR(i,0,n) {
		char c; cin >> c;
		if (c == 'L') {
			pos--;
			if (pos < 0) pos = 0;
		} else if (c == 'R') {
			pos++;
		} else {
			ll dh = c == '(' ? 1 : c == ')' ? -1 : 0;
			S.update(pos,node{dh,min(0,dh),max(0,dh)});
		}
		node res = S.query(0,n+5);
		bool ok = res.dh == 0 && res.hmin == 0;
		cout << (ok ? res.hmax : -1) << " \n"[i+1==n];
	}


}