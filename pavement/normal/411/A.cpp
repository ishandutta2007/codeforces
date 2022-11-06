#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
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
typedef long double ld;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

string S;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> S;
	if (S.size() < 5) return cout << "Too weak\n", 0;
	bool u = 0, l = 0, d = 0;
	for (char c : S) {
		if (isupper(c)) u = 1;
		else if (islower(c)) l = 1;
		else if ('0' <= c && c <= '9') d = 1;
	}
	cout << (u && l && d ? "Correct" : "Too weak") << '\n';
}