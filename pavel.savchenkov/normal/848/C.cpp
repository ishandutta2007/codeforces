#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cstdlib>
#include <memory>
#include <queue>
#include <cassert>
#include <cmath>
#include <ctime>
#include <complex>
#include <bitset>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

using namespace std;

#define ws ws_____________________
#define y1 y1_____________________
#define y0 y0_____________________
#define left left_________________
#define right right_______________
#define next next_________________
#define prev prev_________________
#define hash hash_________________

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;

#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define FILE_NAME "a"

ull mrand() {
	ull x = rand();
	ull y = rand();
	return (x * (RAND_MAX - 1)) ^ y;
}

struct Node;
using NodePtr = Node*;

struct Data {
	int key;
	int val;
	ull prior;

	Data(int key, int val) : key(key), val(val) {
		prior = mrand();
	}
};

using DataPtr = const shared_ptr<Data>;

struct Node {
	const DataPtr data;
	ll sum;
	NodePtr l, r;

	Node() : data(0) {}

	Node(DataPtr data) : data(data) {
		l = r = 0;
		sum = data->val;
	}
};

void print(NodePtr t, int indent = 0) {
	if  (!t) {
		return;
	}

	assert(t->data);
	print(t->l, indent + 2);
	printf("%skey=%d, val=%d, sum=%lld\n", string(indent, ' ').data(), t->data->key, t->data->val, t->sum);
	print(t->r, indent + 2);
}

ll get_node_sum(NodePtr t) {
	if  (!t) {
		return 0;
	}
	return t->sum;
}

void upd(NodePtr& t) {
	if  (!t) {
		return;
	}
	t->sum = t->data->val + get_node_sum(t->l) + get_node_sum(t->r);
}

void split(NodePtr t, NodePtr& l, NodePtr& r, int key) {
	if  (!t) {
		l = r = 0;
		return;
	}

	if  (t->data->key < key) {
		split(t->r, t->r, r, key);
		l = t;
	} else {
		split(t->l, l, t->l, key);
		r = t;
	}

	upd(l);
	upd(r);
}

void merge(NodePtr& t, NodePtr l, NodePtr r) {
	if (!l) {
		t = r;
		return;
	}

	if  (!r) {
		t = l;
		return;
	}

	if  (l->data->prior > r->data->prior) {
		merge(l->r, l->r, r);
		t = l;
	} else {
		merge(r->l, l, r->l);
		t = r;
	}

	upd(t);
}

NodePtr erase(NodePtr& t, int key) {
	assert(t);

	if  (t->data->key == key) {
		NodePtr left = t->l;
		NodePtr right = t->r;
		delete t;
		merge(t, left, right);
		return t;
	}

	if  (key < t->data->key) {
		t->l = erase(t->l, key);
	} else {
		t->r = erase(t->r, key);
	}

	upd(t);

	return t;
}

NodePtr insert(NodePtr& t, NodePtr v) {
	if  (!t) {
		return v;
	}

	if  (v->data->prior > t->data->prior) {
		split(t, v->l, v->r, v->data->key);
		upd(v);
		return v;
	}

	if  (v->data->key < t->data->key) {
		t->l = insert(t->l, v);
	} else {
		t->r = insert(t->r, v);
	}

	upd(t);

	return t;
}

ll calc_sum(NodePtr& t, int up_key) {
	NodePtr t1, t2;
	split(t, t1, t2, up_key + 1);

	ll ans = get_node_sum(t1);

	merge(t, t1, t2);

	return ans;
}

struct SegmTree {
	vector<NodePtr> t;
	int sz;

	SegmTree(int n = 0) {
		sz = 1;
		while (sz < n) sz *= 2;
		t.assign(sz * 2, 0);
	}

	void insert(int pos, int key, int val) {
		int v = sz + pos;
		DataPtr data = make_shared<Data>(key, val);
		while (v) {
			t[v] = ::insert(t[v], new Node(data));
			v >>= 1;
		}
	}

	void erase(int pos, int key) {
		int v = sz + pos;
		while (v) {
			t[v] = ::erase(t[v], key);
			v >>= 1;
		}
	}

	ll get_sum(int l, int r, int up_key) {
		ll ans = 0;
		l += sz;
		r += sz;
		while (l <= r) {
			if  (l & 1) {
				ans += calc_sum(t[l], up_key);
				++l;
			}
			if  (~r & 1) {
				ans += calc_sum(t[r], up_key);
				--r;
			}
			l >>= 1;
			r >>= 1;
		}
		return ans;
	}
};

int n, m;
vi a;

bool read() {
	if  (scanf("%d%d", &n, &m) < 2) {
		return 0;
	}
	a.resize(n);
	forn(i, n) {
		scanf("%d", &a[i]);
		--a[i];
	}
	return 1;
}

vector<set<int>> poses;

int get_next(int pos) {
	const int v = a[pos];
	auto it = poses[v].find(pos);
	assert(it != poses[v].end());
	++it;
	if  (it == poses[v].end()) {
		return n + v;
	}
	return *it;
}

int get_prev(int pos) {
	const int v = a[pos];
	auto it = poses[v].find(pos);
	assert(it != poses[v].end());
	if  (it == poses[v].begin()) {
		return -1;
	}
	--it;
	return *it;
}

void solve() {
	poses.clear();
	poses.resize(n);

	forn(i, n) {
		poses[a[i]].insert(i);
	}

	SegmTree T(n);
	forn(i, n) {
		int nxt = get_next(i);
		T.insert(i, nxt, nxt - i);
	}

	forn(it, m) {
		int type;
		scanf("%d", &type);
		if  (type == 1) {
			int pos, x;
			scanf("%d%d", &pos, &x);
			--pos;
			--x;

			int prev = get_prev(pos);
			if  (prev != -1) {
				T.erase(prev, pos);
			}
			int nxt = get_next(pos);
			T.erase(pos, nxt);
			if  (prev != -1) {
				T.insert(prev, nxt, nxt - prev);
			}

			poses[a[pos]].erase(pos);
			a[pos] = x;
			poses[a[pos]].insert(pos);

			prev = get_prev(pos);
			nxt = get_next(pos);
			if  (prev != -1) {
				T.erase(prev, nxt);
				T.insert(prev, pos, pos - prev);
			}
			T.insert(pos, nxt, nxt - pos);
		} else {
			assert(type == 2);
			int l, r;
			scanf("%d%d", &l, &r);
			--l;
			--r;

			ll ans = T.get_sum(l, r, r);
			printf("%lld\n", ans);
		}
	}
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		solve();
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}