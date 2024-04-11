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
	int n;
	string s;
	cin >> n >> s;
	if (is_sorted(s.begin(), s.end())) cout << "NO\n";
	else {
		cout << "YES\n";
		for (int i = 0; i < s.size() - 1; i++)
			if (s[i] > s[i + 1]) {
				cout << i + 1 << ' ' << i + 2 << '\n';
				return 0;
			}
	}
}