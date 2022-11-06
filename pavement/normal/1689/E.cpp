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
using db = double;
using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using iiii = tuple<int, int, int, int>;
template<class key, class value = null_type, class cmp = less<key> >
using ordered_set = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

int T, N, add, A[2005], link[2005], sz[2005];

int ls(int x) {
	return x & -x;
}

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
		add = 0;
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> A[i];
			link[i] = i;
			sz[i] = 1;
			if (A[i] == 0) add++, A[i] = 1;
		}
		for (int i = 1; i <= N; i++)
			for (int j = i + 1; j <= N; j++)
				if (A[i] & A[j]) unite(i, j);
		if (sz[find(1)] == N) {
			cout << add << "\n";
			for (int i = 1; i <= N; i++) cout << A[i] << ' ';
			cout << '\n';
			continue;
		}
		bool can = 0;
		ii ans;
		for (int i = 1; i <= N; i++) {
			for (int k : {-1, 1}) {
				A[i] += k;
				for (int j = 1; j <= N; j++) {
					link[j] = j;
					sz[j] = 1;
				}
				for (int bit = 0; bit <= 30; bit++) {
					int prv = -1;
					for (int j = 1; j <= N; j++)
						if ((A[j] & (1ll << bit)) && prv != -1) unite(j, prv);
						else if (A[j] & (1ll << bit)) prv = j;
				}	
				if (sz[find(1)] == N) {
					can = 1;
					ans = mp(i, k);
				}
				A[i] -= k;
			}
		}
		if (can) {
			cout << add + 1 << "\n";
			for (int i = 1; i <= N; i++)
				if (i == ans.first) cout << A[i] + ans.second << ' ';
				else cout << A[i] << ' ';
			cout << '\n';
			continue;
		}
		vector<int> vec;
		for (int i = 1; i <= N; i++) {
			if (vec.empty() || ls(A[vec[0]]) < ls(A[i])) {
				vec.clear();
				vec.pb(i);
			} else if (ls(A[vec[0]]) == ls(A[i])) vec.pb(i);
		}
		assert(vec.size() > 1);
		cout << add + 2 << "\n";
		for (int i = 1; i <= N; i++)
			if (i == vec[0]) cout << A[i] - 1 << ' ';
			else if (i == vec[1]) cout << A[i] + 1 << ' ';
			else cout << A[i] << ' ';
		cout << '\n';
	}
}