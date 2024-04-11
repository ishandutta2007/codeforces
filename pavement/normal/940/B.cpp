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

int N, K, A, B, C;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K >> A >> B;
	if (K == 1) {
		cout << (N - 1) * A << '\n';
		return 0;
	}
	while (N != 1) {
		int X = (N / K + 1) * K;
		X -= K;
		if (X <= 0) {
			C += (N - 1) * A;
			break;
		}
		C += (N - X) * A;
		N = X;
		if ((N - X / K) * A <= B) C += (N - X / K) * A;
		else C += B;
		N = X / K;
	}
	cout << C << '\n';
}