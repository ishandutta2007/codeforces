#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define mt make_tuple
typedef long double ld;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x, y, z;
	cin >> x >> y >> z;
	if (x == y + z && y == x + z) cout << "0\n";
	else if (x <= y + z && y <= x + z) cout << "?\n";
	else if (x < y + z) cout << "-\n";
	else cout << "+\n";
}