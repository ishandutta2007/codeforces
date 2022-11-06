#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#endif
#define int long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define ppb pop_back
#define eb emplace_back
#define g0(a) get<0>(a)
#define g1(a) get<1>(a)
#define g2(a) get<2>(a)
#define g3(a) get<3>(a)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef double db;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int T, N, A[500005], link[500005], sz[500005];
bool seen[500005];

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
		bool yep = 0;
		for (int i = 1; i <= N; i++) seen[i] = 0;
		cin >> N;
		if (N < 3) {
			for (int i = 1; i <= N; i++) {
				cin >> A[i];
			}
			if (is_sorted(A + 1, A + 1 + N)) cout << "YES\n";
			else cout << "NO\n";
			continue;
		}
		for (int i = 1; i <= N; i++) {
			link[i] = i;
			sz[i] = 1;
			cin >> A[i];
			if (seen[A[i]]) yep = 1;
			seen[A[i]] = 1;
		}
		if (yep) {
			cout << "YES\n";
			continue;
		}
		int cc = 0;
		for (int i = 1; i <= N; i++) unite(i, A[i]);
		for (int i = 1; i <= N; i++)
			if (i == find(i)) cc++;
		if ((N - cc) % 2 == 0) cout << "YES\n";
		else cout << "NO\n";
	}
}