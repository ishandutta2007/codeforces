#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define uint unsigned int


using namespace std;


template <typename T, T MOD>
class ModInt;

template <typename T, T MOD>
ModInt<T, MOD> lgpow(ModInt<T, MOD> a, ll b) {
    assert(b >= 0);

    ModInt<T, MOD> ans(1);
    while(b > 0) {
        if(b & 1) ans *= a;
        b >>= 1, a *= a;
    }
    return ans;
}

template <typename T, T MOD>
ModInt<T, MOD> inv(ModInt<T, MOD> a) {
    return lgpow(a, MOD - 2);
}

template <typename T, T MOD>
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
    bool operator ==(const T &y) const {
        return val == y;
    }
    bool operator !=(const ModInt &y) const {
        return val != y.val;
    }
    bool operator !=(const T &y) const {
        return val != y;
    }
    bool operator <(const ModInt &y) const {
        return val < y.val;
    }
    bool operator <(const T &y) const {
        return val < y;
    }
    bool operator <=(const ModInt &y) const {
        return val <= y.val;
    }
    bool operator <=(const T &y) const {
        return val <= y;
    }
    bool operator >(const ModInt &y) const {
        return val > y.val;
    }
    bool operator >(const T &y) const {
        return val > y;
    }
    bool operator >=(const ModInt &y) const {
        return val >= y.val;
    }
    bool operator >=(const T &y) const {
        return val >= y;
    }

    ModInt& operator +=(const ModInt &y) {
        val = mod(val + y.val);
        return *this;
    }
    ModInt& operator +=(const T &y) {
        val = mod(val + y);
        return *this;
    }
    ModInt& operator -=(const ModInt &y) {
        val = mod(val - y.val);
        return *this;
    }
    ModInt& operator -=(const T &y) {
        val = mod(val - y);
        return *this;
    }
    ModInt& operator *=(const ModInt &y) {
        val = mod(1LL * val * y.val);
        return *this;
    }
    ModInt& operator *=(const T &y) {
        val = mod(1LL * val * y);
        return *this;
    }
    ModInt& operator /=(const ModInt &y) {
        val = mod(1LL * val * inv(y.val));
        return *this;
    }
    ModInt& operator /=(const T &y) {
        val = mod(1LL * val * inv(y));
        return *this;
    }

    ModInt& operator ++() {
        val = mod(val + 1);
        return *this;
    }
    ModInt operator ++(int) {
        ModInt ans(val);
        val = mod(val + 1);
        return ans;
    }
    ModInt& operator --() {
        val = mod(val - 1);
        return *this;
    }
    ModInt operator --(int) {
        ModInt ans(val);
        val = mod(val - 1);
        return ans;
    }

    operator int() const {
        return (int)val;
    }
    operator ll() const {
        return (ll)val;
    }


    friend std::ostream& operator <<(std::ostream &stream, const ModInt &x) {
        return stream << x.val;
    }
    friend std::istream& operator >>(std::istream &stream, ModInt &x) {
        ll cur;
        stream >> cur;
        x = ModInt<T, MOD>(cur);
        return stream;
    }

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


const int MOD = (int) 1e9 + 7;

using Mint = ModInt<int, MOD>;

int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, j, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    vector <int> a(n + 1);
    for(i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector <int> num(n + 1), sz;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= i; j++) {
            ll cur = 1LL * a[i] * a[j];
            ll sq = sqrt(cur);
            while(sq * sq < cur) {
                sq++;
            }
            while(sq * sq > cur) {
                sq--;
            }
            if(sq * sq == cur) {
               num[j]++;
               break;
            }
        }
    }

    for(i = 1; i <= n; i++) {
        if(num[i])
            sz.push_back(num[i]);
    }

    vector < vector <Mint> > comb(n + 1, vector <Mint>(n + 1));
    for(i = 0; i <= n; i++) {
        comb[i][0] = 1;
        for(j = 1; j <= i; j++) {
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
        }
    }

    vector < vector <Mint> > dp(sz.size(), vector <Mint>(n + 1));
    dp[0][sz[0] - 1] = 1;

    int tot = 0;
    for(i = 0; i + 1 < sz.size(); i++) {
        tot += sz[i];
        for(j = 0; j <= tot; j++) {
            if(dp[i][j] == 0) continue;

            for(int a = 0; a <= j; a++) {
                for(int b = max(a, 1); b <= sz[i + 1]; b++) {
                    dp[i + 1][j - a + sz[i + 1] - b] += dp[i][j] * comb[j][a] * comb[tot + 1 - j][b - a] * comb[sz[i + 1] - 1][b - 1];
                }
            }
        }
    }

    vector <Mint> fact(n + 1);

    fact[0] = 1;
    for(i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i;
    }

    Mint ans = dp[sz.size() - 1][0];
    for(auto it : sz) {
        ans *= fact[it];
    }

    cout << ans;

    return 0;
}