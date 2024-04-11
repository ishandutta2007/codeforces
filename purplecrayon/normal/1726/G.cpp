#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 6e5+10, MOD = 998244353;

// observation (0.0):
//      - the final value must be equal to min + n - 1 (call this M)
//          - it has to get + from everything else since they will all be bigger than it, if it doesn't then it's auto bad
//          - assume M > max (if not, max can be put literally anywhere if it's a 1, otherwise it must be at the end)
//

// 0's -> increases from telling people with less
// 1's -> increases from telling people with more
//
// claim (1.0): 0's must be sorted in increasing order
//      - proof: if x goes before y and x > y x increases strictly more than y (less elements come before and initially starts with a greater value anyway)
//
// claim (1.1): the order of 1's is fixed
//      - let b[x] = a[x] + (number of elements > a[x])
//      - the amount increased is b[x] + (number of elements already processed <= a[x])
//      - if you have x and y s.t. b[x] > b[y] && a[x] > a[y], then x must come before y
//      - in general, just the constructive algorithm of building the array proves both claims 1.0 and 1.1, you're never given a choice
//
// collorally of claims 1.0 and 1.1:
//      - the ordering is fixed, you just get the factor from observation 0.0 and the ordering of equal numbers
//      - implies that all that needs to be checked is if the answer is = 0
//
// algorithm: O(n^2):
//      - maintain a set of the items that you can use at any point that produce a valid value
//      - if there are multiple, pick the largest
//          - if two are tied for largest, pick the 1 before the 0's (you can't have multiple 1's with the same value)
// 
// observation 2.0:
//      - the 0's must be sorted in increasing order, so it's easy to check whether you should insert a 0
//      - maintaining the 1's can be done with a simple segtree, everytime you use a value you just increase the potential of all 1's greater than it (potential = value after choosing it)
//      - the candidate 1 to choose is the one with maximum (potential, original value)
//          - you want to maximize potential first because that ensures that you only pick values that can be chosen in the current iteration
// 

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

num fact[N], ifact[N];

