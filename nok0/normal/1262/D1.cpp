/**
 *	author: nok0
 *	created: 2020.10.19 21:11:33
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
	IN(name)
#define VVEC(type, name, h, w)    \
	VV<type> name(h, V<type>(w)); \
	IN(name)
#define INT(...)     \
	int __VA_ARGS__; \
	IN(__VA_ARGS__)
#define LL(...)     \
	ll __VA_ARGS__; \
	IN(__VA_ARGS__)
#define STR(...)        \
	string __VA_ARGS__; \
	IN(__VA_ARGS__)
#define CHAR(...)     \
	char __VA_ARGS__; \
	IN(__VA_ARGS__)
#define DOUBLE(...)     \
	DOUBLE __VA_ARGS__; \
	IN(__VA_ARGS__)
#define LD(...)     \
	LD __VA_ARGS__; \
	IN(__VA_ARGS__)
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
void IN() {}
template <class Head, class... Tail>
void IN(Head &head, Tail &... tail) {
	scan(head);
	IN(tail...);
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

int main() {
	INT(n);
	VEC(int, a, n);
	INT(m);
	V<pii> b(n);
	REP(i, n) { b[i] = {a[i], -i}; }
	sort(rall(b));
	REP(i, n) { b[i].second *= -1; }
	while(m--) {
		INT(k, p);
		--p;
		V<> res;
		REP(i, k) { res.pb(b[i].second); }
		sort(all(res));
		print(a[res[p]]);
	}
}