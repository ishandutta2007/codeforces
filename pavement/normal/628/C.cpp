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

int N, X[100005], K[100005], P[100005], S[100005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, K, OK;
	string S, T;
	cin >> N >> K >> S;
	OK = K;
	for (int i = 0; i < S.size(); i++) {
		int mx = max(S[i] - 'a', 'z' - S[i]);
		if (K >= mx) {
			if (S[i] - 'a' >= mx) T.pb(S[i] - mx);
			else T.pb(S[i] + mx);
			K -= mx;
		} else {
			if (S[i] - 'a' >= K) T.pb(S[i] - K);
			else T.pb(S[i] + K);
			K = 0;
		}
	}
	if (T.size() != S.size()) return cout << "-1\n", 0;
	for (int i = 0; i < T.size(); i++)
		OK -= abs(T[i] - 'a' - S[i] + 'a');
	if (OK == 0) cout << T << '\n';
	else cout << "-1\n";
}