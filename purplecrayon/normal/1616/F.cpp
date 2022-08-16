#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

// https://judge.yosupo.jp/submission/42190
namespace Mat {
    template <class T>
    struct Matrix {
      vector<vector<T> > A;

      Matrix() = default;
      Matrix(int n, int m) : A(n, vector<T>(m, T())) {}
      Matrix(int n) : A(n, vector<T>(n, T())){};

      int H() const { return A.size(); }

      int W() const { return A[0].size(); }

      int size() const { return A.size(); }

      inline const vector<T> &operator[](int k) const { return A[k]; }

      inline vector<T> &operator[](int k) { return A[k]; }

      static Matrix I(int n) {
        Matrix mat(n);
        for (int i = 0; i < n; i++) mat[i][i] = 1;
        return (mat);
      }

      Matrix &operator+=(const Matrix &B) {
        int n = H(), m = W();
        assert(n == B.H() && m == B.W());
        for (int i = 0; i < n; i++)
          for (int j = 0; j < m; j++) (*this)[i][j] += B[i][j];
        return (*this);
      }

      Matrix &operator-=(const Matrix &B) {
        int n = H(), m = W();
        assert(n == B.H() && m == B.W());
        for (int i = 0; i < n; i++)
          for (int j = 0; j < m; j++) (*this)[i][j] -= B[i][j];
        return (*this);
      }

      Matrix &operator*=(const Matrix &B) {
        int n = H(), m = B.W(), p = W();
        assert(p == B.H());
        vector<vector<T> > C(n, vector<T>(m, 0));
        for (int i = 0; i < n; i++)
          for (int k = 0; k < p; k++)
            for (int j = 0; j < m; j++) C[i][j] += (*this)[i][k] * B[k][j];
        A.swap(C);
        return (*this);
      }

      Matrix &operator^=(long long k) {
        Matrix B = Matrix::I(H());
        while (k > 0) {
          if (k & 1) B *= *this;
          *this *= *this;
          k >>= 1LL;
        }
        A.swap(B.A);
        return (*this);
      }

      Matrix operator+(const Matrix &B) const { return (Matrix(*this) += B); }

      Matrix operator-(const Matrix &B) const { return (Matrix(*this) -= B); }

      Matrix operator*(const Matrix &B) const { return (Matrix(*this) *= B); }

      Matrix operator^(const long long k) const { return (Matrix(*this) ^= k); }

      bool operator==(const Matrix &B) const {
        assert(H() == B.H() && W() == B.W());
        for (int i = 0; i < H(); i++)
          for (int j = 0; j < W(); j++)
            if (A[i][j] != B[i][j]) return false;
        return true;
      }

      bool operator!=(const Matrix &B) const {
        assert(H() == B.H() && W() == B.W());
        for (int i = 0; i < H(); i++)
          for (int j = 0; j < W(); j++)
            if (A[i][j] != B[i][j]) return true;
        return false;
      }

      friend ostream &operator<<(ostream &os, const Matrix &p) {
        int n = p.H(), m = p.W();
        for (int i = 0; i < n; i++) {
          os << (i ? "   " : "") << "[";
          for (int j = 0; j < m; j++) {
            os << p[i][j] << (j + 1 == m ? "]\n" : ",");
          }
        }
        return (os);
      }

      T determinant() const {
        Matrix B(*this);
        assert(H() == W());
        T ret = 1;
        for (int i = 0; i < H(); i++) {
          int idx = -1;
          for (int j = i; j < W(); j++) {
            if (B[j][i] != 0) {
              idx = j;
              break;
            }
          }
          if (idx == -1) return 0;
          if (i != idx) {
            ret *= T(-1);
            swap(B[i], B[idx]);
          }
          ret *= B[i][i];
          T inv = T(1) / B[i][i];
          for (int j = 0; j < W(); j++) {
            B[i][j] *= inv;
          }
          for (int j = i + 1; j < H(); j++) {
            T a = B[j][i];
            if (a == 0) continue;
            for (int k = i; k < W(); k++) {
              B[j][k] -= B[i][k] * a;
            }
          }
        }
        return ret;
      }
    };

