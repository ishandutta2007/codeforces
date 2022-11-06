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

int T, N, A[105];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		bool o = 0, e = 0;
		cin >> N;
		for (int i = 1; i <= N; i++){
			cin >> A[i];
			if (A[i] & 1) o = 1;
			else e = 1;
		}
		if (o && e) cout << "NO\n";
		else cout << "YES\n";
	}
}