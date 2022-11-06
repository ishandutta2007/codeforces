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
#define g4(a) get<4>(a)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using db = double;
using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using iiii = tuple<int, int, int, int>;
template<class key, class value = null_type, class cmp = less<key> >
using ordered_set = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

int N, Q, A[200005], OA[200005];
vector<int> nz;
map<int, vector<int> > pos[2];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		OA[i] = A[i];
		A[i] ^= A[i - 1];
		pos[i & 1][A[i]].pb(i);
		if (OA[i]) nz.pb(i);
	}
	for (int i = 1, l, r; i <= Q; i++) {
		cin >> l >> r;
		auto tmp = lower_bound(nz.begin(), nz.end(), l);
		if (tmp == nz.end() || *tmp > r) cout << "0\n";
		else if (r - l + 1 == 2) cout << "-1\n";
		else if (A[r] != A[l - 1]) cout << "-1\n";
		else {
			if ((r - l + 1) & 1) cout << "1\n";
			else {
				if (OA[l] == 0 || OA[r] == 0) cout << "1\n";
				else {
					auto it = upper_bound(pos[r & 1 ^ 1][A[r]].begin(), pos[r & 1 ^ 1][A[r]].end(), l - 1);
					if (it != pos[r & 1 ^ 1][A[r]].end() && *it < r) cout << "2\n";
					else cout << "-1\n";
				}
			}
		}
	}
}