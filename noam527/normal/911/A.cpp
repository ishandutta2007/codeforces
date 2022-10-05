#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <stack>
#include <queue>
#include <random>
#include <fstream>
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int mn = 1e9 + 5, lst = 0, n, x, ans = 1e9;

int main() {
	fast;
	cin >> n;
	while (n--) {
		cin >> x;
		if (x == mn) ans = min(ans, lst - n), lst = n;
		if (x < mn) ans = 1e9, lst = n, mn = x;
	}
	cout << ans << endl;
}