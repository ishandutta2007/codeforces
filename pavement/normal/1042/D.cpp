#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define mt make_tuple
#define mp make_pair
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, T, U, A[200005], P[200005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> T;
	for (int i = 1; i <= N; i++) cin >> A[i], P[i] = A[i] + P[i - 1];
	ordered_set o;
	o.insert(0);
	for (int i = 1; i <= N; i++) {
		U += o.order_of_key(T - P[i]);
		o.insert(-P[i]);
	}
	cout << U << '\n';
}