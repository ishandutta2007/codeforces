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

int N, T, A[500005], P[500005];
map<int, int> M;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i], P[i] = P[i - 1] + A[i];
	if (P[N] + P[1] == 4 * P[1]) M[4 * P[1]]++;
	for (int i = 2; i < N; i++) {
		T += M[2 * P[i]];
		if (P[N] + P[i] == 4 * P[i]) M[4 * P[i]]++;
	}
	cout << T << '\n';
}