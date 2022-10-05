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
const long long hs = 137;
//const double pi = acos(-1);
typedef long long ll;
typedef long double ldb;
using namespace std;

int x, t, a, b, d1, d2;
vector<int> v1, v2;

int main() {
	fast;
	cin >> x >> t >> a >> b >> d1 >> d2;
	if (x == 0) return cout << "YES" << endl, 0;
	for (int i = 0; i < t; i++) v1.push_back(a - d1 * i), v2.push_back(b - d2 * i);
	for (int i = 0; i < t; i++) for (int j = 0; j < t; j++) {
		if (v1[i] + v2[j] == x || v1[i] == x || v2[j] == x) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
}