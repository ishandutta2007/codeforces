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

int A, B, S;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> A >> B >> S;
	int D = llabs(A) + llabs(B);
	if (S < D || (S - D) & 1) cout << "No\n";
	else cout << "Yes\n";
}