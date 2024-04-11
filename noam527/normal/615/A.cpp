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
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 149;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, m, x, y;
set<int> s;

int main() {
	fast;
	cin >> n >> m;
	while (n--) {
		cin >> x;
		while (x--) cin >> y, s.insert(y);
	}
	if (m == s.size()) cout << "YES" << endl;
	else cout << "NO" << endl;
}