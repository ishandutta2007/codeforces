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

int n;

int main() {
	fast;
	cin >> n;
	if (n < 3) {
		cout << 1 << endl << 1 << endl;
		return 0;
	}
	if (n == 3) {
		cout << 2 << endl << "1 3" << endl;
		return 0;
	}
	cout << n << endl;
	for (int i = 2; i <= n; i += 2) cout << i << " ";
	for (int i = 1; i <= n; i += 2) cout << i << " ";
}