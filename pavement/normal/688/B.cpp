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

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string S;
	cin >> S;
	string R = S;
	reverse(R.begin(), R.end());
	cout << S + R << '\n';
}