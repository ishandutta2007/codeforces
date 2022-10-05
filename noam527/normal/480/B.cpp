#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
const int md = 1e9 + 7;
typedef long long ll;
typedef long double ldb;
using namespace std;

int n, l, x, y, a[200000];
bool b1, b2;

pair<int, int> check(int d, bool b = false) {
	int p1 = 0, p2 = 0;
	while (p2 < n) {
		if (a[p2] - a[p1] == d && (!b || a[p1] - x >= 0 || a[p2] + x <= l)) return{ p1, p2 };
		if (a[p2] - a[p1] < d) p2++;
		else p1++;
	}
	return{ -1, -1 };
}

int main() {
	fast;
	cin >> n >> l >> x >> y;
	for (int i = 0; i < n; i++) cin >> a[i];
	pair<int, int> temp1, temp2;
	temp1 = check(x), temp2 = check(y);
	b1 = (temp1.first != -1 ? true : false);
	b2 = (temp2.first != -1 ? true : false);
	if (b1 || b2) {
		if (b1 && b2) cout << 0 << endl;
		else if (b1) cout << 1 << endl << y << endl;
		else cout << 1 << endl << x << endl;
		return 0;
	}
	temp1 = check(x + y), temp2 = check(y - x, true);
	b1 = (temp1.first != -1 ? true : false);
	b2 = (temp2.first != -1 ? true : false);
	if (b1) {
		cout << 1 << endl << a[temp1.first] + x << endl;
		return 0;
	}
	if (b2) {
		cout << 1 << endl;
		if (a[temp2.first] - x >= 0) cout << a[temp2.first] - x << endl;
		else cout << a[temp2.second] + x << endl;
		return 0;
	}
	cout << 2 << endl << x << " " << y << endl;
	return 0;
}