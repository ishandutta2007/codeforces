#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;

const ll INF = 1e18+10;

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

int n, k;
ar<ll, 3> a[MAXN], lft[MAXN], rgt[MAXN], up[MAXN], down[MAXN];
ll ans = INF;

ll ceil_div(ll x, ll y){ return (x+y-1)/y; }
void solve(){
    cin >> n >> k;
    for (int i = 0; i < n; i++)  {
        ll x1, x2, y1, y2; cin >> x1 >> y1 >> x2 >> y2;
        a[i] = lft[i] = rgt[i] = up[i] = down[i] = {x1+x2, y1+y2, i};
    }
    sort(lft, lft+n, [&](auto i, auto j){ return i[0] < j[0]; });
    sort(rgt, rgt+n, [&](auto i, auto j){ return i[0] > j[0]; });
    sort(up, up+n, [&](auto i, auto j){ return i[1] < j[1]; });
    sort(down, down+n, [&](auto i, auto j){ return i[1] > j[1]; });

    for (int a = 0; a <= k; a++) for (int b = 0; b <= k; b++) for (int c = 0; c <= k; c++) for (int d = 0; d <= k; d++) {
        unordered_set<int> vis;
        for (int i = 0; i < a; i++) vis.insert(lft[i][2]);
        for (int i = 0; i < b; i++) vis.insert(rgt[i][2]);
        for (int i = 0; i < c; i++) vis.insert(up[i][2]);
        for (int i = 0; i < d; i++) vis.insert(down[i][2]);
        if (sz(vis) > k) continue;

        ll mn_x = INF, mx_x = -1, mn_y = INF, mx_y = -1;
        int i;
        for (i = 0; vis.count(lft[i][2]); i++); mn_x = lft[i][0];
        for (i = 0; vis.count(rgt[i][2]); i++); mx_x = rgt[i][0];
        for (i = 0; vis.count(up[i][2]); i++); mn_y = up[i][1];
        for (i = 0; vis.count(down[i][2]); i++); mx_y = down[i][1];

        ans = min(ans, max(1ll, ceil_div(mx_x-mn_x, 2))*max(1ll, ceil_div(mx_y-mn_y, 2)));
    }

    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}