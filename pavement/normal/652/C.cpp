#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
typedef long double ld;

int N, M, T, P[300005], U[300005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1, tmp; i <= N; i++) {
		cin >> tmp;
		P[tmp] = i;
	}
	for (int a, b; M--; ) {
		cin >> a >> b;
		if (P[a] > P[b]) swap(a, b);
		U[P[b]] = U[P[b]] ? max(U[P[b]], P[a]) : P[a];
	}
	for (int i = 1, l = 0; i <= N; i++) {
		l = max(l, U[i]);
		T += i - l;
	}
	cout << T << '\n';
}