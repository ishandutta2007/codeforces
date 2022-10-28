#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 5e1+10, MOD = 998244353;

namespace vector_operators {
    template<typename T> vector<T>& operator*=(vector<T>& l, const T& r) { for (T& e : l) e *= r; return l; }
    template<typename T> vector<T> operator*(const T& l, vector<T> r) { return r *= l; }
    template<typename T> vector<T> conv(const vector<T>& l, const vector<T>& r) {
        if (l.empty() || r.empty()) return {};
        vector<T> p(sz(l) + sz(r) - 1);
        for (int i = 0; i < sz(l); i++) for (int j = 0; j < sz(r); j++) p[i+j] += l[i] * r[j];
        return p;
    }
    template<typename T> vector<T> operator*(const vector<T>& l, const vector<T>& r) { return conv(l, r); }
    template<typename T> vector<T>& operator-=(vector<T>& l, const vector<T>& r) { l.resize(max(sz(l), sz(r))); for (int i = 0; i < sz(r); i++) l[i] -= r[i]; return l; }
 
    template<typename T> vector<T> dot(const vector<T>& a, const vector<T>& b) { vector<T> p(min(sz(a), sz(b))); for (int i = 0; i < sz(p); i++) p[i] = a[i] * b[i]; return p; }
    template<typename T> vector<T>& operator<<=(vector<T>& v, int x) { v.insert(v.begin(), x, 0); return v; }
    template<typename T> vector<T> operator<<(vector<T> v, int x) { return v <<= x; }
 
    template<typename T> void rem_lead(vector<T>& v) { while (sz(v) && v.back() == 0) v.pop_back(); }
    template<typename T> vector<T> reversed(vector<T> v) { reverse(v.begin(), v.end()); rem_lead(v); return v; }
 
    template<typename T> pair<vector<T>, vector<T>> long_division(vector<T> a, vector<T> b) {
        rem_lead(a), rem_lead(b), assert(!b.empty());
        T B = T{1} / b.back(); for (T& e : b) e *= B;
        vector<T> q(max(sz(a) - sz(b) + 1, 0));
        for (; sz(a) >= sz(b); rem_lead(a)) {
            q[sz(a) - sz(b)] = a.back();
            a -= a.back() * (b << (sz(a) - sz(b)));
        }
        for (T& e : q) e *= B;
        return {q, a}; // quotient, remainder
    }
 
    template<typename T> vector<T>& operator/=(vector<T>& a, const vector<T>& b) { return a = long_division(a, b).first; }
    template<typename T> vector<T>& operator%=(vector<T>& a, const vector<T>& b) { return a = long_division(a, b).second; }
    template<typename T> vector<T> operator/(vector<T> a, const vector<T>& b) { return a /= b; }
    template<typename T> vector<T> operator%(vector<T> a, const vector<T>& b) { return a %= b; }
    template<typename T> vector<T> mod_pow(const vector<T>& v, ll e, const vector<T>& m) {
        if (!e) return {1};
        vector<T> res = mod_pow(v, e/2, m); res = res * res % m;
        return e&1 ? res * v % m : res;
    }
}
using namespace vector_operators;
template<typename T> struct LFSR {
    vector<T> seq;    // original sequence
    vector<T> fib;    // seq[i] = sum_j fib[j] * seq[i-1-j] (i >= sz(fib))
    vector<T> galois; // 0 = sum_j galois[j] * seq[i+j] (i <= sz(seq) - sz(galois))
 
    LFSR(vector<T> seq_) : seq(seq_) {
        vector<T> C = {1}, B = {1}; T b = 1;
        for (int i = 0, m = 1; i < sz(seq); i++, m++) {
            T d = 0; for (int j = 0; j < sz(C); j++) d += C[j] * seq[i - j];
            if (d == 0) continue;
            vector<T> B_ = C; C.resize(max(sz(C), m+sz(B)));
            T dbi = d/b; for (int j = 0; j < sz(B); j++) C[m+j] -= dbi * B[j];
            if (sz(B_) < m+sz(B)) { B = B_; b = d; m = 0; }
        }
        galois = vector_operators::reversed(C);
        fib = move(C); fib.erase(fib.begin()); fib *= T{-1};
    }
 
    T operator[](ll n) const {
        vector<T> r = dot(seq, mod_pow({0,1}, n, galois));
        return accumulate(r.begin(), r.end(), T{0});
    }
};
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


