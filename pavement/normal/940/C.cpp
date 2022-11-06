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
typedef long double ld;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, K, pos;
string S;
set<char> T;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K >> S;
	for (char &c : S) T.insert(c);
	if (N < K) {
		cout << S;
		for (int i = N; i < K; i++) cout << *T.begin();
		cout << '\n';
		return 0;
	}
	for (int i = K - 1; i >= 0; i--)
		if (S[i] != *T.rbegin()) {
			pos = i;
			break;
		}
	for (int i = 0; i < pos; i++) cout << S[i];
	cout << *T.upper_bound(S[pos]);
	for (int i = pos + 1; i < K; i++) cout << *T.begin();
	cout << '\n';
}