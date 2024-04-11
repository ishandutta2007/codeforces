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

int n, a[5000], x = 1;
ll m[5000][5001];
map<int, int> to;
map<int, int> from;

int calc(int i = 0, int h = 0) {
	if (i == n) return 0;
	if (m[i][h] != -1) return m[i][h];
	if (h >= a[i])
		return m[i][h] = calc(i + 1, a[i]);
	return m[i][h] = min(1 + calc(i + 1, h), from[a[i]] - from[h] + calc(i + 1, a[i]));
}

int main() {
	fast;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i], to[a[i]] = 0;
	for (auto &i : to) i.second = x++;
	for (auto &i : to) from[i.second] = i.first;
	for (int i = 0; i < n; i++) a[i] = to[a[i]];

	for (int i = 0; i < 5000; i++) for (int j = 0; j < 5001; j++) m[i][j] = -1;
	cout << calc() << endl;
}