#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
const int md = 1e9 + 7;
//const double pi = acos(-1);
typedef long long ll;
typedef long double ldb;
using namespace std;

void solve(int &n, vector<int> &a) {
	unordered_set<int> d;
	for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) d.insert(a[j] - a[i]);

	int good = 1;
	for (int j; good <= 1000000 / n; good++) {
		for (j = 1; j < n && d.find(good*j) == d.end(); j++);
		if (j == n) break;
	}
	if (good <= 1e6 / n) {
		cout << "YES" << endl;
		for (int i = 1; i <= n; i++) cout << good * i << ' '; cout << endl;
	}
	else cout << "NO" << endl;
}

int main() {
	fast;
	int t, n;
	vector<int> a;
	cin >> t;
	while (t--) {
		cin >> n;
		a.resize(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a.begin(), a.end());
		solve(n, a);
	}
}