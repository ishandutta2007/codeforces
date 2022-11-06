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

int N, A, C, T[105];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> A;
	for (int i = 1; i <= N; i++) cin >> T[i];
	for (int l = A, r = A; l >= 1 || r <= N; ) {
		if (l < 1 && T[r]) C++;
		else if (r > N && T[l]) C++;
		else if (T[r] && T[l]) C += (l == r ? 1 : 2);
 		l--;
		r++;
	}
	cout << C << '\n';
}