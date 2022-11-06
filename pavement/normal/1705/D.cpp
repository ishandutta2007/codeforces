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

int TC, N;
bool A[200005], B[200005];
char S[200005], T[200005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> TC;
	while (TC--) {
		vector<int> vec_1, vec_2;
		cin >> N;
		for (int i = 1; i <= N; i++) cin >> S[i];
		for (int i = 1; i <= N; i++) cin >> T[i];
		if (S[1] != T[1]) {
			cout << "-1\n";
			continue;
		}
		for (int i = 1; i < N; i++) {
			A[i] = S[i] == S[i + 1];
			B[i] = T[i] == T[i + 1];
		}
		for (int i = 1; i < N; i++)
			if (A[i]) vec_1.pb(i);
		for (int i = 1; i < N; i++)
			if (B[i]) vec_2.pb(i);
		if (vec_1.size() != vec_2.size()) cout << "-1\n";
		else {
			int r = 0;
			for (int i = 0; i < vec_1.size(); i++)
				r += llabs(vec_1[i] - vec_2[i]);
			cout << r << '\n';
		}
	}
}