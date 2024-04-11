#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <queue>
#define last(x, y) (x)[(x).size() - (y)]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
//const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n;
vector<int> ans;

int digsum(int x) {
	int rtn = 0;
	while (x) rtn += x % 10, x /= 10;
	return rtn;
}

int main() {
	fast;
	cin >> n;
	for (int i = n, lim = max(0, n - 1000); i >= lim; i--) {
		if (i + digsum(i) == n) ans.push_back(i);
	}
	cout << ans.size() << endl;
	for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << endl;
}