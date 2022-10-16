/**
 *	author: nok0
 *	created: 2021.01.01 21:33:56
**/
#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
#pragma region Macros
#define FOR(i, l, r) for(int i = (l); i < (r); ++i)
#define REP(i, n) FOR(i, 0, n)
#define REPS(i, n) FOR(i, 1, n + 1)
#define RFOR(i, l, r) for(int i = (l); i >= (r); --i)
#define RREP(i, n) RFOR(i, n - 1, 0)
#define RREPS(i, n) RFOR(i, n, 1)
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template <class T = int>
using V = vector<T>;
template <class T = int>
using VV = V<V<T>>;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define VEC(type, name, size) \
	V<type> name(size);       \
	INPUT(name)
#define VVEC(type, name, h, w)    \
	VV<type> name(h, V<type>(w)); \
	INPUT(name)
#define INT(...)     \
	int __VA_ARGS__; \
	INPUT(__VA_ARGS__)
#define LL(...)     \
	ll __VA_ARGS__; \
	INPUT(__VA_ARGS__)
#define STR(...)        \
	string __VA_ARGS__; \
	INPUT(__VA_ARGS__)
#define CHAR(...)     \
	char __VA_ARGS__; \
	INPUT(__VA_ARGS__)
#define DOUBLE(...)     \
	DOUBLE __VA_ARGS__; \
	INPUT(__VA_ARGS__)
#define LD(...)     \
	LD __VA_ARGS__; \
	INPUT(__VA_ARGS__)
void scan(int &a) { cin >> a; }
void scan(long long &a) { cin >> a; }
void scan(char &a) { cin >> a; }
void scan(double &a) { cin >> a; }
void scan(long double &a) { cin >> a; }
void scan(char a[]) { scanf("%s", a); }
void scan(string &a) { cin >> a; }
template <class T>
void scan(V<T> &);
template <class T, class L>
void scan(pair<T, L> &);
template <class T>
void scan(V<T> &a) {
	for(auto &i : a) scan(i);
}
template <class T, class L>
void scan(pair<T, L> &p) {
	scan(p.first);
	scan(p.second);
}
template <class T>
void scan(T &a) { cin >> a; }
void INPUT() {}
template <class Head, class... Tail>
void INPUT(Head &head, Tail &... tail) {
	scan(head);
	INPUT(tail...);
}
template <class T>
inline void print(T x) { cout << x << '\n'; }
template <typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) {
	is >> p.first >> p.second;
	return is;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
	os << p.first << " " << p.second;
	return os;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
	for(T &in : v) is >> in;
	return is;
}
template <class T>
ostream &operator<<(ostream &os, const V<T> &v) {
	REP(i, SZ(v)) {
		if(i) os << " ";
		os << v[i];
	}
	return os;
}
//debug
template <typename T>
void view(const V<T> &v) {
	cerr << "{ ";
	for(const auto &e : v) {
		cerr << e << ", ";
	}
	cerr << "\b\b }";
}
template <typename T>
void view(const VV<T> &vv) {
	cerr << "{\n";
	for(const auto &v : vv) {
		cerr << "\t";
		view(v);
		cerr << "\n";
	}
	cerr << "}";
}
template <typename T, typename U>
void view(const V<pair<T, U>> &v) {
	cerr << "{\n";
	for(const auto &c : v) cerr << "\t(" << c.first << ", " << c.second << ")\n";
	cerr << "}";
}
template <typename T, typename U>
void view(const map<T, U> &m) {
	cerr << "{\n";
	for(auto &t : m) cerr << "\t[" << t.first << "] : " << t.second << "\n";
	cerr << "}";
}
template <typename T, typename U>
void view(const pair<T, U> &p) { cerr << "(" << p.first << ", " << p.second << ")"; }
template <typename T>
void view(const set<T> &s) {
	cerr << "{ ";
	for(auto &t : s) {
		view(t);
		cerr << ", ";
	}
	cerr << "\b\b }";
}
template <typename T>
void view(T e) { cerr << e; }
#ifdef LOCAL
void debug_out() {}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	view(H);
	cerr << ", ";
	debug_out(T...);
}
#define debug(...)                                           \
	do {                                                     \
		cerr << __LINE__ << " [" << #__VA_ARGS__ << "] : ["; \
		debug_out(__VA_ARGS__);                              \
		cerr << "\b\b]\n";                                   \
	} while(0)
