#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9 + 1e6 + 123;
const ll LINF = (ll) 1e18 + 1e9 + 123;
const int MOD = (int) 1e9 + 7;

#define rep(i, s, t) for (auto i = (s); i < (t); ++(i))
#define per(i, s, t) for (auto i = (s); i >= (t); --(i))
#define sz(x) ((int)(x).size())
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

template<typename A, typename B> bool mini(A &x, const B &y) {
	if (y < x) {
		x = y;
		return 1;
	}
	return 0;
}

template<typename A, typename B> bool maxi(A &x, const B &y) {
	if (y > x) {
		x = y;
		return 1;
	}
	return 0;
}

int power(int x, int y, int mod=MOD) {
	if (y == 0) {
		return 1;
	}
	if (y % 2 == 1) {
		return power(x, y - 1, mod) * 1LL * x % MOD;
	} else {
		ll t = power(x, y / 2, mod);
		return t * 1LL * t % MOD;
	}
}

void add(int &x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
	if (x < 0) x += MOD;
}

int mult(int x, int y) {
	return x * 1LL * y % MOD;
}

void run();

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	run();
	return 0;
}

const int N = (int) 4e5 + 123;

inline int summ(int x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
	return x;
}

struct Tree {
	int topush[4 * N + 13], sum[4 * N + 13];
	
	Tree() {
		fill(topush, topush + 4 * N, -1);
	}

	void push(int i, int tl, int tr) {
		if (topush[i] == -1) {
			return;
		}
		sum[i] = (topush[i] * 1LL * (tr - tl)) % MOD;
		if (tl != tr - 1) {
			topush[2 * i + 1] = topush[i];
			topush[2 * i + 2] = topush[i];
		}
		topush[i] = -1;
	}

	void upd(int i, int tl, int tr, int l, int r, int val) {
		push(i, tl, tr);
		if (tl >= r || tr <= l) {
			return;
		}
		if (l <= tl && tr <= r) {
			topush[i] = val;
			push(i, tl, tr);
			return;
		}
		int tm = (tl + tr) / 2;
		upd(2 * i + 1, tl, tm, l, r, val);
		upd(2 * i + 2, tm, tr, l, r, val);
		sum[i] = summ(sum[2 * i + 1], sum[2 * i + 2]);
	}
	
	void upd(int l, int r, int val) {
		upd(0, 0, N, l, r + 1, val);
	}
	
	int get(int i, int tl, int tr, int l, int r) {
		push(i, tl, tr);
		if (tl >= r || tr <= l) {
			return 0;
		}
		if (l <= tl && tr <= r) {
			return sum[i];
		}
		int tm = (tl + tr) / 2;
		return summ(get(2 * i + 1, tl, tm, l, r), get(2 * i + 2, tm, tr, l, r));
	}
	
	int get(int l, int r) {
		return get(0, 0, N, l, r + 1);
	}
};

int k, n, m;
vector<int> X;
vector<pair<int, int>> sega, segb;
int a[N], b[N];
Tree in_a, in_b, out_a, out_b;

int get_ind(int x) {
	return (int) (lower_bound(all(X), x) - X.begin());
}

void run() {
	fill(a, a + N, -INF);
	fill(b, b + N, -INF);
	
	cin >> k >> n >> m;
	X.pb(0);
	X.pb(k);
	rep(i, 0, n) {
		int l, r;
		cin >> l >> r;
		sega.pb({l, r});
		X.pb(l - 1);
		X.pb(r);
	}
	rep(i, 0, m) {
		int l, r;
		cin >> l >> r;
		segb.pb({l, r});
		X.pb(l - 1);
		X.pb(r);
	}
	sort(all(X));
	X.resize(unique(all(X)) - X.begin());
	rep(i, 0, n) {
		int L = get_ind(sega[i].first - 1) + 1;
		int R = get_ind(sega[i].second);
		maxi(a[R], L);
	}
	rep(i, 0, m) {
		int L = get_ind(segb[i].first - 1) + 1;
		int R = get_ind(segb[i].second);
		maxi(b[R], L);
	}
	
	int k = sz(X);
	{
		int len = X[1] - X[0];
		out_a.upd(1, 1, 1);
		out_b.upd(1, 1, 1);
		int mem = power(2, len - 1);
		add(mem, -1);
		in_a.upd(1, 1, mem);
		in_b.upd(1, 1, mem);
		
		if (a[1] != -INF) {
			out_b.upd(0, a[1], 0);
			in_b.upd(0, a[1] - 1, 0);
		}
		if (b[1] != INF) {
			out_a.upd(0, b[1], 0);
			in_a.upd(0, b[1] - 1, 0);
		}
	}
	rep(i, 2, k) {
		int len = X[i] - X[i - 1];
		int mem = power(2, len - 1);
		add(mem, -1);
		int sum_A = summ(in_a.get(0, i - 1), out_a.get(0, i - 1));
		int sum_B = summ(in_b.get(0, i - 1), out_b.get(0, i - 1));
		int total = summ(sum_A, sum_B);
		in_a.upd(i, i, mult(total, mem));
		in_b.upd(i, i, mult(total, mem));
		out_a.upd(i, i, sum_B);
		out_b.upd(i, i, sum_A);
		if (a[i] != -INF) {
			out_b.upd(0, a[i], 0);
			in_b.upd(0, a[i] - 1, 0);
		}
		if (b[i] != INF) {
			out_a.upd(0, b[i], 0);
			in_a.upd(0, b[i] - 1, 0);
		}
		
		/*cerr << X[i - 1] + 1 << " " << X[i] << endl;
		cerr << "in_a: ";
		rep(j, 0, i + 1) {
			cerr << in_a.get(j, j) << " ";
		}
		cerr << endl;
		cerr << "in_b: ";
		rep(j, 0, i + 1) {
			cerr << in_b.get(j, j) << " ";
		}
		cerr << endl;
		cerr << "out_a: ";
		rep(j, 0, i + 1) {
			cerr << out_a.get(j, j) << " ";
		}
		cerr << endl;
		cerr << "out_b: ";
		rep(j, 0, i + 1) {
			cerr << out_b.get(j, j) << " ";
		}
		cerr << endl;
		cerr << "====" << endl;*/
	}
	
	cout << ((ll)in_a.get(0, k) + (ll)in_b.get(0, k) + (ll)out_a.get(0, k) + (ll)out_b.get(0, k)) % MOD << "\n";
}