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
typedef double db;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

string S;
int A, B, curr, pref[1000005], suf[1000005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> S >> A >> B;
	for (int i = 0; i < S.size(); i++) {
		curr *= 10;
		curr += (S[i] - '0');
		curr %= A;
		pref[i] = curr;
	}
	curr = 0;
	for (int i = S.size() - 1, pow = 1; i >= 0; i--) {
		curr += (S[i] - '0') * pow;
		pow *= 10;
		curr %= B;
		pow %= B;
		suf[i] = curr;
	}
	for (int i = 0; i < S.size() - 1; i++) {
		if (pref[i] == 0 && suf[i + 1] == 0 && S[i + 1] != '0') {
			cout << "YES\n";
			for (int j = 0; j <= i; j++) cout << S[j];
			cout << '\n';
			for (int j = i + 1; j < S.size(); j++) cout << S[j];
			cout << '\n';
			return 0;
		}
	}
	cout << "NO\n";
}