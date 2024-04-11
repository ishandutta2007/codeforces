#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#define int long long
#define endl "\n";
using namespace std;
long long md(long long x, long long mod) {
	return ((x % mod) + mod) % mod;
}
long long sub(long long x, long long y, long long mod) {
	return md(md(x, mod) - md(y, mod), mod);
}
int power(int n, int x, int m) {
	if (x % 2 == 1) return (n * power(n, x - 1, m)) % m;
	if (x == 0) return 1;
	int t = power(n, x / 2, m) % m;
	return(t * t) % m;
}
long long add(long long x, long long y, long long mod) {
	return md(md(x, mod) + md(y, mod), mod);
}
void solve(){
	string s;
	int n; cin >> n;
	getline(cin, s);
	getline(cin, s);
	int cnt1 = 0, cnt2 = 0, cur = 0, ans = 0;
	for (auto x : s) {
		if (x == ')') cnt1++;
		else cnt2++;
	}
	if (cnt1 - cnt2) {
		cout << -1; return;
	}
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '(') cur++;
		else cur--;
		if (cur < 0 or cur == 0 and s[i] == '(') ans++;
	}
	cout << ans;

}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(15);
	int t;
	t = 1;
	while (t--) {
		solve();
	}
	return 0;
}