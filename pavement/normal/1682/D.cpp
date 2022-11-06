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

int T, N;
char S[200005], NS[200005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 1; i <= N; i++) cin >> S[i];
		int brk = -1;
		if (S[1] == S[N]) {
			for (int i = 1; i < N; i++)
				if (S[i] != S[i + 1]) {
					brk = i;
					break;
				}
			if (brk != -1) {
				for (int i = 1; i <= N; i++)
					NS[i] = S[(brk + i - 1) % N + 1];
				swap(S, NS);
			}
		}
		int len = 0;
		vector<tuple<char, int, int> > vec;
		for (int i = 1; i <= N; i++) {
			if (i > 1 && S[i - 1] != S[i]) {
				vec.eb(S[i - 1], len, i - 1);
				len = 0;
			}
			len++;
		}
		vector<ii> op;
		vector<int> prob;
		vec.eb(S[N], len, N);
		if (vec.size() == 1 && g0(vec[0]) == '0') {
			cout << "NO\n";
			continue;
		}
		for (auto [c, len, r] : vec) {
			if (c == '0') {
				for (int i = r; i - 1 >= r - len + 1; i--)
					op.eb(i - 1, i);
				op.eb(r, r % N + 1);
			}
		}
		for (auto [u, v] : op) {
			S[u] = (S[u] == '0' ? '1' : '0');
			S[v] = (S[v] == '0' ? '1' : '0');
		}
		for (int i = 1; i <= N; i++)
			if (S[i] == '1') prob.pb(i);
		if (prob.size() % 2 == 1) cout << "NO\n";
		else {
			for (int i = 1; i < prob.size(); i++)
				op.eb(prob[0], prob[i]);
			cout << "YES\n";
			for (auto [u, v] : op) {
				if (brk != -1) {
					u += brk;
					v += brk;
					u--;
					v--;
					u = (u % N + N) % N;
					v = (v % N + N) % N;
					u++;
					v++;
				}
				cout << u << ' ' << v << '\n';
			}
		}
	}
}