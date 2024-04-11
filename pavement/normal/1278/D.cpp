#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#ifdef TEST
#define getchar_unlocked _getchar_nolock
#define putchar_unlocked _putchar_nolock
#endif
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
typedef tuple<int, int, int, int> iiii;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, edges, A[1000005], rev[1000005], link[1000005], sz[1000005];
bool S[1000005];
list<int> L;
list<int>::iterator pos[1000005];

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
	for (int i = 1; i <= (N << 1); i++)
		link[i] = i, sz[i] = 1;
	for (int l, r, i = 1; i <= N; i++) {
		cin >> l >> r;
		A[l] = A[r] = l;
		rev[l] = rev[r] = i;
	}
	for (int i = 1; i <= (N << 1); i++) {
		if (S[A[i]]) {
			for (auto it = --L.end(); it != pos[A[i]]; it--) {
				edges++;
				if (edges >= N || find(rev[A[i]]) == find(rev[*it])) return cout << "NO\n", 0;
				unite(rev[A[i]], rev[*it]);
			}
			L.erase(pos[A[i]]);
		} else {
			L.pb(A[i]);
			pos[A[i]] = --L.end();
			S[A[i]] = 1;
		}
	}
	if (edges == N - 1) cout << "YES\n";
	else cout << "NO\n";
}