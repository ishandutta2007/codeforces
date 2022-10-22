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
	int n, x;
	cin >> n;
	unordered_set <int> s;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		s.insert(x);
	}
	for (int i = 1; i <= 2048; ++i) {
		unordered_set <int> copy;
		for (auto x : s) {
			copy.insert(x ^ i);
		}
		if (copy == s) {
			cout << i << endl; return;
		}
	}
	cout << -1 << endl;


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