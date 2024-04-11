#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define endl "\n"
#define int long long
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;


signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(15);
	int n, m; cin >> n >> m;
	int n2 = n / 2, n1 = n % 2;
	for (; n2 >= 0; n1 += 2, n2--) {
		if ((n1 + n2) % m == 0) {
			cout << n1 + n2; return 0;
		}
	}
	cout << -1;
	return 0;
}