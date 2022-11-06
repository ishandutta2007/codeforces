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

int N, A[100005], S[100005], dp[100005];
map<int, int> M;

vector<int> fac(int X) {
	vector<int> r;
	while (X != 1) {
		r.pb(S[X]);
		X /= S[X];
	}
	return r;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= 1e5; i++) S[i] = i;
	for (int i = 4; i <= 1e5; i += 2) S[i] = 2;
	for (int i = 3; i * i <= 1e5; i += 2)
		if (S[i] == i)
			for (int j = i * i; j <= 1e5; j += i)
				if (S[j] == j) S[j] = i;
	for (int i = 1; i <= N; i++) {
		dp[i] = 1;
		auto v = fac(A[i]);
		for (int j : v)
			dp[i] = max(dp[i], M[j] + 1);
		for (int j : v)
			M[j] = max(M[j], dp[i]);
	}
	cout << *max_element(dp + 1, dp + 1 + N) << '\n';
}