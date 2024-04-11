#ifdef LOCAL
#  define _GLIBCXX_DEBUG
#else
#  define cerr __get_ce
#endif
#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(x) ((int)x.size())

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
mt19937 tw(9450189);
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }

struct node {
	int l, r, y, p;
	int x1, x2, val, tval;
	node() : l(0), r(0), y(0), p(-1), val(0), tval(0) {}
	node(int _x1, int _x2, int _val) : l(0), r(0), y(rnd(0, INFL)), p(-1), x1(_x1), x2(_x2), val(_val), tval(_val) {}
};

vector<node> treap;

void t_upd(int v) {
	int vl = treap[v].l;
	int vr = treap[v].r;
	treap[v].tval = treap[vl].tval ^ treap[v].val ^ treap[vr].tval;
	treap[vl].p = v;
	treap[vr].p = v;
	treap[v].p = -1;
}

int get_root(int v) {
	while (treap[v].p != -1) {
		v = treap[v].p;
	}
	return v;
}

int get_x1(int v) {
	while (treap[v].l != 0) {
		v = treap[v].l;
	}
	return treap[v].x1;
}

int get_x2(int v) {
	while (treap[v].r != 0) {
		v = treap[v].r;
	}
	return treap[v].x2;
}

void t_merge(int vl, int vr, int& v) {
	if (!vl) {
		v = vr;
		return;
	}
	if (!vr) {
		v = vl;
		return;
	}
	if (treap[vl].y > treap[vr].y) {
		t_merge(treap[vl].r, vr, treap[vl].r);
		v = vl;
		t_upd(v);
	} else {
		t_merge(vl, treap[vr].l, treap[vr].l);
		v = vr;
		t_upd(v);
	}
}

void t_split_1(int v, int& vl, int& vr, int x) {
	if (!v) {
		vl = vr = 0;
		return;
	}
	if (treap[v].x1 >= x) {
		t_split_1(treap[v].l, vl, treap[v].l, x);
		vr = v;
		t_upd(vr);
	} else {
		t_split_1(treap[v].r, treap[v].r, vr, x);
		vl = v;
		t_upd(vl);
	}
}

void t_split_2(int v, int& vl, int& vr, int x) {
	if (!v) {
		vl = vr = 0;
		return;
	}
	if (treap[v].x2 > x) {
		t_split_2(treap[v].l, vl, treap[v].l, x);
		vr = v;
		t_upd(vr);
	} else {
		t_split_2(treap[v].r, treap[v].r, vr, x);
		vl = v;
		t_upd(vl);
	}
}

