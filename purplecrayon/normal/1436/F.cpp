#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+1, MOD = 998244353;

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

const int MAXV = 2e5+10;
int pf[MAXV];
 
num po(num b, ll p){
    num r=1;
    for (; p; b=b*b, p>>=1) if (p&1) r=r*b;
    return r;
}
void prep() {
    memset(pf, -1, sizeof(pf));
    for (int i = 2; i < MAXV; i++) if (pf[i] == -1) {
        for (int j = i; j < MAXV; j+=i) pf[j] = i;
    }
}
int get_mul(int c) {
    int ans = 0;
    while (c > 1) {
        int p = pf[c];
        c /= p;
 
        if (c%p == 0)
            return 0;
 
        ans ^= 1;
    }
    return (ans == 0 ? 1 : -1);
}


int n;
ll occ[MAXN];

num get(int d) {
    ll tot_occ = 0;
    for (int c = d; c < MAXN; c += d) tot_occ += occ[c];
    if (!tot_occ) return 0;

    num sum_same = 0, sum = 0;
    for (int c = d; c < MAXN; c += d) sum += num(occ[c])*c, sum_same += num(c)*c*occ[c];
    num sum_diff = sum*sum-sum_same;

    num ans = 0;
    if (tot_occ > 1) {
        ll real_occ = tot_occ - 2;
        //over all subsets of something of size real_occ, ans += sz(subset)+1
        num cur_sub = po(2, real_occ) + (real_occ ? po(2, real_occ-1) : num(1))*real_occ;
        ans += sum_diff * cur_sub;
    }
    ll real_occ = tot_occ - 1;
    //over all susbets of something of size real_occ, ans += sz(subset)
    num cur_sub = (real_occ ? po(2, real_occ-1) : num(1))*real_occ;
    ans += sum_same * cur_sub;

    return ans;
}
void solve() {
    prep();

    cin >> n;
    while (n--) {
        int x; ll cnt; cin >> x >> cnt;
        occ[x] = cnt;
    }
    num ans = 0;
    for (int i = 1; i < MAXN; i++) {
        int mul = get_mul(i);
        if (!mul) continue;
        ans += get(i)*mul;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}