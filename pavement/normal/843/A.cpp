#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define pp pop
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define g0(a) get<0>(a)
#define g1(a) get<1>(a)
#define g2(a) get<2>(a)
#define g3(a) get<3>(a)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long double ld;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, link[100005], sz[100005], A[100005];
pair<int, int> T[100005];
map<int, vector<int> > M;

int find(int x) {
	if (x == link[x]) return x;
	return link[x] = find(link[x]);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (sz[b] > sz[a]) swap(a, b);
	sz[a] += sz[b];
	link[b] = a;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		T[i] = mp(A[i], i);
		link[i] = i;
		sz[i] = 1;
	}
	sort(T + 1, T + 1 + N);
	for (int i = 1; i <= N; i++)
		unite(T[i].second, i);
	for (int i = 1; i <= N; i++)
		M[find(i)].pb(i);
	cout << M.size() << '\n';
	for (auto i : M) {
		cout << i.second.size() << ' ';
		for (int j : i.second) cout << j << ' ';
		cout << '\n';
	}
}