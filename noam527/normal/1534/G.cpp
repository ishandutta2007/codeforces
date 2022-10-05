#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 1;
using namespace std;


struct splaytree {
	// to be nonlazy, if efficiency is necessary, remove the definition of push() and uncomment the next line:
	//#define push(X) ;
	struct node {
		int ch[2] = {}, p;
		int val;
		int size;
		int add; // hold some lazy tags
		node(int value = 0) {
			ch[0] = ch[1] = p = add = 0;
			size = 1;
			val = value;
		}
		int& operator [](int index) {
			return ch[index];
		}
	};
	int root = 0; // will hold some root.
	vector<node> T;
	vector<int> free_nodes;
	splaytree(int expected_max = 0) {
		T.reserve(expected_max + 1);
		// initialize T[0] with null values:
		T.push_back(node());
		T[0].size = 0;
	}
	int new_node(int value) {
		if (free_nodes.size()) {
			int res = free_nodes.back();
			free_nodes.pop_back();
			T[res] = node(value);
			return res;
		}
		T.push_back(node(value));
		return (int)T.size() - 1;
	}
	// update push and fix accordingly
	void push(int x) {
		if (!x) return;
		int l = T[x].ch[0], r = T[x].ch[1];
		if (T[x].add) {
			T[x].val += T[x].add;
			T[l].add += T[x].add, T[r].add += T[x].add;
			T[x].add = 0;
		}
	}
	void fix(int x) {
		if (!x) return;
		int l = T[x].ch[0], r = T[x].ch[1];
		push(l); push(r);
		T[x].size = 1 + T[l].size + T[r].size;
	}
	// assumes p is pushed.
	void setchild(int p, int d, int x) {
		T[p][d] = x, T[x].p = p;
		fix(p);
	}
	int dir(int x) {
		int p = T[x].p;
		if (!p) return -1;
		return T[T[x].p].ch[1] == x ? 1 : 0;
	}
	// assumes the chain (x, x.p, x.p.p) is all pushed.
	void rotate(int x) {
		int y = T[x].p, z = T[y].p, dx = dir(x), dy = dir(y);
		setchild(y, dx, T[x][!dx]);
		setchild(x, !dx, y);
		if (dy >= 0) setchild(z, dy, x);
		else T[x].p = z; // needs to happen regardless.
	}
	// guarantees the new root is pushed.
	int splay(int x) {
		for (push(x); T[x].p;) {
			int y = T[x].p, z = T[y].p;
			push(z); push(y); push(x);
			int dx = dir(x), dy = dir(y);
			if (dy >= 0) rotate(dx == dy ? y : x);
			rotate(x);
		}
		return root = x;
	}
	// have at it
	// returns the new node at root
	int lowerbound(int val, int start) {
		int v = 0, lst = 0;
		for (int cur = (start ? start : root); cur;) {
			push(cur);
			lst = cur;
			if (T[cur].val < val)
				cur = T[cur].ch[1];
			else
				v = cur, cur = T[cur].ch[0];
		}
		if (!v) return splay(lst);
		splay(lst);
		return splay(v);
	}
	// the actual value
	ll lowerbound(ll val) {
		int v = lowerbound(val, root);
		if (T[v].val >= val) return T[v].val;
		return inf;
	}
	// returns the new node at root
	int index(int k, int start) {
		while (1) {
			push(start);
			int l = T[start].ch[0];
			if (T[l].size > k) start = l;
			else if (T[l].size < k) {
				start = T[start].ch[1];
				k -= (1 + T[l].size);
			}
			else return splay(start);
		}
	}
	// the actual value
	ll index(int k) {
		return T[index(k, root)].val;
	}
	// splits the splay containing v into two splays with roots l, r:
	// l has all values < val, r has all values >= val.
	void split_value(int v, int &l, int &r, int val) {
		splay(v);
		int u = lowerbound(val, v);
		if (T[u].val < val) {
			l = u, r = 0;
			return;
		}
		r = u, l = T[u].ch[0];
		setchild(u, 0, 0);
		if (l) T[l].p = 0;
	}
	void split_size(int v, int &l, int &r, int lsz) {
		splay(v);
		if (T[v].size == lsz) {
			l = v, r = 0;
			return;
		}
		int u = index(lsz, v);
		r = u, l = T[u].ch[0];
		setchild(u, 0, 0);
		if (l) T[l].p = 0;
	}
	// merge the trees rooted at l, r, return the new root.
	int merge(int l, int r) {
		if (!l || !r) return l | r;
		for (push(l); T[l].ch[1]; push(l))
			l = T[l].ch[1];
		splay(l);
		setchild(l, 1, r);
		return l;
	}

	int insert(int val) {
		if (!root) return root = new_node(val);
		int l, r, n = new_node(val);
		split_value(root, l, r, val);
		T[n].ch[0] = l, T[n].ch[1] = r;
		T[l].p = T[r].p = n;
		fix(n);
		return root = n;
	}
	int insert_at(int val, int k) {
		if (!root) return root = new_node(val);
		int l, r, n = new_node(val);
		split_size(root, l, r, k);
		setchild(n, 0, l), setchild(n, 1, r);
		return root = n;
	}
	void erase(ll val) {
		int v = splay(lowerbound(val, root));
		free_nodes.push_back(v);
		int l = T[v].ch[0], r = T[v].ch[1];
		T[l].p = T[r].p = 0;
		root = merge(l, r);
	}
	void erase_at(int k) {
		int v = splay(index(k, root));
		free_nodes.push_back(v);
		int l = T[v].ch[0], r = T[v].ch[1];
		T[l].p = T[r].p = 0;
		root = merge(l, r);
	}


	int size() {
		return T[root].size;
	}
	void add_from_median(ll add) {
		index((size() - 1) / 2, root);
		T[T[root].ch[1]].add += add;
	}

	void gettree(int v, vector<int> &res) {
		if (!v) return;
		push(v);
		gettree(T[v].ch[0], res);
		res.push_back(T[v].val);
		gettree(T[v].ch[1], res);
	}
	vector<int> gettree() {
		vector<int> result;
		gettree(root, result);
		return result;
	}
};

bool cmp(const pair<int, int> &aa, const pair<int, int> &bb) {
	return aa.first + aa.second < bb.first + bb.second;
}

void solve() {
	int n;
	splaytree T;

	cin >> n;
	T = splaytree(2 * n);
	vector<pair<int, int>> a(n);
	for (auto &i : a) cin >> i.first >> i.second;
	sort(a.begin(), a.end(), cmp);
	int l = 0;
	for (int i = 1; i <= n; i++) {
		if (i == n || cmp(a[l], a[i])) {
			if (l != 0) {
				int diff = a[l].first + a[l].second - (a[l - 1].first + a[l - 1].second);
				T.add_from_median(diff);
			}
			for (int j = l; j < i; j++)
				T.insert(a[j].first), T.insert(a[j].first);
			l = i;
		}
	}
	vector<int> pos = T.gettree();
	//for (const auto &i : pos) cout << i << " "; cout << '\n';

	ll end = 0;
	for (int i = 0; i < n; i++)
		end += a[i].first;
	ll lst = 0;
	ll mult = n;
	for (int i = 0; mult > 0; i++, mult--) {
		end -= mult * (pos[i] - lst);
		lst = pos[i];
	}
	cout << end << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	//cin >> tst;
	while (tst--) solve();
}