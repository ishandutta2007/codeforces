#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#define CHECK cout << "ok" << endl
#define finish(X) return cout << (X) << endl, 0
typedef long long ll;
typedef long double ldb;
const int OO = 1;
const int inf = 1e9 + 7;
const int md = 1e9 + 7;
using namespace std;

struct point {
	ll x, y, r, p;
	point() {}
	point(ll xx, ll yy, ll rr, ll pp) {
		x = xx;
		y = yy;
		r = rr;
		p = pp;
	}
	bool operator < (const point &a) const {
		if (x != a.x) return x < a.x;
		return y < a.y;
	}
};
struct segtree {
	int n;
	vector<ll> tree;
	segtree() {}
	segtree(const vector<point> &a) {
		n = max(2, (int)a.size());
		while (n != (n & -n)) n += (n & -n);
		tree.resize(2 * n, 9e18);
		for (int i = 0; i < a.size(); i++)
			tree[i + n - 1] = a[i].y;
		for (int i = n - 2; i >= 0; i--) fix(i);
	}
	void fix(int x) {
		tree[x] = min(tree[x + x + 1], tree[x + x + 2]);
	}
	void rem(int x) {
		x += n - 1;
		tree[x] = inf;
		x = (x - 1) / 2;
		while (x) {
			fix(x);
			x = (x - 1) / 2;
		}
		fix(0);
	}
	int first(ll upto) {
		int rtn = first(upto, 0, 0, n - 1);
//		cout << "returned rtn " << rtn << " " << tree[rtn + n - 1] << '\n';
		if (tree[rtn + n - 1] <= upto) return rtn;
		return -1;
	}
	int first(int upto, int node, int nl, int nr) {
//		cout << "upto node nl nr " << upto << " " << node << " " << nl << " " << nr << '\n';
		if (nl == nr) return nl;
		int mid = (nl + nr) / 2;
		if (tree[2 * node + 1] <= upto) return first(upto, 2 * node + 1, nl, mid);
		return first(upto, 2 * node + 2, mid + 1, nr);
	}
};

int n, r, p;
vector<point> a;
segtree T;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	ll tx, ty;
	cin >> tx >> ty >> p >> r >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		ll pa[5];
		for (int j = 0; j < 5; j++) cin >> pa[j];
		pa[0] -= tx;
		pa[1] -= ty;
		a[i] = point(ceill(sqrtl((ll)pa[0] * pa[0] + (ll)pa[1] * pa[1])), pa[2], pa[4], pa[3]);
	}
	sort(a.begin(), a.end());
	T = segtree(a);
	vector<pair<ll, ll>> q;
	q.push_back({ r, p });
	int nxt = 0;
	while (nxt < q.size()) {
		pair<ll, ll> x = q[nxt++];
		int i;
		i = T.first(x.second);
		while (i != -1 && a[i].x <= x.first) {
			T.rem(i);
			q.push_back({ a[i].r, a[i].p });
			i = T.first(x.second);
		}
	}
	cout << q.size() - 1 << '\n';

	cin.ignore();
	cin.get();
}