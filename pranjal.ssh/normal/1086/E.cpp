#include <bits/stdc++.h>
using namespace std;

#define cerr cout
#define F first
#define S second
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(auto i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
string to_string(string s) { return '"' + s + '"';}
string to_string(char s) { return string(1, s);}
string to_string(const char* s) { return to_string((string) s);}
string to_string(bool b) { return (b ? "true" : "false");}
template <typename A> string to_string(A);
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A> string to_string(A v) {bool f = 1; string r = "{"; for (const auto &x : v) {if (!f)r += ", "; f = 0; r += to_string(x);} return r + "}";}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cerr << " " << to_string(H); debug_out(T...);}
#define pr(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)


template<int MOD>
struct ModInt {
    static const int Mod = MOD;
    unsigned x;
    ModInt() : x(0) {}
    ModInt(signed sig) { int sigt = sig % MOD; if (sigt < 0) sigt += MOD; x = sigt; }
    ModInt(signed long long sig) { int sigt = sig % MOD; if (sigt < 0) sigt += MOD; x = sigt; }
    int get() const { return (int)x; }
    bool operator==(ModInt that) const {return this->x == that.x;}

    ModInt &operator+=(ModInt that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator-=(ModInt that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
    ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }
    ModInt &operator^=(ModInt<MOD - 1> that) { *this = that; return *this; }

    friend ostream& operator<<(ostream& out, const ModInt& yo) { out << yo.x; return out; }

    ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
    ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
    ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
    ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }

    ModInt operator^(ModInt<MOD - 1> that) const {
    	ModInt ans = 1;
    	ModInt a = *this;
    	while (that.x > 0) {
    		if (that.x & 1) ans = ans * a;
    		a = a * a;
    		that.x >>= 1;
    	}
    	return ans;
    }

    ModInt inverse() const {
        signed a = x, b = MOD, u = 1, v = 0;
        while (b) {
            signed t = a / b;
            a -= t * b; std::swap(a, b);
            u -= t * v; std::swap(u, v);
        }
        if (u < 0) u += Mod;
        ModInt res; res.x = (unsigned)u;
        return res;
    }
};
template<int MOD> string to_string(ModInt<MOD> x) {return to_string(x.x);}
typedef ModInt<998244353> mint;

const int N = 2048;
mint f[N+1], d[N+1], finv[N + 1];
int a[N][N];
bitset<N> bt[N];
bitset<N> prefix[N];
mint dp[N+1][N+1];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	dp[0][0] = 1; dp[1][1] = 1;
	f[0] = 1, f[1] = 1; finv[1] = 1;
	d[0] = 1, d[1] = 0;
	prefix[1][1] = 1;
	FOR (i, 2, N) {
		f[i] = f[i - 1] * i;
		d[i] = (d[i - 1] + d[i - 2]) * (i - 1);
		prefix[i] = prefix[i - 1];
		prefix[i][i] = 1;
		finv[i] = finv[i - 1] / i;

		dp[i][0] = d[i];
		FOR (j, 1, i) {
			dp[i][j] = dp[i-1][j-1] * j + dp[i-1][j] * (i - j);
		}
	}
	

	int n; cin >> n;
	FOR (i, 1, n) {
		FOR (j, 1, n) {
			cin >> a[i][j];
		}
	}
	mint ans = 0;
	FOR (i, 1, n) {
		mint down = (d[n] ^ (n - i));
		bitset<N> cur;
		FOR (j, 1, n) {
			if (i == 1) {
				int fc = (prefix[a[i][j] - 1] & cur.flip()).count();
				ans += f[n - j] * down * fc;
			} else {
				int ad = (bt[j + 1] & cur).count();
				auto can = prefix[a[i][j] - 1];
				can[a[i-1][j]] = 0;
				can &= cur.flip();
				int fc = (can & bt[j + 1]).count();
				int dc = can.count() - fc;
				int tot = n - j;
				ans += down * (dp[tot][ad + 1] * fc + dp[tot][ad] * dc);
				// pr(i, j, fc, dc, ad, tot);
			}
			cur.flip();
			cur[a[i][j]] = 1;
		}
		NFOR (j, n, 1) {
			bt[j] = bt[j + 1];
			bt[j][a[i][j]] = 1;
		}
	}
	cout << ans << "\n";
	
	return 0;
}