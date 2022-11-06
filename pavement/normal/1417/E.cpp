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
typedef double db;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int RANDOM = rng();
struct chash {
    int operator()(int x) const { return x ^ RANDOM; }
};

int N, x, A[300005];
ll ans;
gp_hash_table<int, int, chash> cnt0, cnt1;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int k = 0; k <= 30; k++) {
		cnt0.clear();
		cnt1.clear();
		ll inv = 0, invflip = 0;
		for (int i = 1; i <= N; i++) {
			if (A[i] & 1) invflip += cnt0[A[i] >> 1];
			else inv += cnt1[A[i] >> 1];
			if (A[i] & 1) cnt1[A[i] >> 1]++;
			else cnt0[A[i] >> 1]++;
		}
		if (inv > invflip) x |= (1 << k);
		ans += min(inv, invflip);
		for (int i = 1; i <= N; i++) A[i] >>= 1;
	}
	cout << ans << ' ' << x << '\n';
}