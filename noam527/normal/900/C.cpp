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

struct fenwick {
	int n;
	vector<int> a;
	fenwick(int size) {
		n = size;
		a.resize(n + 1, 0);
	}
	void upd(int x) {
		for (; x <= n; x += (x & -x)) a[x]++;
	}
	int query(int x) {
		int ans = 0;
		for (; x; x -= (x & -x)) ans += a[x];
		return ans;
	}
};

int n, a[100001], is[100001] = {}, val[100001] = {}, ans = 0;

int main() {
	fast;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	fenwick f = fenwick(n);

	int mx[2] = { -1, -1 };
	for (int i = 0; i < n; i++) {
		if (a[i] > mx[1]) ans++, is[a[i]] = 1, mx[0] = mx[1], mx[1] = a[i];
		else if (a[i] > mx[0])
			val[mx[1]]++, mx[0] = a[i];
	}
	int rtn = -1, v = -1;
	for (int i = 1; i <= n; i++) {
		if (ans - is[i] + val[i] > rtn) rtn = ans - is[i] + val[i], v = i;
	}
	cout << v << endl;
}