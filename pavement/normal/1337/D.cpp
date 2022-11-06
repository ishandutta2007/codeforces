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
typedef long double ld;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int T, NR, NG, NB;
int R[100005], B[100005], G[100005];

int f(int a, int b, int c) {
	return (a - b) * (a - b) + (b - c) * (b - c) + (a - c) * (a - c);
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		int Y = LLONG_MAX;
		cin >> NR >> NG >> NB;
		for (int i = 1; i <= NR; i++) cin >> R[i];
		for (int i = 1; i <= NG; i++) cin >> G[i];
		for (int i = 1; i <= NB; i++) cin >> B[i];
		sort(R + 1, R + 1 + NR);
		sort(G + 1, G + 1 + NG);
		sort(B + 1, B + 1 + NB);
		// try G -> R
		for (int i = NR; i >= 1; i--) {
			auto it2 = upper_bound(B + 1, B + 1 + NB, R[i]);
			if (it2 == B + 1) continue;
			--it2;
			auto it = upper_bound(G + 1, G + 1 + NG, *it2);
			if (it == G + 1) continue;
			--it;
			auto it3 = lower_bound(B + 1, B + 1 + NB, (*it + R[i]) / 2);
			auto it4 = it3;
			if (it3 != B + 1) it4--;
			if (it4 != B + 1 + NB) Y = min(Y, f(R[i], *it, *it4));
			if (it3 != B + 1 + NB) Y = min(Y, f(R[i], *it, *it3));
		}
		// try R -> G
		for (int i = NG; i >= 1; i--) {
			auto it2 = upper_bound(B + 1, B + 1 + NB, G[i]);
			if (it2 == B + 1) continue;
			--it2;
			auto it = upper_bound(R + 1, R + 1 + NR, *it2);
			if (it == R + 1) continue;
			--it;
			auto it3 = lower_bound(B + 1, B + 1 + NB, (*it + G[i]) / 2);
			auto it4 = it3;
			if (it3 != B + 1) it4--;
			if (it4 != B + 1 + NB) Y = min(Y, f(G[i], *it, *it4));
			if (it3 != B + 1 + NB) Y = min(Y, f(G[i], *it, *it3));
		}
		// try B -> R
		for (int i = NR; i >= 1; i--) {
			auto it2 = upper_bound(G + 1, G + 1 + NG, R[i]);
			if (it2 == G + 1) continue;
			--it2;
			auto it = upper_bound(B + 1, B + 1 + NB, *it2);
			if (it == B + 1) continue;
			--it;
			auto it3 = lower_bound(G + 1, G + 1 + NG, (*it + R[i]) / 2);
			auto it4 = it3;
			if (it3 != G + 1) it4--;
			if (it4 != G + 1 + NG) Y = min(Y, f(R[i], *it, *it4));
			if (it3 != G + 1 + NG) Y = min(Y, f(R[i], *it, *it3));
		}
		// try R -> B
		for (int i = NB; i >= 1; i--) {
			auto it2 = upper_bound(G + 1, G + 1 + NG, B[i]);
			if (it2 == G + 1) continue;
			--it2;
			auto it = upper_bound(R + 1, R + 1 + NR, *it2);
			if (it == R + 1) continue;
			--it;
			auto it3 = lower_bound(G + 1, G + 1 + NG, (*it + B[i]) / 2);
			auto it4 = it3;
			if (it3 != G + 1) it4--;
			if (it4 != G + 1 + NG) Y = min(Y, f(B[i], *it, *it4));
			if (it3 != G + 1 + NG) Y = min(Y, f(B[i], *it, *it3));
		}
		// try G -> B
		for (int i = NB; i >= 1; i--) {
			auto it2 = upper_bound(R + 1, R + 1 + NR, B[i]);
			if (it2 == R + 1) continue;
			--it2;
			auto it = upper_bound(G + 1, G + 1 + NG, *it2);
			if (it == G + 1) continue;
			--it;
			auto it3 = lower_bound(R + 1, R + 1 + NR, (*it + B[i]) / 2);
			auto it4 = it3;
			if (it3 != R + 1) it4--;
			if (it4 != R + 1 + NR) Y = min(Y, f(B[i], *it, *it4));
			if (it3 != R + 1 + NR) Y = min(Y, f(B[i], *it, *it3));
		}
		// try B -> G
		for (int i = NG; i >= 1; i--) {
			auto it2 = upper_bound(R + 1, R + 1 + NR, G[i]);
			if (it2 == R + 1) continue;
			--it2;
			auto it = upper_bound(B + 1, B + 1 + NB, *it2);
			if (it == B + 1) continue;
			--it;
			auto it3 = lower_bound(R + 1, R + 1 + NR, (*it + G[i]) / 2);
			auto it4 = it3;
			if (it3 != R + 1) it4--;
			if (it4 != R + 1 + NR) Y = min(Y, f(G[i], *it, *it4));
			if (it3 != R + 1 + NR) Y = min(Y, f(G[i], *it, *it3));
		}
		cout << Y << '\n';
	}
}