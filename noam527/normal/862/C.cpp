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
const long long hs = 149;
//const double pi = acos(-1);
typedef long long ll;
typedef long double ldb;
using namespace std;

int n, x, i = 524288, lim = 1048576;
vector<int> ans;

void finish() {
	cout << "YES" << endl;
	for (auto i : ans) cout << i << " "; cout << endl;
}

int main() {
	fast;
	cin >> n >> x;
	if (n == 2 && x == 0) {
		cout << "NO" << endl;
		return 0;
	}
	if (n == 1) {
		cout << "YES" << endl << x << endl;
		return 0;
	}
	if (n == 2) {
		if (x & 1) cout << "YES" << endl << 1 << " " << x - 1 << endl;
		else cout << "YES" << endl << 1 << " " << x + 1 << endl;
		return 0;
	}
	if (n == 3) {
		cout << "YES" << endl << 262144 << " " << 524288 << " " << x + 262144 + 524288 << endl;
		return 0;
	}
	ans.push_back(x);
	n--;
	while (n > 6) {
		ans.push_back(i);
		ans.push_back(lim - i - 1);
		i++;
		ans.push_back(i);
		ans.push_back(lim - i - 1);
		i++;
		n -= 4;
	}
	if (n == 3) {
		if (x > 3)
			ans.push_back(1), ans.push_back(2), ans.push_back(3);
		else
			ans.push_back(8), ans.push_back(16), ans.push_back(24);
	}
	if (n == 4) {
		ans.push_back(i);
		ans.push_back(lim - i - 1);
		i++;
		ans.push_back(i);
		ans.push_back(lim - i - 1);
		i++;
	}
	if (n == 5) {
		if (x > 15)
			ans.push_back(15), ans.push_back(1), ans.push_back(2), ans.push_back(4), ans.push_back(8);
		else
			ans.push_back(240), ans.push_back(16), ans.push_back(32), ans.push_back(64), ans.push_back(128);
	}
	if (n == 6) {
		if (x > 31)
			ans.push_back(31), ans.push_back(1), ans.push_back(2), ans.push_back(4), ans.push_back(8), ans.push_back(16);
		else
			ans.push_back(992), ans.push_back(32), ans.push_back(64), ans.push_back(128), ans.push_back(256), ans.push_back(512);
	}
	finish();
	return 0;
}