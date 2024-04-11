#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

using namespace std;
struct DisjointSet {
	int fcnt;
	vector<int> f, sz;
	DisjointSet(int size) {
		f.resize(size);
		sz.resize(size);
		fcnt = size;
		foru(i, 0, size) {
			f[i] = i;
			sz[i] = 1;
		}
	}
	int father(int src) {
		if (src == f[src])return src;
		return f[src] = father(f[src]);
	}
	bool unite(int a, int b) {
		int fa = father(a), fb = father(b);
		if (sz[fa] < sz[fb])swap(fa, fb);
		if (fa == fb)return false;
		f[fb] = fa;
		fcnt--;
		sz[fa] += sz[fb];
		return true;
	}
};

const int sz = 1e6 + 5;
int n, pos[sz];
pii a[sz];
vector<int> adj[sz], toPush[sz];

int main() {
	//fast;
	scanf("%d", &n);
	foru(i, 0, n)
		scanf("%d", &a[i].first), a[i].second = i;
	foru(i, 0, n - 1) {
		int x, y;
		scanf("%d %d", &x, &y);
		adj[--x].pb(--y);
		adj[y].pb(x);
	}
	sort(a, a + n);
	foru(i, 0, n)pos[a[i].second] = i, toPush[i].clear();
	foru(i, 0, n) {
		for (int x : adj[i]) {
			if (pos[i] > pos[x])
				toPush[i].pb(x);
		}
	}
	ll ret = 0;
	DisjointSet dsu1(n);
	foru(i, 0, n) {
		ll s = 0, s2 = 0, tmp;
		for (int x : toPush[a[i].second]) {
			tmp = dsu1.sz[dsu1.father(x)];
			s += tmp;
			s2 += (tmp * tmp);
		}
		ll myocc = (s*s - s2) / 2 + s + 1;
		ret += a[i].first * myocc;
		for (int x : toPush[a[i].second])
			dsu1.unite(a[i].second, x);
	}
	reverse(a, a + n);
	foru(i, 0, n)pos[a[i].second] = i, toPush[i].clear();
	foru(i, 0, n) {
		for (int x : adj[i]) {
			if (pos[i] > pos[x])
				toPush[i].pb(x);
		}
	}
	DisjointSet dsu2(n);
	foru(i, 0, n) {
		ll s = 0, s2 = 0, tmp;
		for (int x : toPush[a[i].second]) {
			tmp = dsu2.sz[dsu2.father(x)];
			s += tmp;
			s2 += (tmp * tmp);
		}
		ll myocc = (s*s - s2) / 2 + s + 1;
		ret -= a[i].first * myocc;
		for (int x : toPush[a[i].second])
			dsu2.unite(a[i].second, x);
	}
	printf("%lld\n", ret);
	return 0;
}