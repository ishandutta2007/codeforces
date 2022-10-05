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

int n, m, mx = -1;
vector<int> a, c[2];
set<int> b[2];

void work(int i, int lim, int w = 0, int to = 0) {
	b[to].insert(w);
	if (i == lim) return;
	work(i + 1, lim, w, to);
	work(i + 1, lim, (w + a[i]) % m, to);
}

int main() {
	fast;
	cin >> n >> m;
	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	if (n == 1) finish(a[0] % m);
	work(0, n / 2, 0, 0);
	work(n / 2, n, 0, 1);

	for (auto &i : b[0]) c[0].push_back(i);
	for (auto &i : b[1]) c[1].push_back(i);

	mx = max(max(mx, c[0].back()), c[1].back());

	int p1 = 0, p2 = c[1].size() - 1;
	while (p1 < c[0].size() && p2 >= 0) {
		if (c[0][p1] + c[1][p2] < m) {
			mx = max(mx, c[0][p1] + c[1][p2]);
			p1++;
		}
		else p2--;
	}
	cout << mx << endl;
}