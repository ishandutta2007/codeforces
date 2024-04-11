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
using ordered_set = tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update>;

int T, N;
deque<int> D;
vector<ii> op;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		op.clear();
		D.clear();
		bool inv = 0;
		map<int, int> cnt;
		cin >> N;
		for (int i = 1, A; i <= N; i++) {
			cin >> A;
			cnt[A]++;
			D.pb(A);
		}
		for (auto i : cnt)
			if (i.second & 1) inv = 1;
		if (inv) {
			cout << "-1\n";
			continue;
		}
		int bef = 0, prv = 0;
		vector<int> tt;
		while (!D.empty()) {
			vector<int> tmp;
			int x = D.front();
			D.pop_front();
			while (D.front() != x) {
				tmp.pb(D.front());
				D.pop_front();
			}
			int tmpp = bef;
			for (int i : tmp)
				op.eb(tmpp++ + tmp.size() + 2, i);
			D.pop_front();
			for (int i : tmp)
				D.push_front(i);
			bef += (tmp.size() + 1) * 2;
			tt.pb(bef - prv);
			prv = bef;
		}
		cout << op.size() << '\n';
		for (auto [a, b] : op) cout << a << ' ' << b << '\n';
		cout << tt.size() << '\n';
		for (int i : tt) cout << i << ' ';
		cout << '\n';
	}
}