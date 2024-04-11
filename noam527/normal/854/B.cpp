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
const double pi = acos(-1);
typedef long long ll;
typedef long double ldb;
using namespace std;

int n, k;

int main() {
	fast;
	cin >> n >> k;
	if (k == 0 || k == n) {
		cout << "0 0" << endl;
		return 0;
	}
	cout << "1 ";
	if (k <= n / 3) return cout << 2 * k << endl, 0;
	cout << 2 * (n / 3) - (k - n / 3) + (n % 3) << endl;
	return 0;
	if (n % 3 == 0) return cout << 2 * (n / 3) - (k - n / 3) << endl, 0;
	if (n % 3 == 1) return cout << 2 * (n / 3) - (k - n / 3) + 1 << endl, 0;

}