#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <set>
#include <map>
#include <random>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>

typedef long long ll;
typedef long double ld;
using namespace std;

const int N = 400001;
map<int, int> m;
int p[N], r[N], d[N];

int get(int x) {
	if (m.count(x))
		return m[x];
	int sz = m.size() + 1;
	m[x] = sz;
	return sz;
}

void merge(int v, int u, int x) {
	if (r[v] < r[u])
		swap(v, u);
	if (r[u] == r[v])
		r[v]++;
	d[u] = x;
	p[u] = v;
}

pair<int, int> getp(int v) {
	int x = 0;
	while (p[v] != v) {
		x ^= d[v];
		v = p[v];
	}
	return {v, x};
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q, t, l, r, x;
	int last = 0, ans;
	cin >> q;
	for (int i = 0; i < N; i++)
		p[i] = i;
	for (int i = 0; i < q; i++) {
		cin >> t;
		if (t == 1) {
			cin >> l >> r >> x;
			l ^= last;
			r ^= last;
			x ^= last;
			if (l > r)
				swap(l, r);
			r++;
			pair<int, int> p1 = getp(get(l)), p2 = getp(get(r));
			if (p1.first == p2.first)
				continue;
			merge(p1.first, p2.first, p1.second ^ p2.second ^ x);
		}
		else {
			cin >> l >> r;
			l ^= last;
			r ^= last;
			if (l > r)
				swap(l, r);
			r++;
			if (!m.count(l) || !m.count(r)) {
				cout << -1 << '\n';
				last = 1;
				continue;
			}
			pair<int, int> p1 = getp(get(l)), p2 = getp(get(r));
			if (p1.first != p2.first) {
				ans = -1;
				last = 1;
			}
			else
				ans = last = p1.second ^ p2.second;
			cout << ans << '\n';
		}
	}
}