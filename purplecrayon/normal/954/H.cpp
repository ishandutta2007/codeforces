#include "bits/stdc++.h"
using namespace std;
 
template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;
 
#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 5e3+10, MAXQ = 3e5+10, MAXL = 18, ALP = 26, MOD = 1e9+7, MAXK = 17,  MAXA = 10, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const int INF = 1e9+10;

template <int MOD_> struct modnum {
	static constexpr int MOD = MOD_;
	static_assert(MOD_ > 0, "MOD must be positive");
private:
	using ll = long long;

	int v;

	static int minv(int a, int m) {
		a %= m;
		assert(a);
		return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
	}
public:
	modnum() : v(0) {}
	modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
	explicit operator int() const { return v; }
	friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
	friend std::istream& operator >> (std::istream& in, modnum& n) { ll v_; in >> v_; n = modnum(v_); return in; }

	friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
	friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

	modnum inv() const {
		modnum res;
		res.v = minv(v, MOD);
		return res;
	}
	friend modnum inv(const modnum& m) { return m.inv(); }
	modnum neg() const {
		modnum res;
		res.v = v ? MOD-v : 0;
		return res;
	}
	friend modnum neg(const modnum& m) { return m.neg(); }

	modnum operator- () const {
		return neg();
	}
	modnum operator+ () const {
		return modnum(*this);
	}

	modnum& operator ++ () {
		v ++;
		if (v == MOD) v = 0;
		return *this;
	}
	modnum& operator -- () {
		if (v == 0) v = MOD;
		v --;
		return *this;
	}
	modnum& operator += (const modnum& o) {
		v -= MOD-o.v;
		v = (v < 0) ? v + MOD : v;
		return *this;
	}
	modnum& operator -= (const modnum& o) {
		v -= o.v;
		v = (v < 0) ? v + MOD : v;
		return *this;
	}
	modnum& operator *= (const modnum& o) {
		v = int(ll(v) * ll(o.v) % MOD);
		return *this;
	}
	modnum& operator /= (const modnum& o) {
		return *this *= o.inv();
	}

	friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
	friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
	friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
	friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
	friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
	friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};

using num = modnum<MOD>;

const int I2 = (MOD+1)/2;
ll po(ll b, ll p) {
    ll r=1;
    for (; p; b=b*b%MOD, p>>=1) if (p&1) r=r*b%MOD;
    return r;
}
int n, a[MAXN];
num cnt[MAXN], dp[MAXN][2*MAXN], ans[MAXN];

void solve(){
    cin >> n;
    cnt[0] = 1;
    for (int i = 1; i < n; i++) {
        cin >> a[i], cnt[i] = cnt[i-1]*a[i];
    }
    //cnt is number of nodes at ith level
    for (int i = n; i >= 1; i--) {
        dp[i][0] = 1;
        for (int j = 1; j <= n-i; j++) {
            dp[i][j] = a[i]*dp[i+1][j-1];
            ans[j] += dp[i][j]*cnt[i-1];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = (n-1)*2; j >= 1; j--) {
            dp[i][j] = dp[i-1][j-1];
            if (i > 1 && j > 1 && j <= i+n-2 && j-2 < n)
                dp[i][j] += dp[i][j-2]*(a[i-1]-1);

            ans[j] += dp[i][j]*cnt[i-1];
        }
    }
    for (int i = 1; i <= (n-1)*2; i++) cout << (ans[i]/2) << ' ';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}