#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef TEST
#define getchar_unlocked _getchar_nolock
#endif
#define int long long
#define ins insert
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define pp pop
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define g0(a) get<0>(a)
#define g1(a) get<1>(a)
#define g2(a) get<2>(a)
#define g3(a) get<3>(a)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef double db;
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

bitset<2800000> bs;
vector<int> vec;
int N, K, idx;

main() {
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; i <= 2800000; i++)
		if (bs[i]) {
			vec.pb(i);
			if (vec.size() >= 200000) break;
			for (int j = i + i; j <= 2800000; j += i) bs[j] = 0;
		}
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	if (N == 1) {
		if (K == 0) cout << "1\n";
		else cout << "-1\n";
		return 0;
	}
	K -= N / 2 - 1;
	if (K <= 0) return cout << "-1\n", 0;
	for (int cnt = 0; cnt < N - (N & 1) - 2; cnt++) {
		while (vec[idx] == K || vec[idx] == 2 * K) idx++;
		cout << vec[idx++] << ' ';
	}
	cout << K << ' ' << 2 * K << ' ';
	if (N & 1) {
		while (vec[idx] == K || vec[idx] == 2 * K) idx++;
		cout << vec[idx] << ' ';
	}
	cout << '\n';
}