void solve() {
	map<int, pair<pii, int>> to_left, to_right;
	treap.push_back(node());
	int cnt = 1;
	int tmp_node;

	function<void(int, int, int)> add = [&](int l, int r, int x) {
		// cerr << "add " << l << " " << r << " " << x << endl;
		assert(l < r);
		assert(!to_right.count(l) && !to_left.count(r));
		to_right[l] = {{r, x}, cnt};
		to_left[r] = {{l, x}, cnt};
		treap.push_back(node(l, r, x));
		if (to_left.count(l)) {
			// cerr << "here merge" << endl;
			// cerr << get_root(to_left[l].ss) << " " << cnt << endl;
			t_merge(get_root(to_left[l].ss), cnt, tmp_node);
			// cerr << treap[tmp_node].tval << endl;
		}
		if (to_right.count(r)) {
			t_merge(get_root(cnt), get_root(to_right[r].ss), tmp_node);
		}
		++cnt;
	};

	function<void(int, int, int)> remove = [&](int l, int r, int x) {
		// cerr << "remove " << l << " " << r << " " << x << endl;
		assert(l < r);
		assert(to_right.count(l) && to_left.count(r));
		assert(to_right[l].ff == make_pair(r, x) && to_left[r].ff == make_pair(l, x));
		int rt = get_root(to_right[l].ss);
		int vl, vm, vr;
		t_split_1(rt, vl, vr, r);
		t_split_2(vl, vl, vm, l);

		to_right.erase(l);
		to_left.erase(r);
	};

	function<pii(int, int)> skip_to_left = [&](int l, int r) {
		assert(to_left.count(r));
		int rt = get_root(to_left[r].ss);
		int vl, vm, vr;
		t_split_1(rt, vl, vr, r);
		t_split_1(vl, vl, vm, l);
		pii ret;
		if (vm) {
			ret = {get_x1(vm), treap[vm].tval};
		} else {
			ret = {r, 0};
		}
		t_merge(vl, vm, vl);
		t_merge(vl, vr, rt);
		return ret;
	};

	function<pii(int, int)> skip_to_right = [&](int l, int r) {
		assert(to_right.count(l));
		int rt = get_root(to_right[l].ss);
		int vl, vm, vr;
		t_split_2(rt, vl, vr, l);
		t_split_2(vr, vm, vr, r);
		// cerr << vl << " " << vm << " " << vr << endl;
		pii ret;
		if (vm) {
			ret = {get_x2(vm), treap[vm].tval};
		} else {
			ret = {l, 0};
		}
		t_merge(vl, vm, vl);
		t_merge(vl, vr, rt);
		return ret;
	};

	function<int(int, int)> calc = [&](int l, int r) {
		if (to_right.count(l) && to_left.count(r)) {
			pii tmp = skip_to_right(l, r);
			// cerr << tmp.ff << " " << tmp.ss << endl;
			if (tmp.ff == r) {
				return tmp.ss;
			} else {
				return -1;
			}
		}
		return -1;
	};

	function<void(int, int, int)> set_val = [&](int l, int r, int x) {
		// cerr << "set val" << endl;
		// cerr << l << " " << r << " " << x << endl;
		while (true) {
			bool changed = false;
			if (to_right.count(l)) {
				pii tmp = skip_to_right(l, r);
				// cerr << tmp.ff << " " << tmp.ss << endl;
				if (tmp.ff == r) {
					assert(tmp.ss == x);
					return;
				}
				assert(tmp.ff < r);
				x ^= tmp.ss;
				l = tmp.ff;
				if (to_right.count(l)) {
					pii seg = to_right[l].ff;
					assert(seg.ff > r);
					remove(l, seg.ff, seg.ss);
					//add(l, r, x);
					set_val(l, r, x);
					set_val(r, seg.ff, x ^ seg.ss);
					return;
					l = r;
					r = seg.ff;
					x ^= seg.ss;
					changed = true;
				}
			}
			// cerr << l << " " << r << " " << x << endl;
			if (to_left.count(r)) {
				pii tmp = skip_to_left(l, r);
				if (tmp.ff == l) {
					assert(tmp.ss == x);
					return;
				}
				assert(tmp.ff > l);
				x ^= tmp.ss;
				r = tmp.ff;
				if (to_left.count(r)) {
					pii seg = to_left[r].ff;
					assert(seg.ff < l);
					remove(seg.ff, r, seg.ss);
					// add(l, r, x);
					set_val(l, r, x);
					set_val(seg.ff, l, x ^ seg.ss);
					return;
					r = l;
					l = seg.ff;
					x ^= seg.ss;
					changed = true;
				}
			}

			// cerr << l << " " << r << " " << x << endl;

			if (!changed) {
				break;
			}
		}

		assert(!to_right.count(l) && !to_left.count(r));
		assert(l < r);

		add(l, r, x);
	};
	int q;
	cin >> q;
	int last = 0;
	for (int i = 0; i < q; ++i) {
		// cerr << "i: " << i << endl;
		int t;
		cin >> t;
		// cerr << t << " ";
		if (t == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			l ^= last; r ^= last; x ^= last;
			if (l > r) {
				swap(l, r);
			}
			++r;
			// cerr << l << " " << r << " " << x << endl;
			int tmp = calc(l, r);
			// cerr << l << " " << r << " " << tmp << endl;
			if (tmp == -1) {
				set_val(l, r, x);
			}
		} else {
			int l, r;
			cin >> l >> r;
			l ^= last;
			r ^= last;
			if (l > r) {
				swap(l, r);
			}
			++r;
			// cerr << l << " " << r << endl;
			int tmp = calc(l, r);
			if (tmp == -1) {
				last = 1;
			} else {
				last = tmp;
			}
			cout << tmp << "\n";
		}
	}
}


int main() {
#ifdef LOCAL
	auto start_time = clock();
	cerr << setprecision(3) << fixed;
#endif
	cout << setprecision(15) << fixed;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_count = 1;
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}
	
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}