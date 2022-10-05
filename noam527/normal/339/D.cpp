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

int n, m, a[200000];

struct sometree {
	int *lo, *hi, val, lvl, *mid;
	sometree *l = 0, *r = 0;
	void fix() {
		if (lvl & 1) val = (l->val | r->val);
		else val = (l->val ^ r->val);
	}
	sometree(int *st, int *en, int dis) {
		lo = st, hi = en, mid = lo + dis / 2;
		if (dis == 1) {
			val = *lo, lvl = 0;
			return;
		}
		l = new sometree(st, mid, dis / 2), r = new sometree(mid, en, dis / 2);
		lvl = l->lvl + 1;
		fix();
	}
	void update(int *at, int v) {
		if (!lvl) {
			val = v;
			return;
		}
		if (at < mid) l->update(at, v);
		else r->update(at, v);
		fix();
	}
	void print() {
		if (!lvl) {
			cout << val << endl;
			return;
		}
		l->print(), cout << val << endl, r->print();
	}
};

int main() {
	fast;
	cin >> n >> m;
	for (int i = 0, lim = (1 << n); i < lim; i++) cin >> a[i];
	sometree t = sometree(a, a + (1 << n), (1 << n));
	for (int i = 0, p, b; i < m; i++) {
		cin >> p >> b;
		t.update(a + p - 1, b);
		cout << t.val << endl;
	}
}