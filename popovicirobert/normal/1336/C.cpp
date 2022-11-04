#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "

using namespace std;


template <class T, T MOD>
class ModInt;

template <class T, T MOD>
ModInt<T, MOD> lgpow(ModInt<T, MOD> a, ll b) {
    assert(b >= 0);

    ModInt<T, MOD> ans(1);
    while(b > 0) {
        if(b & 1) ans *= a;
        b >>= 1, a *= a;
    }
    return ans;
}

template <class T, T MOD>
ModInt<T, MOD> inv(ModInt<T, MOD> a) {
    return lgpow(a, MOD - 2);
}


template <class T, T MOD> 
class ModInt {

protected:

    T val;

    inline T mod(ll x) const {
        if(llabs(x) >= MOD) {
            x %= MOD;
        }
        return (x < 0 ? MOD : 0) + x;
    }

public:

    explicit ModInt(ll _val = 0) : val(mod(_val)) {}
    ModInt(const ModInt &y) : val(y.val) {}

    ModInt operator +(const ModInt &y) const {
        return ModInt(mod(val + y.val));
    }
    ModInt operator +(const ll &y) const {
        return *this + ModInt(y);
    }
    ModInt operator -(const ModInt &y) const {
        return ModInt(mod(val - y.val));
    }
    ModInt operator -(const ll &y) const {
        return *this - ModInt(y);
    }
    ModInt operator *(const ModInt &y) const {
        return ModInt(mod(1LL * val * y.val));
    }
    ModInt operator *(const ll &y) const {
        return *this * ModInt(y);
    }
    ModInt operator /(const ModInt &y) const {
        return ModInt(mod(1LL * val * inv(y).val));
    }
    ModInt operator /(const ll &y) const {
        return *this / ModInt(y);
    }
    ModInt& operator =(const ModInt &y) {
        val = y.val;
        return *this;
    }
    ModInt& operator =(const ll &y) {
        val = mod(y);
        return *this;
    }

    bool operator ==(const ModInt &y) const {
        return val == y.val;
    }
    bool operator ==(const ll &y) const {
        return val == y;
    }
    bool operator !=(const ModInt &y) const {
        return val != y.val;
    }
    bool operator !=(const ll &y) const {
        return val != y;
    }
    bool operator <(const ModInt &y) const {
        return val < y.val;
    }
    bool operator <(const ll &y) const {
        return val < y;
    }
    bool operator <=(const ModInt &y) const {
        return val <= y.val;
    }
    bool operator <=(const ll &y) const {
        return val <= y;
    }
    bool operator >(const ModInt &y) const {
        return val > y.val;
    }
    bool operator >(const ll &y) const {
        return val > y;
    }
    bool operator >=(const ModInt &y) const {
        return val >= y.val;
    }
    bool operator >=(const ll &y) const {
        return val >= y;
    }

    ModInt& operator +=(const ModInt &y) {
        val = mod(val + y.val);
        return *this;
    }
    ModInt& operator +=(const ll &y) {
        val = mod(val + y);
        return *this;
    }
    ModInt& operator -=(const ModInt &y) {
        val = mod(val - y.val);
        return *this;
    }
    ModInt& operator -=(const ll &y) {
        val = mod(val - y);
        return *this;
    }
    ModInt& operator *=(const ModInt &y) {
        val = mod(1LL * val * y.val);
        return *this;
    }
    ModInt& operator *=(const ll &y) {
        val = mod(1LL * val * y);
        return *this;
    }
    ModInt& operator /=(const ModInt &y) {
        val = mod(1LL * val * inv(y));
        return *this;
    }
    ModInt& operator /=(const ll &y) {
        val = mod(1LL * val * inv(ModInt(y)));
        return *this;
    }

    ModInt& operator ++() {
        val = mod(val + 1);
        return *this;
    }
    ModInt& operator ++(int) {
        val = mod(val + 1);
        return *this;
    }
    ModInt& operator --() {
        val = mod(val - 1);
        return *this;
    }
    ModInt& operator --(int) {
        val = mod(val - 1);
        return *this;
    }

    operator int() const {
        return (int)val;
    }
    operator ll() const {
        return (ll)val;
    }


    template <class U, U mod> friend std::ostream& operator <<(std::ostream &stream, const ModInt<U, mod> &x);
    template <class U, U mod> friend std::istream& operator >>(std::istream &stream, ModInt<U, mod> &x);

    friend ModInt operator +(ll x, const ModInt &y) {
        return ModInt(x) + y;
    }
    friend ModInt operator -(ll x, const ModInt &y) {
        return ModInt(x) - y;
    }
    friend ModInt operator *(ll x, const ModInt &y) {
        return ModInt(x) * y;
    }
    friend ModInt operator /(ll x, const ModInt &y) {
        return ModInt(x) / y;
    }
    friend ModInt operator +=(ll x, const ModInt &y) {
        return ModInt(x) + y;
    }
    friend ModInt operator -=(ll x, const ModInt &y) {
        return ModInt(x) - y;
    }
    friend ModInt operator *=(ll x, const ModInt &y) {
        return ModInt(x) * y;
    }
    friend ModInt operator /=(ll x, const ModInt &y) {
        return ModInt(x) / y;
    }

};

template <class T, T MOD>
std::istream& operator >>(std::istream &stream, ModInt<T, MOD> &x) {
    ll cur;
    stream >> cur;
    x = ModInt<T, MOD>(cur);
    return stream;
}

template <class T, T MOD>
std::ostream& operator <<(std::ostream &stream, const ModInt<T, MOD> &x) {
    return stream << x.val;
}

const int MOD = (int) 998244353;

using Mint = ModInt<int, MOD>;


int main() {
#ifdef HOME
    ifstream cin("B.in");
    ofstream cout("B.out");
#endif
    int i, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

   	string s, t; cin >> s >> t;
   	n = s.size(), m = t.size();

   	s = " " + s;
   	t = " " + t;

   	vector<vector<Mint>> dp(n + 1, vector<Mint>(n + 1));
   	for(i = 1; i <= n; i++) {
   		if(i > m || t[i] == s[1]) {
   			dp[i][i] = 2;
   		}
   	}
   	for(int len = 2; len <= n; len++) {
   		for(int l = 1; l + len - 1 <= n; l++) {
   			int r = l + len - 1;
   			if(l > m || s[len] == t[l]) {
   				dp[l][r] += dp[l + 1][r];
   			}
   			if(r > m || s[len] == t[r]) {
   				dp[l][r] += dp[l][r - 1];
   			}
   		} 
   	}
   	Mint ans(0);
   	for(i = m; i <= n; i++) {
   		ans += dp[1][i];
   	}
   	cout << ans;

    return 0;
}