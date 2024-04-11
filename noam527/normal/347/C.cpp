#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
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

int n, g = 0, mx = -1;

int gcd(int x, int y) {
	return y == 0 ? x : gcd(y, x % y);
}

int main() {
	fast;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i], g = gcd(g, a[i]), mx = max(mx, a[i]);
	if ((mx / g - n) & 1) cout << "Alice" << endl;
	else cout << "Bob" << endl;
}