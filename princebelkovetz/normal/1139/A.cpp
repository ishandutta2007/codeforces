#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
//#define int long long
#define endl "\n";
using namespace std;

void solve(){
	int n, ans = 0; string s;
	cin >> n >> s;
	for (int i = 0; i < n; ++i) {
		if ((int)s[i] % 2 == 0) {
			ans += i + 1;
		}
	}
	cout << ans;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(15);
	int t = 1;
	while (t--) {
		solve();
	}
	return 0;
}