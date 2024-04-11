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

int T, N, M, A[200005], _A[200005];
set<int> bad;

int conv(int r, int c) {
	return (r - 1) * M + c;
}

void swpp(int x, int y) {
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			_A[conv(i, j)] = (j == x ? A[conv(i, y)] : (j == y ? A[conv(i, x)] : A[conv(i, j)]));
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			A[conv(i, j)] = _A[conv(i, j)];
}

bool correct() {
	for (int i = 1; i <= N; i++)
		for (int j = 1; j < M; j++)
			if (A[conv(i, j)] > A[conv(i, j + 1)]) return 0;
	return 1;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		bad.clear();
		cin >> N >> M;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				cin >> A[conv(i, j)];
		int arr = -1;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j < M; j++)
				if (A[conv(i, j)] > A[conv(i, j + 1)]) {
					bad.insert(j);
					arr = i;
				}
		if (bad.empty()) cout << "1 1\n";
		else {
			if (bad.size() == 1) {
				int can = *bad.begin() + 1;
				for (int i = *bad.begin() + 1; i <= M; i++)
					if (A[conv(arr, i)] == A[conv(arr, *bad.begin() + 1)])
						can = i;
				swpp(*bad.begin(), can);
				if (correct()) cout << *bad.begin() << ' ' << can << '\n';
				else {
					swpp(*bad.begin(), can);
					can = *bad.begin();
					for (int i = *bad.begin(); i >= 1; i--)
						if (A[conv(arr, i)] == A[conv(arr, *bad.begin())])
							can = i;
					swpp(*bad.begin() + 1, can);
					if (correct()) cout << *bad.begin() + 1 << ' ' << can << '\n';
					else cout << "-1\n";
				}
			} else {
				int f = *bad.begin(), s = *bad.rbegin();
				ii ans = mp(-1, -1);
				for (int x = f; x <= f + 1; x++)
					for (int y = s; y <= s + 1; y++) {
						swpp(x, y);
						if (correct()) ans = mp(x, y);
						swpp(x, y);
					}
				if (ans.first == -1) cout << "-1\n";
				else cout << ans.first << ' ' << ans.second << '\n';
			}
		}
	}
}