int range_isect(ar<int, 2> a, ar<int, 2> b) {
    return !(b[1] < a[0] || b[0] > a[1]);
}
const int INF = 1e9+10;
ar<int, 2> get_range(int x, int delta) {
    return {x-delta, x+delta};
}
int isect(ar<int, 2> a, ar<int, 2> b) {
    int lo = 0, hi = INF, mid = (lo+hi)/2;
    while (lo < mid && mid < hi) {
        bool x_isect = range_isect(get_range(a[0], mid), get_range(b[0], mid));
        bool y_isect = range_isect(get_range(a[1], mid), get_range(b[1], mid));
        if (x_isect && y_isect) hi = mid;
        else lo = mid;
        mid = (lo+hi)/2;
    }
    return hi;
}


int n, t;
ar<int, 2> a[MAXN];


namespace benq {
using ll = long long;
using db = long double; // or double, if TL is tight
using str = string; // yay python!

using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;

using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>; 
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>; 
using vpd = vector<pd>;

#define tcT template<class T
#define tcTU tcT, class U
// ^ lol this makes everything look weird but I'll try it
tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>; 
tcT> using PR = pair<T,T>;

// pairs
#define mp make_pair
#define f first
#define s second

// vectors
// oops size(x), rbegin(x), rend(x) need C++17
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sor(x) sort(all(x)) 
#define rsz resize
#define ins insert 
#define ft front()
#define bk back()
#define pb push_back
#define eb emplace_back 
#define pf push_front
#define rtn return

#define lb lower_bound
#define ub upper_bound 
tcT> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }

// loops
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)

const int MOD = 1e9+7;
const int MX = 2e5+5;
const ll INF = 1e18; // not too close to LLONG_MAX
const db PI = acos((db)-1);
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;

// bitwise ops
// also see https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
constexpr int pct(int x) { return __builtin_popcount(x); } // # of bits set
constexpr int bits(int x) { // assert(x >= 0); // make C++11 compatible until USACO updates ...
	return x == 0 ? 0 : 31-__builtin_clz(x); } // floor(log2(x)) 
constexpr int p2(int x) { return 1<<x; }
constexpr int msk2(int x) { return p2(x)-1; }

ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down

tcT> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; } // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; }

tcTU> T fstTrue(T lo, T hi, U f) {
	hi ++; assert(lo <= hi); // assuming f is increasing
	while (lo < hi) { // find first index such that f is true 
		T mid = lo+(hi-lo)/2;
		f(mid) ? hi = mid : lo = mid+1; 
	} 
	return lo;
}
tcTU> T lstTrue(T lo, T hi, U f) {
	lo --; assert(lo <= hi); // assuming f is decreasing
	while (lo < hi) { // find first index such that f is true 
		T mid = lo+(hi-lo+1)/2;
		f(mid) ? lo = mid : hi = mid-1;
	} 
	return lo;
}
tcT> void remDup(vector<T>& v) { // sort and remove duplicates
	sort(all(v)); v.erase(unique(all(v)),end(v)); }
tcTU> void erase(T& t, const U& u) { // don't erase
	auto it = t.find(u); assert(it != end(t));
	t.erase(it); } // element that doesn't exist from (multi)set


void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
	cerr << h; if (sizeof...(t)) cerr << ", ";
	DBG(t...); }
#ifdef LOCAL // compile with -DLOCAL
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif
typedef pi T;
T operator+(const T& l, const T& r) {
	return l.f != r.f ? min(l,r) : T{l.f,l.s+r.s}; }

