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

int A1, A2, A3, B1, B2, B3, A, B, N;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> A1 >> A2 >> A3 >> B1 >> B2 >> B3 >> N;
	A = A1 + A2 + A3;
	B = B1 + B2 + B3;
	if ((A + 4) / 5 + (B + 9) / 10 <= N) cout << "YES\n";
	else cout << "NO\n";
}