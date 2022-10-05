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

int main() {
	fast;
	int n;
	cin >> n;
	if (n < 4) return cout << "NO" << endl, 0;
	cout << "YES" << endl;
	int cnt = 0;
	while (n > 7) {
		cout << n << " + " << n - 3 << " = " << n + n - 3 << endl;
		cout << n - 1 << " + " << n - 2 << " = " << n + n - 3 << endl;
		cout << 2 * n - 3 << " - " << 2 * n - 3 << " = " << 0 << endl;
		cnt++;
		n -= 4;
	}
	if (n == 4)
		cout << "1 * 2 = 2" << endl << "2 * 3 = 6" << endl << "6 * 4 = 24" << endl;
	if (n == 5)
		cout << "2 * 4 = 8" << endl << "3 * 5 = 15" << endl << "1 + 8 = 9" << endl << "9 + 15 = 24" << endl;
	if (n == 6)
		cout << "2 * 3 = 6" << endl << "6 * 4 = 24" << endl << "24 + 6 = 30" << endl << "30 - 1 = 29" << endl << "29 - 5 = 24" << endl;
	if (n == 7)
		cout << "1 + 3 = 4" << endl << "4 + 4 = 8" << endl << "8 + 5 = 13" << endl << "13 + 6 = 19" << endl << "19 + 7 = 26" << endl << "26 - 2 = 24" << endl;
	while (cnt--) cout << "24 - 0 = 24" << endl;
}