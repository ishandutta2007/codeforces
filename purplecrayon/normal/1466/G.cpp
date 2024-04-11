#include "bits/stdc++.h"
using namespace std;

template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;

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

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 1e5+10, MAXQ = 5e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 110, INF = 1e9+10, MAXA = 62, MAXB = 24, MAXBB = (1<<MAXB), MOD2=MOD-1;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

using num = modnum<MOD>;
num po(num b, ll p){
    num r=1;
    for (; p; b=b*b, p/=2) if (p&1) r=r*b;
    return r;
}

int occ(const string& s, const string t) { //# of s in t
    const int p = 31; 
    const int m = 1e9 + 9;
    int S = s.size(), T = t.size();

    vector<long long> p_pow(max(S, T)); 
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++) 
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(T + 1, 0); 
    for (int i = 0; i < T; i++)
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m; 
    long long h_s = 0; 
    for (int i = 0; i < S; i++) 
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m; 

    int occ=0;
    for (int i = 0; i + S - 1 < T; i++) { 
        long long cur_h = (h[i+S] + m - h[i]) % m; 
        if (cur_h == h_s * p_pow[i] % m) occ++;
    }
    return occ;
}

const int MAX_LEN = 3e6+10;
const int BASE = 345;

using hnum = modnum<int(1e9)+9>;
hnum pows[MAX_LEN];
void initHashes(){
    pows[0] = 1;
    for (int i = 1; i < MAX_LEN; i++) pows[i] = hnum(BASE)*pows[i-1];
}

struct hsh {
    //supports concatenating two hashes, checking for equality
    hnum v=hnum(0);
    int len=0;
    void init(string s){
        len = sz(s);
        for (char c : s) v = v*BASE, v += hnum(int(c-'a'+1));
    }
    hsh(){
    }
    hsh(string s){
        init(s);
    }
    hsh& operator+=(const hsh& h){
        v = v*pows[h.len]+h.v; len += h.len;
        return *this;
    };
    friend hsh operator+(hsh hl, const hsh& hr){
        return hl += hr;
    }
    friend bool operator==(const hsh& hl, const hsh& hr){
        return hl.v==hr.v && hl.len==hr.len;
    }
    friend bool operator!=(const hsh& hl, const hsh& hr){
        return !(hl == hr);
    }
};

int n, q;
string s_0, t, in, nw_in;
num dp[MAXN][26];

int get_sz(int x){
    return (ll(sz(s_0)+1)<<x) - 1;
}
int gen(int l, int idx){
    if (l == 0){
        for (int i = idx; i < idx+sz(s_0); i++) in[i] = s_0[i-idx];
        return idx+sz(s_0);
    }
    idx = gen(l-1, idx);
    in[idx++] = t[l-1];
    idx = gen(l-1, idx);
    return idx;
}
void solve(){
    initHashes();
    cin >> n >> q;
    cin >> s_0 >> t; assert(sz(t) == n);
    
    //|s_x| = (sz(s_0)+1)<<x - 1
    for (int j = 0; j < 26; j++) dp[0][j] = num(0);
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < 26; j++){
            dp[i][j] = dp[i-1][j]*num(2);
        }
        dp[i][t[i-1]-'a']++;
    }

    while (q--){
        int k; string w; cin >> k >> w; hsh w_h = hsh(w);
        int st=0; while (get_sz(st) < sz(w)) st++;
        if (st > k){ cout << 0 << '\n'; continue; } //doesn't fit in string

        in.resize(get_sz(st));
        int st_n = gen(st, 0); assert(st_n == get_sz(st));
        //cerr << st << ' ' << st_n << ' ' << in << '\n';

        vector<hsh> pre(st_n), suf(st_n);
        pre[0].init(string(1, in[0]));
        for (int i = 1; i < st_n; i++) pre[i] = pre[i-1]+hsh(string(1, in[i]));
        suf[st_n-1].init(string(1, in[st_n-1]));
        for (int i = st_n-2; i >= 0; i--) suf[i] = hsh(string(1, in[i]))+suf[i+1];

        num cur = num(occ(w, in)), ans=po(num(2), (k-st))*cur;
        if (st < k){
            for (int j = 0; j < 26; j++){
                num c_occ=0; hsh j_h = hsh(string(1, 'a'+j));
                if (sz(w) > 1){
                    for (int i = 0; i < sz(w)-2; i++) if (suf[st_n-sz(w)+i+2]+j_h+pre[i] == w_h) c_occ++;
                    if (j_h + pre[sz(w)-2] == w_h) c_occ++;
                    if (suf[st_n-sz(w)+1] + j_h == w_h) c_occ++;
                } else c_occ = j == w[0]-'a';

                num cur_dp = dp[k][j]-po(2, k-st)*dp[st][j];
                ans += cur_dp*c_occ;
            }
        }
        //cerr << "ANS: " << q << ' ' << ans << '\n';
        cout << ans << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}