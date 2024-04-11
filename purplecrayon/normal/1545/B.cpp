#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 998244353;

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

ll po(ll b, ll p, ll mod=MOD){
    ll r=1;
    for (; p; b=b*b%mod, p>>=1) if (p&1) r=r*b%mod;
    return r;
}
num po(num b, ll p){
    num r=1;
    for (; p; b=b*b, p>>=1) if (p&1) r=r*b;
    return r;
}

const int MAXV = 2e6+10;
num fact[MAXV], ifact[MAXV];

void pre(){ //call pre at the beginning (in main)
    fact[0] = ifact[0] = 1;
    for (int i = 1; i < MAXV; i++) fact[i] = fact[i-1]*i;
    ifact[MAXV-1] = inv(fact[MAXV-1]);
    for (int i = MAXV-2; i > 0; i--) ifact[i] = ifact[i+1]*num(i+1);
}
num nck(int n, int k){ //nck
    if (k > n) return 0;
    return fact[n]*ifact[k]*ifact[n-k];
}
num nck(num n, num k){ //nck
    return nck(int(n), int(k));
}
void solve(){
    int n; cin >> n;
    string s; cin >> s;

    int pos_left = n;
    int run = 0;
    int cnt_blocks = 0;

    int tot_num = 0, cnt[2]={};
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            cnt[i&1]++;
        }
    }
    int tot_even = (n+1)/2, tot_odd = n/2;
    for (char c : s) {
        tot_num += c-'0';
        if (c == '1') run++;
        else {
            if (run) {
                if (run&1) pos_left--, run--;
                cnt_blocks += run/2;
            }
            run = 0;
        }
    }
    if (run) {
        if (run&1) pos_left--, run--;
        cnt_blocks += run/2;
    }

    num ans = 0;
    //cnt_block 1's in a bitstring of length pos_left
    //the distance between adjacent ones has to be > 1
    pos_left--;
    if (cnt_blocks == 0) {
        ans = 1;
    } else if (cnt_blocks == 1) {
        ans = pos_left;
    } else {
        int gaps = cnt_blocks-1, tot_slots = pos_left-cnt_blocks;
        //cerr << tot_slot
        for (int i = 1; i <= tot_slots; i++) {
            int border = tot_slots-i;
            ans += nck(i-1, gaps-1)*(border+1);
        }
    }
    cout << ans << '\n';

    /*
    for (int i = 0; i < (1<<pos_left); i++) if (__builtin_popcount(i) == cnt_blocks) {
        vector<bool> has(pos_left);
        for (int j = 0; j < pos_left; j++) has[j] = (i>>j)&1;
        bool bad = 0;
        for (int j = 0; j < pos_left; j++) {
            if (j && has[j] && has[j-1]) bad = 1;
        }
        if (!bad) {
            ans++;
        }
    }
    cout << ans << '\n';
    */
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    pre();
    int T=1;
    cin >> T;
    while (T--) solve();
}