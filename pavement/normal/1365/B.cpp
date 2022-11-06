#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define ins insert
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
typedef double db;
typedef long double ld;
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int T, N, A[505], C[505], link[505], sz[505];
bool B[505];
bool V[505];
vector<int> vec[505];

int find(int x) {
	if (x == link[x]) return x;
	return link[x] = find(link[x]);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (sz[b] > sz[a]) swap(a, b);
	sz[a] += sz[b];
	link[b] = a;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 1; i <= N; i++) cin >> A[i], link[i] = i, sz[i] = 1, vec[i].clear();
		for (int i = 1; i <= N; i++) cin >> B[i];
		for (int i = 1; i <= N; i++)
			for (int j = i + 1; j <= N; j++)
				if (B[i] != B[j]) unite(i, j);
		for (int i = 1; i <= N; i++)
			vec[find(i)].pb(i);
		for (int i = 1; i <= N; i++) {
			vector<ii> tmp;
			for (int j : vec[i]) {
				tmp.eb(A[j], j);
			}
			sort(tmp.begin(), tmp.end());
			int cnt = 0;
			for (int j : vec[i])
				C[j] = tmp[cnt++].first;
		}
		if (is_sorted(C + 1, C + 1 + N)) cout << "Yes\n";
		else cout << "No\n";
	}
}