void pre() {
    fact[0] = ifact[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = fact[i-1]*i;
    ifact[N-1] = inv(fact[N-1]);
    for (int i = N-2; i > 0; i--) ifact[i] = ifact[i+1]*num(i+1);
}
num nck(int n, int k) {
    if (n < k || k < 0 || n < 0) return 0;
    return fact[n] * ifact[k] * ifact[n-k];
}

template<class T>
struct FT {
    vector<T> bit;
    FT(int n) : bit(n) {}
    FT(){}
    void upd(int i, T x) {
        for (; i < sz(bit); i |= i+1) bit[i] += x;
    }
    T qry(int r) {
        T ans = T();
        for (++r; r > 0; r &= r-1) ans += bit[r-1];
        return ans;
    }
    T qry(int l, int r) {
        if (l > r) return T();
        return qry(r)-qry(l-1);
    }
};

struct Tree {
    int n;
    vector<pair<int, int>> t;
    vector<int> lzy;

    Tree(const vector<int>& a) {
        n = sz(a);
        t.resize(4 * n);
        lzy.resize(4 * n);
        build(1, 0, n-1, a);
    }
    void build(int v, int tl, int tr, const vector<int>& a) {
        lzy[v] = 0;
        if (tl == tr) {
            t[v] = {a[tl], tl};
        } else {
            int tm = (tl + tr) / 2;
            build(2*v, tl, tm, a), build(2*v+1, tm+1, tr, a);
            t[v] = max(t[2*v], t[2*v+1]);
        }
    }
    void push(int v, int tl, int tr, int x) {
        t[v].first += x;
        if (tl != tr) {
            lzy[2*v] += x;
            lzy[2*v+1] += x;
        }
    }
    void app(int v, int tl, int tr) {
        push(v, tl, tr, lzy[v]), lzy[v] = 0;
    }
    void upd(int v, int tl, int tr, int l, int r, int x) {
        app(v, tl, tr);
        if (r < tl || l > tr) return;
        if (l <= tl && tr <= r) {
            push(v, tl, tr, x);
            return;
        }
        int tm = (tl + tr) / 2;
        upd(2*v, tl, tm, l, r, x), upd(2*v+1, tm+1, tr, l, r, x);
        t[v] = max(t[2*v], t[2*v+1]);
    }
    void upd(int l, int r, int x) {
        upd(1, 0, n-1, l, r, x);
    }
    pair<int, int> qry(int v, int tl, int tr, int l, int r) {
        app(v, tl, tr);
        if (r < tl || l > tr) return {-MOD, -MOD};
        if (l <= tl && tr <= r) return t[v];
        int tm = (tl + tr) / 2;
        return max(qry(2*v, tl, tm, l, r), qry(2*v+1, tm+1, tr, l, r));
    }
    pair<int, int> qry(int l, int r) {
        return qry(1, 0, n-1, l, r);
    }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x, --x;
    vector<int> type(n); for (auto& x : type) cin >> x;

    int mn = *min_element(a.begin(), a.end());
    int mx = *max_element(a.begin(), a.end());
    if (mn == mx) {
        cout << fact[n] << '\n';
        return;
    }

    int M = mn + n - 1;
    if (mx > M) {
        cout << 0 << '\n';
        return;
    }
    vector<int> o, z;

    for (int i = 0; i < n; i++) {
        (type[i] ? o : z).push_back(a[i]);
    }
    sort(o.begin(), o.end());
    sort(z.begin(), z.end());
    int cnt_M = 0;
    int cnt_M_o = 0, cnt_M_z = 0;
    while (sz(o) && o.back() == M) {
        cnt_M++, cnt_M_o++;
        o.pop_back();
    }
    while (sz(z) && z.back() == M) {
        cnt_M++, cnt_M_z++;
        z.pop_back();
    }

    for (int i = 1; i < sz(o); i++) if (o[i] == o[i-1]) {
        cout << 0 << '\n';
        return;
    }

    FT<int> unused(M);
    for (int x : o) unused.upd(x, +1);
    for (int x : z) unused.upd(x, +1);

    vector<int> pot_o(M, -MOD);
    for (int x : o) {
        pot_o[x] = x + unused.qry(x + 1, M - 1) + cnt_M;
    }
    Tree pot_tree(pot_o);

    // range increment pot_o, range max segtree of {pot_o[i], i}
    
    int p_z = 0;
    for (int i = 0; i < n - cnt_M; i++) {
        pair<int, int> me{-1, -1};
        if (p_z < sz(z) && unused.qry(0, z[p_z] - 1) + z[p_z] == M) {
            me = max(me, pair<int, int>{z[p_z], 0});
        }
        auto one = pot_tree.qry(0, M-1);
        if (one.first > M) {
            cout << 0 << '\n';
            return;
        }
        if (one.first == M) {
            me = max(me, pair<int, int>{one.second, 1});
        }
        /*
        for (int i = 0; i < M; i++) {
            if (pot_o[i] > M) {
                cout << 0 << '\n';
                return;
            }
            if (pot_o[i] == M) { // TODO SLOW
                me = max(me, ar<int, 2>{i, 1});
            }
        }
        */
        if (me.second == 0) {
            p_z++;
        } else if (me.second == 1) {
            /*
            pot_o[me[0]] = -MOD;
            for (int j = me[0] + 1; j < M; j++) pot_o[j]++; // TODO SLOW
            */
            pot_tree.upd(me.first, me.first, -MOD);
            pot_tree.upd(me.first + 1, M - 1, +1);
        } else if (me.second == -1) {
            cout << 0 << '\n';
            return;
        } else assert(false);

        unused.upd(me.first, -1);
    }
    map<int, int> cnt_z, cnt_o;
    for (int x : z) cnt_z[x]++;
    for (int x : o) cnt_o[x]++;

    num ans = fact[cnt_M_o] * fact[cnt_M_z] * nck(n, cnt_M_o);
    for (auto [_, k] : cnt_z) ans *= fact[k];
    for (auto [_, k] : cnt_o) ans *= fact[k];
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    pre();
    int T = 1;
    // cin >> T;
    while (T--) solve();
}