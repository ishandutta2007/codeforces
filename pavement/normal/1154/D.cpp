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

int N, B, A, S[200005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> B >> A;
	int cura = A;
	for (int i = 1; i <= N; i++) {
		cin >> S[i];
		if (S[i]) {
			if (B > 0 && cura < A) B--, cura = min(A, cura + 1);
			else if (cura > 0) cura--;
			else if (B > 0) B--;
			else return cout << i - 1 << '\n', 0;
		} else {
			if (cura > 0) cura--;
			else if (B > 0) B--;
			else return cout << i - 1 << '\n', 0;
		}
		if (cura < 0 || B < 0) return cout << i - 1 << '\n', 0;
	}
	cout << N << '\n';
}