#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e5+10, MOD = 998244353;

struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
        k *= -1, m *= -1;
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return -(l.k * x + l.m);
	}
};

const ll INF = 1e18+10;

template<class T> using min_pq = priority_queue<T, vector<T>, greater<T>>;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<vector<pair<int, ll>>> adj(n);
    while (m--) {
        int a, b; ll w; cin >> a >> b >> w, --a, --b;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    vector<ll> pdp(n, INF); pdp[0] = 0;

    auto relax = [&]() {
        vector<ll> ndp(n, INF);

        min_pq<pair<ll, int>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({pdp[i], i});
            ndp[i] = pdp[i];
        }

        while (sz(pq)) {
            auto [d, c] = pq.top(); pq.pop();
            if (d != ndp[c]) continue;
            for (auto [nxt, w] : adj[c]) if (ndp[nxt] > ndp[c] + w) {
                ndp[nxt] = ndp[c] + w;
                pq.push({ndp[nxt], nxt});
            }
        }
        swap(ndp, pdp);
    };

    for (int rep = 0; rep < k; rep++) {
        relax();

        auto ndp = pdp;
        LineContainer lines;

        lines.clear();
        for (int i = 0; i < n; i++) {
            // a[j] + i^2 + j^2 - 2*i*j
            if (sz(lines)) ndp[i] = min(ndp[i], lines.query(i) + (long long) i * i);
            if (pdp[i] != INF) lines.add(-2 * i, pdp[i] + (long long) i * i);
        }

        lines.clear();
        for (int i = n-1; i >= 0; i--) {
            // a[j] + i^2 + j^2 - 2*i*j
            if (sz(lines)) ndp[i] = min(ndp[i], lines.query(i) + (long long) i * i);
            if (pdp[i] != INF) lines.add(-2 * i, pdp[i] + (long long) i * i);
        }

        swap(pdp, ndp);
    }
    relax();
    for (auto x : pdp) cout << x << ' ';
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}