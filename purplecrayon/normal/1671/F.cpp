#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 46, MOD = 998244353;

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

template <typename num>
std::vector<num> BerlekampMassey(const std::vector<num>& s) {
	int n = int(s.size()), L = 0, m = 0;
	std::vector<num> C(n), B(n), T;
	C[0] = B[0] = 1;

	num b = 1;
	for(int i = 0; i < n; i++) { ++m;
		num d = s[i];
		for (int j = 1; j <= L; j++) d += C[j] * s[i - j];
		if (d == 0) continue;
		T = C; num coef = d / b;
		for (int j = m; j < n; j++) C[j] -= coef * B[j - m];
		if (2 * L > i) continue;
		L = i + 1 - L; B = T; b = d; m = 0;
	}

	C.resize(L + 1); C.erase(C.begin());
	for (auto& x : C) {
		x = -x;
	}
	return C;
}
template <typename num>
num linearRec(const std::vector<num>& S, const std::vector<num>& tr, long long k) {
	int n = int(tr.size());
	assert(S.size() >= tr.size());

	auto combine = [&](std::vector<num> a, std::vector<num> b) {
		std::vector<num> res(n * 2 + 1);
		for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) res[i + j] += a[i] * b[j];
		for (int i = 2 * n; i > n; --i) for (int j = 0; j < n; j++)
			res[i - 1 - j] += res[i] * tr[j];
		res.resize(n + 1);
		return res;
	};

	std::vector<num> pol(n + 1), e(pol);
	pol[0] = e[1] = 1;

	for (++k; k; k /= 2) {
		if (k % 2) pol = combine(pol, e);
		e = combine(e, e);
	}

	num res = 0;
	for (int i = 0; i < n; i++) res += pol[i + 1] * S[i];
	return res;
}


using num = modnum<MOD>;

const int K = 12;
num dp[N][K][K][K];
vector<num> store[K][K], massey[K][K];


void pre() {
    dp[1][0][0][0] = 1;
    for (int n = 2; n < N; n++) {
        for (int p = 0; p < min(n-1, K); p++) { // pth element from the back
            for (int k = 0; k < K; k++) {
                for (int x = 0; x < K; x++) {
                    for (int m = 0; m < n && k + m < K && x + (m > p) < K; m++) {
                        // right after the mth element from the back
                        dp[n][m][k + m][x + (m > p)] += dp[n-1][p][k][x];
                    }
                }
            }
        }
    }
    for (int k = 0; k < K; k++) {
        for (int x = 0; x < K; x++) {
            vector<num> seq(N);
            for (int n = 1; n < N; n++) {
                for (int m = 0; m < min(n, K); m++) seq[n] += dp[n][m][k][x];
            }
            store[k][x] = seq;
            massey[k][x] = BerlekampMassey(seq);
        }
    }
}
void solve() {
    int n, k, x; cin >> n >> k >> x;
    cout << linearRec(store[k][x], massey[k][x], n) << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    pre();
    int T = 1;
    cin >> T;
    while (T--) solve();
}