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

int ask(int i, int j) {
	cout << "? " << i << " " << j << endl;
	flush;
	int temp;
	cin >> temp;
	return temp;
}

int cnt = 0, at = 0, n;
vector<int> a, b, c, d;

bool check() {
	for (int i = 0; i < n; i++)
		if (c[i] >= n || d[i] >= n || c[d[i]] != i) return false;
	return true;
}

int main() {
	fast;
	cin >> n;
	c.resize(n), d.resize(n);
	for (int i = 0; i < n; i++) a.push_back(ask(0, i)), b.push_back(ask(i, 0));
	for (int i = 0; i < n; i++) {
		c[0] = i;
		for (int j = 0; j < n; j++) d[j] = c[0] ^ a[j], c[j] = d[0] ^ b[j];
		if (check()) cnt++, at = i;
	}
	cout << '!' << endl;
	cout << cnt << endl;
	c[0] = at;
	for (int i = 0; i < n; i++) d[i] = c[0] ^ a[i], c[i] = d[0] ^ b[i];
	for (auto &i : c) cout << i << " "; cout << endl;
}