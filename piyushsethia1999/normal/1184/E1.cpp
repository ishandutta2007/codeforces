#include <bits/stdc++.h>
#define pb emplace_back
#define fi first
#define se second
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }
 
class DSU
{
public:
	std::vector<int> parent;
	int n;
	DSU(int n) : n(n) { parent.resize(n, -1); };
	int root(int x);
	void merge(int x, int y);
	bool areInSame(int x, int y);
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
 
int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	#ifdef ANIKET_GOYAL
		freopen("inputf.in","r",stdin);
		freopen("outputf.in","w",stdout);
	#endif
	int n; cin >> n;
	int m; cin >> m;
	int u1, v1;
	std::vector<pair<pair<int,int>, pair<int, int>>> gr;
	for (int i = 0; i < m; ++i) {
		int u; cin >> u; u--; 
		int v; cin >> v; v--;
		int w; cin >> w;
		if (i == 0)
			u1 = u, v1 = v;
		gr.push_back({{w,i}, {u, v}});
	}
	int s = 0, e = 1000000006;
	while (s < e) {
		int mi = s + ((e - s + 1) >> 1);
		gr[0].first.first = mi;
		auto r = gr;
		stable_sort(r.begin(), r.end());
		DSU d(n);
		bool ok = false;
		for (int i = 0; i < m; ++i) {
			if (!d.areInSame(r[i].second.second, r[i].second.first)) {
				d.merge(r[i].second.second, r[i].second.first);
				if (r[i].second.first == u1 && r[i].second.second == v1) {
					ok = true;
					break;
				} 
			} 
		}
		if (ok)
			s = mi;
		else
			e = mi - 1;
		// d.
	} 
	if (e > 1000000000) e = 1000000000; 
	cout << e;
}