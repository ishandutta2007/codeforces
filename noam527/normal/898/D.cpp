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
#define last(x, y) (x)[(x).size() - (y)]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9;
const ll hs = 199;
//const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

struct fenwick {
	int n;
	vector<int> a;
	fenwick(int size) {
		n = size;
		a.resize(n + 1, 0);
	}
	void set(int x) {
		for (; x <= n; x += (x & -x)) a[x]++;
	}
	void unset(int x) {
		for (; x <= n; x += (x & -x)) a[x]--;
	}
	int query(int x) {
		int ans = 0;
		for (; x > 0; x -= (x & -x)) ans += a[x];
		return ans;
	}
	// (l, r]
	int query(int l, int r) {
		return query(r) - query(l);
	}
};

int n, m, k, a[200002], ans = 0;

int main() {
	fast;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	
	fenwick f = fenwick(1e6);
	for (int i = 0; i < n; i++) f.set(a[i]);

	int p;
	for (int i = 0, rtn; i < n; i++) {
		p = i;
		rtn = f.query(a[i] - m, a[i]);
		for (; rtn >= k; rtn--)
			f.unset(a[p]), a[p--] = 0, ans++;
	}
	cout << ans << endl;
}