#else
#define debug(...) (void(0))
#endif
template <class T>
V<T> press(V<T> &x) {
	V<T> res = x;
	sort(all(res));
	res.erase(unique(all(res)), res.end());
	REP(i, SZ(x)) {
		x[i] = lower_bound(all(res), x[i]) - res.begin();
	}
	return res;
}
template <class T>
inline bool chmin(T &a, T b) {
	if(a > b) {
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool chmax(T &a, T b) {
	if(a < b) {
		a = b;
		return true;
	}
	return false;
}
inline void Yes(bool b = true) { cout << (b ? "Yes" : "No") << '\n'; }
inline void YES(bool b = true) { cout << (b ? "YES" : "NO") << '\n'; }
inline void err(bool b = true) {
	if(b) {
		cout << -1 << '\n';
		exit(0);
	}
}
template <class T>
inline void fin(bool b = true, T e = 0) {
	if(b) {
		cout << e << '\n';
		exit(0);
	}
}
template <class T>
T divup(T x, T y) { return (x + (y - 1)) / y; }
template <typename T>
T pow(T a, long long n, T e = 1) {
	T ret = e;
	while(n) {
		if(n & 1) ret *= a;
		a *= a;
		n >>= 1;
	}
	return ret;
}
struct iofast {
	iofast() {
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		cout << fixed << setprecision(15);
	}
} iofast_;
const int inf = 1e9;
const ll INF = 1e18;
#pragma endregion

template <class T>
struct SegmentTreeBeats {
private:
	size_t n, n_;
	const T MAX = std::numeric_limits<T>::max();
	const T MIN = -MAX;
	std::vector<T> max_v, min_v, smax_v, smin_v, lz_upd, lz_ad, sigm, len;
	std::vector<int> max_c, min_c;

	void init(std::vector<T> &v) {
		n_ = v.size(), n = 1;
		while(n < n_) n *= 2;
		max_v.assign(n * 2 - 1, MIN);
		min_v.assign(n * 2 - 1, MAX);
		smax_v.assign(n * 2 - 1, MIN);
		smin_v.assign(n * 2 - 1, MAX);
		lz_upd.assign(n * 2 - 1, MAX);
		lz_ad.assign(n * 2 - 1, 0);
		len.assign(n * 2 - 1, n);
		sigm.assign(n * 2 - 1, 0);
		max_c.assign(n * 2 - 1, 1);
		min_c.assign(n * 2 - 1, 1);

		for(int i = 0; i < n - 1; i++)
			len[i * 2 + 1] = len[i * 2 + 2] = (len[i] >> 1);

		for(int i = 0; i < n_; i++)
			max_v[i + n - 1] = min_v[i + n - 1] = sigm[i + n - 1] = v[i];

		for(int i = n - 2; i >= 0; i--)
			proc(i);
	}

	void proc(int i) {
		sigm[i] = sigm[i * 2 + 1] + sigm[i * 2 + 2];

		max_v[i] = std::max(max_v[i * 2 + 1], max_v[i * 2 + 2]);

		if(max_v[i * 2 + 1] > max_v[i * 2 + 2]) {
			max_c[i] = max_c[i * 2 + 1];
			smax_v[i] = std::max(smax_v[i * 2 + 1], max_v[i * 2 + 2]);
		}

		if(max_v[i * 2 + 1] < max_v[i * 2 + 2]) {
			max_c[i] = max_c[i * 2 + 2];
			smax_v[i] = std::max(max_v[i * 2 + 1], smax_v[i * 2 + 2]);
		}

		if(max_v[i * 2 + 1] == max_v[i * 2 + 2]) {
			max_c[i] = max_c[i * 2 + 1] + max_c[i * 2 + 2];
			smax_v[i] = std::max(smax_v[i * 2 + 1], smax_v[i * 2 + 2]);
		}

		min_v[i] = std::min(min_v[i * 2 + 1], min_v[i * 2 + 2]);

		if(min_v[i * 2 + 1] < min_v[i * 2 + 2]) {
			min_c[i] = min_c[i * 2 + 1];
			smin_v[i] = std::min(smin_v[i * 2 + 1], min_v[i * 2 + 2]);
		}

		if(min_v[i * 2 + 1] > min_v[i * 2 + 2]) {
			min_c[i] = min_c[i * 2 + 2];
			smin_v[i] = std::min(min_v[i * 2 + 1], smin_v[i * 2 + 2]);
		}

		if(min_v[i * 2 + 1] == min_v[i * 2 + 2]) {
			min_c[i] = min_c[i * 2 + 1] + min_c[i * 2 + 2];
			smin_v[i] = std::min(smin_v[i * 2 + 1], smin_v[i * 2 + 2]);
		}
	}

	void eval(int i) {
		if(lz_upd[i] != MAX) {
			in_update(i * 2 + 1, lz_upd[i]);
			in_update(i * 2 + 2, lz_upd[i]);
			lz_upd[i] = MAX;
			return;
		}

		if(lz_ad[i]) {
			in_add(i * 2 + 1, lz_ad[i]);
			in_add(i * 2 + 2, lz_ad[i]);
			lz_ad[i] = 0;
		}

		if(max_v[i] < max_v[i * 2 + 1]) in_chmin(i * 2 + 1, max_v[i]);
		if(max_v[i] < max_v[i * 2 + 2]) in_chmin(i * 2 + 2, max_v[i]);

		if(min_v[i] > min_v[i * 2 + 1]) in_chmax(i * 2 + 1, min_v[i]);
		if(min_v[i] > min_v[i * 2 + 2]) in_chmax(i * 2 + 2, min_v[i]);
	}

	void in_update(int i, T x) {
		max_v[i] = min_v[i] = x;
		smax_v[i] = MIN, smin_v[i] = MAX;
		max_c[i] = min_c[i] = len[i];
		sigm[i] = len[i] * x;
		lz_upd[i] = x, lz_ad[i] = 0;
	}

	void in_chmin(int i, T x) {
		sigm[i] += (x - max_v[i]) * max_c[i];

		if(max_v[i] == min_v[i])
			max_v[i] = min_v[i] = x;

		else if(max_v[i] == smin_v[i])
			max_v[i] = smin_v[i] = x;

		else
			max_v[i] = x;

		if(lz_upd[i] != MAX and lz_upd[i] > x) lz_upd[i] = x;
	}

	void in_chmax(int i, T x) {
		sigm[i] += (x - min_v[i]) * min_c[i];

		if(min_v[i] == max_v[i])
			min_v[i] = max_v[i] = x;

		else if(min_v[i] == smax_v[i])
			min_v[i] = smax_v[i] = x;

		else
			min_v[i] = x;

		if(lz_upd[i] != MAX and lz_upd[i] < x) lz_upd[i] = x;
	}

	void in_add(int i, T x) {
		max_v[i] += x, min_v[i] += x;

		if(smin_v[i] != MAX) smin_v[i] += x;
		if(smax_v[i] != MIN) smax_v[i] += x;

		sigm[i] += x * len[i];

		if(lz_upd[i] != MAX) lz_upd[i] += x;
		lz_ad[i] += x;
	}

	void chmin(int i, int a, int b, int l, int r, T x) {
		if(b <= l or r <= a or x >= max_v[i]) return;

		if(a <= l and r <= b and smax_v[i] < x) {
			in_chmin(i, x);
			return;
		}

		eval(i);
		chmin(i * 2 + 1, a, b, l, (l + r) >> 1, x);
		chmin(i * 2 + 2, a, b, (l + r) >> 1, r, x);
		proc(i);
	}

	void chmax(int i, int a, int b, int l, int r, T x) {
		if(b <= l or r <= a or x <= min_v[i]) return;

		if(a <= l and r <= b and smin_v[i] > x) {
			in_chmax(i, x);
			return;
		}

		eval(i);
		chmax(i * 2 + 1, a, b, l, (l + r) >> 1, x);
		chmax(i * 2 + 2, a, b, (l + r) >> 1, r, x);
		proc(i);
	}

	void add(int i, int a, int b, int l, int r, T x) {
		if(b <= l or r <= a) return;

		if(a <= l and r <= b) {
			in_add(i, x);
			return;
		}

		eval(i);
		add(i * 2 + 1, a, b, l, (l + r) >> 1, x);
		add(i * 2 + 2, a, b, (l + r) >> 1, r, x);
		proc(i);
	}

	void update(int i, int a, int b, int l, int r, T x) {
		if(b <= l or r <= a) return;

		if(a <= l and r <= b) {
			in_update(i, x);
			return;
		}

		eval(i);
		update(i * 2 + 1, a, b, l, (l + r) >> 1, x);
		update(i * 2 + 2, a, b, (l + r) >> 1, r, x);
		proc(i);
	}

	T sum(int i, int a, int b, int l, int r) {
		if(r <= a || b <= l) return 0;
		if(a <= l && r <= b) return sigm[i];
		eval(i);
		T lv = sum(i * 2 + 1, a, b, l, (l + r) / 2);
		T rv = sum(i * 2 + 2, a, b, (l + r) / 2, r);
		return lv + rv;
	}

	T rangemin(int i, int a, int b, int l, int r) {
		if(r <= a or b <= l) return MAX;

		if(a <= l and r <= b) return min_v[i];

		eval(i);

		T lv = rangemin(i * 2 + 1, a, b, l, (l + r) >> 1);
		T rv = rangemin(i * 2 + 2, a, b, (l + r) >> 1, r);
		return std::min(lv, rv);
	}

	T rangemax(int i, int a, int b, int l, int r) {
		if(r <= a or b <= l) return MIN;

		if(a <= l and r <= b) return max_v[i];

		eval(i);

		T lv = rangemax(i * 2 + 1, a, b, l, (l + r) >> 1);
		T rv = rangemax(i * 2 + 2, a, b, (l + r) >> 1, r);
		return std::max(lv, rv);
	}

	T rangesum(int i, int a, int b, int l, int r) {
		if(r <= a or b <= l) return 0;

		if(a <= l and r <= b) return sigm[i];

		eval(i);

		T lv = rangesum(i * 2 + 1, a, b, l, (l + r) >> 1);
		T rv = rangesum(i * 2 + 2, a, b, (l + r) >> 1, r);
		return lv + rv;
	}

public:
	SegmentTreeBeats() = default;

	SegmentTreeBeats(std::vector<T> &v) {
		init(v);
	}

	SegmentTreeBeats(size_t n, T init_data = 0) {
		std::vector<T> v(n, init_data);
		init(v);
	}

	T operator[](int i) {
		return query_min(i, i + 1);
	}

	void update_chmin(int a, int b, T x) {
		chmin(0, a, b, 0, n, x);
	}

	void update_chmax(int a, int b, T x) {
		chmax(0, a, b, 0, n, x);
	}

	void update_add(int a, int b, T x) {
		add(0, a, b, 0, n, x);
	}

	void update_upd(int a, int b, T x) {
		update(0, a, b, 0, n, x);
	}

	T query_min(int a, int b) {
		return rangemin(0, a, b, 0, n);
	}

	T query_max(int a, int b) {
		return rangemax(0, a, b, 0, n);
	}

	T query_sum(int a, int b) {
		return rangesum(0, a, b, 0, n);
	}
};

int main() {
	INT(n);
	VEC(int, p, n);
	VEC(int, a, n);
	vector<int> ps(n);
	REP(i, n) {
		ps[--p[i]] = a[i] * (i ? 1 : -1);
	}
	debug(ps);
	vector cum(n + 1, 0ll);
	cum[0] = a[0];
	REP(i, n) {
		cum[i + 1] = cum[i] + ps[i];
	}
	debug(cum);
	SegmentTreeBeats<ll> Beats(cum);
	ll res = Beats.query_min(0, n + 1);
	FOR(i, 1, n - 1) {
		Beats.update_add(0, n + 1, a[i]);
		Beats.update_add(p[i] + 1, n + 1, -a[i] * 2);
		chmin(res, Beats.query_min(0, n + 1));
	}
	print(res);
}