#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#ifndef print
#define print(...)
#endif
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

class DSU
{
public:
	int *parent;
	int n;
	DSU(int n) : n(n) { parent = new int[n]; for (int i = 0; i < n; ++i) parent[i] = -1; };
	int root(int x);
	void merge(int x, int y);
	bool areInSame(int x, int y);
	~DSU();
};

int DSU::root(int x) { return (parent[x] < 0 ? x : (parent[x] = root(parent[x]))); }

void DSU::merge(int x, int y)
{
	if ((x = root(x)) == (y = root(y))) return;
	if (parent[x] > parent[y]) swap(x, y);
	parent[x] += parent[y];
	parent[y] = x;
}

bool DSU::areInSame(int x, int y) { return (root(x) == root(y)); }

DSU::~DSU()
{
	delete parent;
}

int l[200003];
int r[200003];
int cn[200003] = {};

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin >> n;
	int q; cin >> q;
	memset(r, -1, sizeof(l));
	memset(l, 0x3f, sizeof(r));
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		l[x] = min(l[x], i);
		r[x] = max(r[x], i);
		cn[x]++;
		print(x, cn[x]);
	}
	int p[200003];
	for (int i = 0; i < 200003; ++i) p[i] = i;
	sort(p, p + 200003, [&](int a, int b) {
		return l[a] < l[b];
	});
	int op = -1;
	int mx = 0;
	int to = 0;
	for (int i = 0; i < 200003; ++i) {
		if (r[p[i]] == -1) continue;
		if (op == -1) {
			op = p[i];
			mx = cn[op];
		} else if (r[op] < l[p[i]]) {
			print(mx);
			to += mx;
			op = p[i];
			mx = cn[op];
		} else {
			r[op] = max(r[op], r[p[i]]);
			cn[op] += cn[p[i]];
			mx = max(cn[p[i]], mx);
		}
	}
	if (op != -1) {
		to += mx;
		print(mx);
	}
	cout << n - to;
}