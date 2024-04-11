#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <set>
#include <unordered_set>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 3e5;
int n;
int a[sz], cnts[32];


void solve() {
	vector<vector<int>> ret;
	if (n == 3) {
		cout << "1\n1 2 3\n";
		return;
	}
	int i = n - 3;
	while (i >= 4) {
		ret.pb({ i,i + 1,i + 2 });
		i -= 2;
	}
	ret.pb({ 0,1,2 });
	ret.pb({ 2,3,4 });
	ret.pb({ 0,1,2 });
	i = 4;
	while (i + 1 < n) {
		ret.pb({ i,i + 1,i + 2 });
		i += 2;
	}
	cout << ret.size() << '\n';
	for (vector<int> v : ret) {
		for (int x : v)cout << x + 1 << ' ';
		cout << '\n';
	}
}

int main() {
	fast;
	cin >> n;
	foru(i, 0, n) {
		cin >> a[i];
		foru(j, 0, 31)cnts[j] += ((a[i] >> j) & 1);
	}
	bool flag = 0;
	foru(i, 1, n) {
		if (a[i] != a[i - 1]) {
			flag = 1;
			break;
		}
	}
	if (not flag) {
		cout << "YES\n0\n";
		return 0;
	}
	else if (n & 1) {
		cout << "YES\n";
		solve();
	}
	else {
		foru(j, 0, 32) {
			if (cnts[j] & 1) {
				cout << "NO\n";
				return 0;
			}
		}
		cout << "YES\n";
		n--;
		foru(j, 0, 32)cnts[j] -= ((a[n] >> j) & 1);
		solve();
	}
	return 0;
}