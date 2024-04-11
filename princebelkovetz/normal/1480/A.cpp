#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
using namespace std;
#define int long long
#define debug(x) cout << #x << " is " << x << '\n';

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(3);
	int tt; cin >> tt;
	while (tt-- > 0) {
		string s; cin >> s;
		int n = s.size();
		for (int i = 0; i < n; ++i) {
			if (i & 1) cout << (s[i] == 'z' ? 'y' : 'z');
			else cout << (s[i] == 'a' ? 'b' : 'a');
		}
		cout << '\n';
	}
}