    /**
     * @brief ???????
     */


    template <typename mint>
    std::pair<int, mint> GaussElimination(vector<vector<mint>> &a,
                                          bool LE = false) {
      int H = a.size(), W = a[0].size();
      int rank = 0, je = LE ? W - 1 : W;
      mint det = 1;
      for (int j = 0; j < je; j++) {
        int idx = -1;
        for (int i = rank; i < H; i++) {
          if (a[i][j] != mint(0)) {
            idx = i;
            break;
          }
        }
        if (idx == -1) {
          det = 0;
          continue;
        }
        if (rank != idx) {
          det = -det;
          swap(a[rank], a[idx]);
        }
        det *= a[rank][j];
        if (LE && a[rank][j] != mint(1)) {
          mint coeff = a[rank][j].inv();
          for (int k = j; k < W; k++) a[rank][k] *= coeff;
        }
        int is = LE ? 0 : rank + 1;
        for (int i = is; i < H; i++) {
          if (i == rank) continue;
          if (a[i][j] != mint(0)) {
            mint coeff = a[i][j] / a[rank][j];
            for (int k = j; k < W; k++) a[i][k] -= a[rank][k] * coeff;
          }
        }
        rank++;
      }
      return make_pair(rank, det);
    }

    template <typename mint>
    vector<vector<mint>> LinearEquation(vector<vector<mint>> a, vector<mint> b) {
      int H = a.size(), W = a[0].size();
      for (int i = 0; i < H; i++) a[i].push_back(b[i]);
      auto p = GaussElimination(a, true);
      int rank = p.first;

      for (int i = rank; i < H; ++i) {
        if (a[i][W] != 0) return vector<vector<mint>>{};
      }

      vector<vector<mint>> res(1, vector<mint>(W));
      vector<int> pivot(W, -1);
      for (int i = 0, j = 0; i < rank; ++i) {
        while (a[i][j] == 0) ++j;
        res[0][j] = a[i][W], pivot[j] = i;
      }
      for (int j = 0; j < W; ++j) {
        if (pivot[j] == -1) {
          vector<mint> x(W);
          x[j] = 1;
          for (int k = 0; k < j; ++k) {
            if (pivot[k] != -1) x[k] = -a[pivot[k]][j];
          }
          res.push_back(x);
        }
      }
      return res;
    }
};
using namespace Mat;

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
using num = modnum<3>;

void solve() {
    int n, m; cin >> n >> m;
    vector<ar<int, 3>> ed(m);
    vector<vector<int>> adj(n, vector<int>(n, -1));
    vector<vector<num>> eq;
    vector<num> res;
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c, --a, --b;
        ed[i] = {a, b, c};
        adj[a][b] = adj[b][a] = i;
        if (c != -1) {
            vector<num> row(m);
            row[i] = 1;
            eq.push_back(row);

            res.emplace_back(c);
        }
    }
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < a; b++) {
            for (int c = 0; c < b; c++) {
                int x = adj[a][b];
                int y = adj[b][c];
                int z = adj[c][a];
                if (x != -1 && y != -1 && z != -1) {
                    vector<num> row(m);
                    row[x] = row[y] = row[z] = 1;
                    eq.push_back(row);

                    res.emplace_back(0);
                }
            }
        }
    }
    /*
    for (int i = 0; i < sz(eq); i++) {
        for (auto x : eq[i]) cerr << x << ' ';
        cerr << "  -> " << res[i] << '\n';
    }
    */
    vector<num> v;
    if (sz(eq) == 0) {
        v.assign(n, 0);
    } else {
        auto get = LinearEquation<num>(eq, res);
        if (sz(get) == 0) {
            cout << -1 << '\n';
            return;
        }
        v = get[0];
    }
    for (int i = 0; i < m; i++) {
        int ans = int(v[i]);
        if (v[i] == 0) ans = 3;
        cout << ans << ' ';
    }
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}