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
#define finish return cout << "NO" << endl, 0
#define all(X) (X).begin(), (X).end()
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

struct node {
	int val, x, y;
	node(int _v = -1, int _x = -1, int _y = -1) {
		val = _v, x = _x, y = _y;
	}
};

struct query {
	int t, x, y;
	query(int _t = 0, int _x = 0, int _y = 0) : t(_t), x(_x), y(_y) {};
};

struct segtree {
	int n;
	vector<node> tree;
	segtree(int size) {
		n = size;
		tree.resize(2 * n, -1);
	}
	void fix(int x) { tree[x].val = max(tree[2 * x + 1].val, tree[2 * x + 2].val); }
	void insert(int i, node a) {
		i += n - 1;
		tree[i] = a;
		for (i = (i - 1) / 2; i; i = (i - 1) / 2) fix(i);
		fix(0);
	}
	void erase(int i) {
		i += n - 1;
		tree[i] = node();
		for (i = (i - 1) / 2; i; i = (i - 1) / 2) fix(i);
		fix(0);
	}
	int query(int l, int r) {
		int rtn = -2e9;
		for (l += n - 1, r += n - 1; l < r; l = (l - 1) / 2, r = (r - 1) / 2) {
			if (!(l & 1)) rtn = max(rtn, tree[l++].val);
			if (r & 1) rtn = max(rtn, tree[r--].val);
		}
		if (l == r) rtn = max(rtn, tree[l].val);
		return rtn;
	}
	pair<int, int> bs(int st, int x) {
		int lo = st, hi = n - 1, mid;
//		cout << "st " << lo << " hi " << hi << " x " << x << endl;
		while (lo < hi) {
			mid = lo + (hi - lo) / 2;
//			cout << "the query from " << st << " to " << mid << " returns " << query(st, mid) << endl;
			if (query(st, mid) > x) hi = mid;
			else lo = mid + 1;
		}
		if (query(st, lo) <= x) return{ -1, -1 };
		return{ tree[lo + n - 1].x, tree[lo + n - 1].y };
	}
};

string temp;
int n, p1, p2;
map<pair<int, int>, int> m;
vector<query> q;
vector<int> stfrom;

int main() {
	fast;
	cin >> n;
	q.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> temp >> p1 >> p2;
		if (temp[0] == 'a') q[i] = query(0, p1, p2);
		else if (temp[0] == 'r') q[i] = query(1, p1, p2);
		else q[i] = query(2, p1, p2);
		if (q[i].t != 2) m[{p1, p2}] = -1;
	}
	if (m.size() == 0) {
		while (n--) cout << -1 << endl;
		return 0;
	}
	int x = 0;
	for (auto i = m.begin(); i != m.end(); i++, x++) i->second = x;
	stfrom.resize(m.size());
	last(stfrom, 1) = -1;
	if (m.size() > 1) {
		auto it1 = m.rbegin(), it2 = it1; it2++;
		x = stfrom.size() - 2;
		for (; it2 != m.rend(); it1++, it2++, x--) {
			if (it2->first.first == it1->first.first) stfrom[x] = stfrom[x + 1];
			else stfrom[x] = x + 1;
		}
	}

	segtree seg = segtree(m.size());
	for (auto &i : q) {
		if (i.t == 0) seg.insert(m[{i.x, i.y}], node(i.y, i.x, i.y));
		else if (i.t == 1) seg.erase(m[{i.x, i.y}]);
		else {
			auto it = m.upper_bound({ i.x, i.y });
			if (it == m.end()) printf("-1\n");
			else {
				int at;
				if (it->first.first > i.x) at = it->second;
				else at = stfrom[it->second];
				if (at == -1) printf("-1\n");
				else {
					pair<int, int> rtn = seg.bs(at, i.y);
					if (rtn.first == -1) printf("-1\n");
					else printf("%d %d\n", rtn.first, rtn.second);
				}
			}
		}
	}
}