const int SZ = 1<<7;
struct LazySeg { 
	const T ID = {MOD,0}; T comb(T a, T b) { return a+b; }
	T seg[2*SZ]; int lazy[2*SZ]; 
	LazySeg() { F0R(i,2*SZ) seg[i] = {0,0}, lazy[i] = 0; }
	void push(int ind, int L, int R) { /// modify values for current node
		if (L != R) F0R(i,2) lazy[2*ind+i] += lazy[ind]; /// prop to children
		seg[ind].f += lazy[ind]; // dependent on operation
		lazy[ind] = 0; 
	} // recalc values for current node
	void pull(int ind) { seg[ind] = comb(seg[2*ind],seg[2*ind+1]); }
	void build() { ROF(i,1,SZ) pull(i); }
	void upd(int lo,int hi,int inc,int ind=1,int L=0, int R=SZ-1) {
		push(ind,L,R); if (hi < L || R < lo) return;
		if (lo <= L && R <= hi) { 
			lazy[ind] = inc; push(ind,L,R); return; }
		int M = (L+R)/2; upd(lo,hi,inc,2*ind,L,M); 
		upd(lo,hi,inc,2*ind+1,M+1,R); pull(ind);
	}
};
 
ll area(vector<pair<pi,pi>> v) {
	LazySeg L;
	vi y; each(t,v) y.pb(t.s.f), y.pb(t.s.s);
	sort(all(y)); y.erase(unique(all(y)),y.end());
	F0R(i,sz(y)-1) L.seg[SZ+i].s = y[i+1]-y[i];
	L.build();
	vector<array<int,4>> ev; // sweep line
	each(t,v) {
		t.s.f = lb(all(y),t.s.f)-begin(y);
		t.s.s = lb(all(y),t.s.s)-begin(y)-1;
		ev.pb({t.f.f,1,t.s.f,t.s.s});
		ev.pb({t.f.s,-1,t.s.f,t.s.s});
	}
	sort(all(ev));
	ll ans = 0;
	F0R(i,sz(ev)-1) {
		const auto& t = ev[i]; L.upd(t[2],t[3],t[1]);
		int len = y.bk-y.ft-L.seg[1].s; // L.mn[0].f should equal 0
		ans += (ll)(ev[i+1][0]-t[0])*len;
	}
	return ans;
}
};

num f(int v) {
    using benq::pi;
    vector<pair<pi, pi>> rect;
    for (int i = 0; i < n; i++) {
        ar<int, 2> x_range = get_range(a[i][0], v); x_range[1]++;
        ar<int, 2> y_range = get_range(a[i][1], v); y_range[1]++;
        rect.push_back({{x_range[0], x_range[1]}, {y_range[0], y_range[1]}});
    }
    return num(benq::area(rect));

    /*
    vector<pair<int, vector<pair<int, int>>>> keys;
    for (auto e : ev) keys.push_back(e);

    vector<pair<int, int>> y_ev;

    num ans = 0;
    for (int i = 0; i < sz(keys)-1; i++) {
        num c_mul = keys[i+1].first-keys[i].first;
        vector<pair<int, int>>& cur_ev = keys[i].second;
        for (auto c : cur_ev) y_ev.push_back(c);
        sort(y_ev.begin(), y_ev.end());

        num cur_cover = 0;
        int run = 0;
        for (int j = 0; j < sz(y_ev)-1; j++) {
            run += y_ev[j].second;
            num cur_dist = y_ev[j+1].first-y_ev[j].first;
            cur_cover += cur_dist*(run ? 1 : 0);
        }
        ans += c_mul*cur_cover;
    }
    return ans;
    */
}
void solve(){
    cin >> n >> t;
    for (int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1];
    num ans = f(t)*t;

    vector<int> imp;
    for (int i = 0; i < n; i++) for (int j = i+1; j < n; j++) {
        int cur = isect(a[i], a[j]);
        imp.push_back(cur);
    }
    imp.push_back(0), imp.push_back(t);
    sort(imp.begin(), imp.end()); 
    while (sz(imp) && imp.back() > t) imp.pop_back();


    int m = sz(imp);
    const int N_TERMS = 8;
    for (int i = 0; i < m-1; i++) if (imp[i] < imp[i+1]) {
        int a = imp[i], b = imp[i+1]-1;
        int cur_terms = min(N_TERMS, b-a+1);

        //generate the sequence
        vector<num> seq(cur_terms);
        for (int i = 0; i < cur_terms; i++) {
            seq[i] = f(a+i);
            if (i) seq[i] += seq[i-1];
        }

        num seg_val = -1;
        if (cur_terms == b-a+1) seg_val = seq[b-a];
        else {
            LFSR<num> massey(seq);
            for (int i = 0; i < cur_terms; i++) assert(massey[i] == seq[i]);
            seg_val = massey[b-a];
        }
        ans -= seg_val;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}