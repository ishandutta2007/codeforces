#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;
#define DEBUG
#ifdef DEBUG
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
	os << '(' << p.first << ',' << p.second << ')';
	return os;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
	os << '{';
	for(int i = 0; i < (int)v.size(); i++) {
		if(i) { os << ','; }
		os << v[i];
	}
	os << '}';
	return os;
}
ostream &operator<<(ostream &os, const set<int> &se) {
	os << '{';
	int now = 0;
	for(auto x : se) {
		if(now) { os << ','; }
		os << x;
		now++;
	}
	os << '}';
	return os;
}
void debugg() { cerr << endl; }
template <class T, class... Args>
void debugg(const T &x, const Args &... args) {
	cerr << " " << x;
	debugg(args...);
}
#define debug(...) \
	cerr << __LINE__ << " [" << #__VA_ARGS__ << "]: ", debugg(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef pair<ll, ll> P;
typedef pair<int, int> pii;
typedef vector<P> vpl;
typedef tuple<ll, ll, ll> tapu;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const int inf = (1 << 30) - 1;
const ll linf = 1LL << 61;
const int MAX = 3010000;
int dy[8] = {0, 1, 0, -1, 1, -1, -1, 1};
int dx[8] = {-1, 0, 1, 0, 1, -1, 1, -1};
const double pi = acos(-1);
const double eps = 1e-8;
template <typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {
	if(a > b) {
		a = b;
		return true;
	} else
		return false;
}
template <typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {
	if(a < b) {
		a = b;
		return true;
	} else
		return false;
}
template <typename T>
inline void print(T &a) {
	int sz = a.size();
	for(auto itr = a.begin(); itr != a.end(); itr++) {
		cout << *itr;
		sz--;
		if(sz) cout << " ";
	}
	cout << "\n";
}
template <typename T1, typename T2>
inline void print2(T1 a, T2 b) {
	cout << a << " " << b << "\n";
}
template <typename T1, typename T2, typename T3>
inline void print3(T1 a, T2 b, T3 c) {
	cout << a << " " << b << " " << c << "\n";
}
void mark() { cout << "#"
	               << "\n"; }
ll pcount(ll x) { return __builtin_popcountll(x); }
const int mod = 1e9 + 7;
//const int mod = 998244353;

template <int mod>
struct ModInt {
	int x;

	ModInt() : x(0) {}

	ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

	ModInt &operator+=(const ModInt &p) {
		if((x += p.x) >= mod) x -= mod;
		return *this;
	}

	ModInt &operator-=(const ModInt &p) {
		if((x += mod - p.x) >= mod) x -= mod;
		return *this;
	}

	ModInt &operator*=(const ModInt &p) {
		x = (int)(1LL * x * p.x % mod);
		return *this;
	}

	ModInt &operator/=(const ModInt &p) {
		*this *= p.inverse();
		return *this;
	}

	ModInt operator-() const { return ModInt(-x); }

	ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

	ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

	ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

	ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

	bool operator==(const ModInt &p) const { return x == p.x; }

	bool operator!=(const ModInt &p) const { return x != p.x; }

	ModInt inverse() const {
		int a = x, b = mod, u = 1, v = 0, t;
		while(b > 0) {
			t = a / b;
			swap(a -= t * b, b);
			swap(u -= t * v, v);
		}
		return ModInt(u);
	}

	ModInt pow(int64_t n) const {
		ModInt ret(1), mul(x);
		while(n > 0) {
			if(n & 1) ret *= mul;
			mul *= mul;
			n >>= 1;
		}
		return ret;
	}

	friend ostream &operator<<(ostream &os, const ModInt &p) {
		return os << p.x;
	}

	friend istream &operator>>(istream &is, ModInt &a) {
		int64_t t;
		is >> t;
		a = ModInt<mod>(t);
		return (is);
	}

	static int get_mod() { return mod; }
};

using mint = ModInt<mod>;

vector<mint> fac(MAX), finv(MAX), inv(MAX);

void comInit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for(ll i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i;
		inv[i] = (mint)mod - inv[mod % i] * (mod / i);
		finv[i] = finv[i - 1] * inv[i];
	}
}

mint com(ll n, ll k) {
	if(n < k) return 0;
	if(n < 0 || k < 0) return 0;
	return fac[n] * finv[k] * finv[n - k];
}

mint dp[3010101][3];

const mint Inv = 333333336;
void solve() {
	int n, q;
	cin >> n >> q;
	comInit();
	dp[0][0] = dp[0][1] = dp[0][2] = n + 1;
	for(int i = 1; i <= n * 3; i++) {
		dp[i][0] = (com(3 * n + 3, i + 1) - dp[i - 1][0] * 2 - dp[i - 1][1]) * Inv;
		dp[i][1] = dp[i][0] + dp[i - 1][0];
		dp[i][2] = dp[i][1] + dp[i - 1][1];
	}
	while(q--) {
		int x;
		cin >> x;
		cout << dp[x][0] << "\n";
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int t = 1;
	//cin >> t;
	while(t--) {
		solve();
	}
}