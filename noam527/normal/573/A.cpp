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
#include <fstream>
#include <random>
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
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int mn = 1e9, mx = -1e9, n, x;

int main() {
	fast;
	cin >> n;
	while (n--) {
		cin >> x;
		while (x % 2 == 0) x /= 2;
		while (x % 3 == 0) x /= 3;
		mn = min(mn, x);
		mx = max(mx, x);
	}
	if (mn == mx) finish("Yes");
	finish("No");
}