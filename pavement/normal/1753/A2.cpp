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

int T, N, A[200005], col[200005], ml[200005], mr[200005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		int nonzero = 0, curr = 0;
		vector<ii> curr_seg;
		vector<vector<ii> > segs;
		for (int i = 1; i <= N; i++) {
			cin >> A[i];
			curr_seg.eb(A[i], i);
			if (A[i]) {
				nonzero++;
				if (nonzero % 2 == 0) {
					segs.eb(curr_seg);
					curr_seg.clear();
				}
			}
		}
		segs.pb(curr_seg);
		if (nonzero & 1) cout << "-1\n";
		else {
			for (auto i : segs) {
				vector<int> nzidx;
				for (auto [j, idx] : i) {
					if (j) nzidx.pb(idx);
				}
				if (nzidx.empty()) {
					for (auto [j, idx] : i)
						col[idx] = ++curr;
					break;
				}
				assert(nzidx.size() == 2);
				int st = i[0].second, ed = i.back().second;
				if (A[nzidx[0]] == A[nzidx[1]]) {
					for (int j = st; j <= nzidx[0]; j++)
						col[j] = ++curr;
					if (nzidx[0] == nzidx[1] - 1) {
						col[nzidx[1]] = curr;
					} else {
						for (int j = nzidx[0] + 1; j < nzidx[1] - 1; j++)
							col[j] = ++curr;
						col[nzidx[1] - 1] = col[nzidx[1]] = ++curr;
					}
				} else {
					for (int j = st; j <= nzidx[1]; j++)
						col[j] = ++curr;
				}
				for (int j = nzidx[1] + 1; j <= ed; j++)
					col[j] = ++curr;
			}
			for (int i = 1; i <= N; i++) {
				assert(1 <= col[i] && col[i] <= N);
				ml[i] = LLONG_MAX;
				mr[i] = 0;
			}
			for (int i = 1; i <= N; i++) {
				ml[col[i]] = min(ml[col[i]], i);
				mr[col[i]] = max(mr[col[i]], i);
			}
			vector<ii> vec;
			for (int i = 1; i <= N; i++) {
				if (mr[i]) vec.eb(ml[i], mr[i]);
			}
			cout << vec.size() << '\n';
			for (auto [l, r] : vec) cout << l << ' ' << r << '\n';
		}
	}
}