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
typedef long long ll;
typedef long double ldb;
using namespace std;

ll l, r, x, y, k;

int main() {
	fast;
	cin >> l >> r >> x >> y >> k;
	for (int i = x; i <= y; i++) {
		if (i * k >= l && i * k <= r) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
}