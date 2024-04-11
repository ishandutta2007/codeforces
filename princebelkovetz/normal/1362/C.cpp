#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <unordered_set>
#include <queue>
#define int long long
#define endl "\n";
using namespace std;

void solve(){
	int n, ans = 0, cur = 1;
	cin >> n;
	while (n) {
		ans += cur * (n / 2 + n % 2);
		n /= 2;
		cur++;
	}
	cout << ans << endl;


}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(15);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}