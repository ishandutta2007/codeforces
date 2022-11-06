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

int N, A[100005];
tuple<int, int, vector<int> > op[4];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	if (N == 1) {
		cin >> A[1];
		cout << "1 1\n" << -A[1] << '\n';
		cout << "1 1\n" << 1 << '\n';
		cout << "1 1\n" << -1 << '\n';
		return 0;
	}
	vector<int> tmp;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		if (i < N) {
			int curr = 0;
			if (A[i] < 0) {
				// find min k s.t.
				// A[i] + k * (N - 1) > 0
				// k > (-A[i]) / (N - 1)
				int k = (-A[i]) / (N - 1) + 1;
				A[i] += k * (N - 1);
				curr += k * (N - 1);
			}
			curr += A[i] * (N - 1);
			tmp.pb(curr);
			A[i] += A[i] * (N - 1);
		} else {
			vector<int> tmp2;
			tmp2.pb(-A[i]);
			A[i] = 0;
			op[2] = mt(i, i, tmp2);
		}
	}
	op[1] = mt(1, N - 1, tmp);
	tmp.clear();
	for (int i = 1; i <= N; i++)
		tmp.eb(-A[i]);
	op[3] = mt(1, N, tmp);
	for (int k = 1; k <= 3; k++) {
		cout << g0(op[k]) << ' ' << g1(op[k]) << '\n';
		for (int i : g2(op[k])) cout << i << ' ';
		cout << '\n';
	}
}