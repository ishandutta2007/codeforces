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
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, k, cnt = 0;
queue<pair<int, int>> q;

int count(vector<int> &a, int st, int en) {
	bool good = true;
	for (int i = st + 1; i < en; i++) if (a[i] < a[i - 1]) good = false;
	if (good) return 0;

	int md = (st + en) / 2;
	return 2 + count(a, st, md) + count(a, md, en);
}

int main() {
	fast;
	cin >> n >> k;
	if (k % 2 == 0) finish(-1);
	k--;

	q.push({ 0, n });
	vector<int> a(n - 1, 1);
	while (k && q.size()) {
		pair<int, int> x = q.front(); q.pop();

		int md = (x.first + x.second) / 2;
		if (md && x.first + 1 < x.second) {
			a[md - 1] = 0, q.push({ x.first, md }), q.push({ md, x.second });
			k -= 2, cnt++;
		}
	}
	if (k) finish(-1);
//	for (auto &i : a) cout << i << " "; cout << endl;

	int p1 = cnt, p2 = cnt + 1;

	vector<int> ans(n);
	ans[0] = p2++;
	for (int i = 1; i < n; i++) {
		if (a[i - 1]) ans[i] = p2++;
		else ans[i] = p1--;
	}
	for (auto &i : ans) cout << i << " "; cout << endl;
}