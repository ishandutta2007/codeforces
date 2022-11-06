#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#endif
//#define int long long
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

#include <bits/functexcept.h>
#include <iosfwd>
#include <bits/cxxabi_forced.h>
#include <bits/functional_hash.h>

#pragma push_macro("__SIZEOF_LONG__")
#pragma push_macro("__cplusplus")
#define __SIZEOF_LONG__ __SIZEOF_LONG_LONG__
#define unsigned unsigned long
#define __cplusplus 201102L

#define __builtin_popcountl __builtin_popcountll
#define __builtin_ctzl __builtin_ctzll

#include <bitset>

#pragma pop_macro("__cplusplus")
#pragma pop_macro("__SIZEOF_LONG__")
#undef unsigned
#undef __builtin_popcountl
#undef __builtin_ctzl

const int BS = 350;
int N, M, ans = INT_MAX, mpp2[500005], X[500005][5], W[500005], rev[500005], mpp[500005], cnt[500005];
ii T[500005];
bitset<100005> tmp;
vector<bitset<100005> > B;
vector<int> bigs, disc, pos[500005];

main() {
	memset(mpp2, -1, sizeof mpp2);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> X[i][j];
			disc.pb(X[i][j]);
		}
		cin >> W[i];
		T[i] = mp(W[i], i);
	}
	sort(disc.begin(), disc.end());
	disc.erase(unique(disc.begin(), disc.end()), disc.end());
	sort(T + 1, T + 1 + N);
	for (int i = 1; i <= N; i++) {
		mpp[T[i].second] = i;
		rev[i] = T[i].second;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			X[i][j] = lower_bound(disc.begin(), disc.end(), X[i][j]) - disc.begin() + 1;
			cnt[X[i][j]]++;
		}
	}
	int cnt2 = 0;
	for (int i = 1; i <= disc.size(); i++)
		if (cnt[i] > BS) {
			bigs.pb(i);
			mpp2[i] = cnt2++;
		}
	B.resize(bigs.size());
	for (int i = 0; i < bigs.size(); i++) B[i].set();
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			if (cnt[X[i][j]] > BS) B[mpp2[X[i][j]]][mpp[i]] = 0;
			else pos[X[i][j]].pb(mpp[i]);
	for (int i = 1; i <= N; i++) {
		tmp.set();
		for (int j = 1; j <= M; j++)
			if (mpp2[X[i][j]] != -1) tmp &= B[mpp2[X[i][j]]];
			else {
				for (int k : pos[X[i][j]])
					tmp[k] = 0;
			}
		int tmp2 = tmp._Find_next(0);
		if (rev[tmp2]) ans = min(ans, W[i] + W[rev[tmp2]]);
	}
	cout << (ans == INT_MAX ? -1 : ans) << '\n';
}