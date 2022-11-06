#include <bits/stdc++.h>
using namespace std;
#define MAX_N 2005
typedef long long ll;

ll link[MAX_N], sz[MAX_N], c[MAX_N], idxs[MAX_N];

inline ll find(ll x) {
	if (link[x] == x) return x;
	return link[x] = find(link[x]);
}

inline void unite(ll a, ll b) {
	a = find(a);
	b = find(b);
	if (sz[b] > sz[a]) swap(a, b);
	sz[a] += sz[b];
	link[b] = a;
	if (c[b] < c[a]) idxs[a] = idxs[b], c[a] = c[b];
}

int main() {
	ll n;
	scanf("%lld", &n);
	ll x[n], y[n], k[n], w, u, v;
	for (ll i = 0; i < n; i++) scanf("%lld%lld", &x[i], &y[i]);
	for (ll i = 0; i < n; i++) scanf("%lld", &c[i]);
	for (ll i = 0; i < n; i++) sz[i] = 1, scanf("%lld", &k[i]);
	ll sz = n * (n - 1) / 2;
	tuple<ll, ll, ll> ed[sz];
	ll idx = 0;
	for (ll i = 0; i < n; i++) {
		link[i] = idxs[i] = i;
		for (ll j = i + 1; j < n; j++) {
			ed[idx++] = make_tuple((abs(x[i] - x[j]) + abs(y[i] - y[j])) * (k[i] + k[j]), i, j);
		}
	}
	sort(ed, ed + sz);
	vector<pair<ll, ll> > conn;
	ll ty = 0;
	for (auto i : ed) {
		tie(w, u, v) = i;
		if (find(u) != find(v)) {
			if (c[find(u)] + c[find(v)] >= min(c[find(u)], c[find(v)]) + w) {
				unite(u, v);
				ty += w;
				conn.emplace_back(u, v);
			}
		}
	}
	vector<ll> ps;
	bool vi[n] = {};
	for (ll i = 0; i < n; i++) {
		if (!vi[idxs[find(i)]]) {
			ty += c[find(i)];
			ps.push_back(idxs[find(i)]);
			vi[idxs[find(i)]] = true;
		}
	}
	printf("%lld\n%u\n", ty, ps.size());
	for (ll i : ps) printf("%lld ", i + 1);
	printf("\n%u\n", conn.size());
	for (auto i : conn) printf("%lld %lld\n", i.first + 1, i.second + 1);
}