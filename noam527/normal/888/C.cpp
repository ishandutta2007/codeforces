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

int n, a[256] = {}, mx[256] = {};
string s;

int main() {
	fast;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < 256; j++) mx[j] = max(mx[j], i + 1 - a[j]);
		a[s[i]] = i + 1;
	}
	for (int j = 0; j < 256; j++) mx[j] = max(mx[j], (int)s.size() + 1 - a[j]);
	int ans = 1e9;
	for (int i = 0; i < 256; i++) ans = min(ans, mx[i]);
	cout << ans << endl;
}