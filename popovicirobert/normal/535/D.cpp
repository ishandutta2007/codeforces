#include <bits/stdc++.h>
#define ull unsigned long long

using namespace std;

const int MOD1 = (int) 1e9 + 7;
const int MOD2 = (int) 1e9 + 9;
const int MAXN = (int) 1e6 + 5;
const int B = 666013;

char sol[MAXN + 1], a[MAXN + 1];

inline int lgput(int a, int b, int md) {
    int ans = 1;
    while(b > 0) {
        if(b & 1) ans = (1LL * ans * a) % md;
        b >>= 1;
        a = (1LL * a * a) % md;
    }
    return ans;
}

template <int MOD1, int MOD2>
struct Hash {
    int hsh1, hsh2;
    Hash(int _hsh1, int _hsh2) {
        hsh1 = _hsh1, hsh2 = _hsh2;
    }

    Hash() : hsh1(0), hsh2(0) {}

    Hash operator +(const Hash &other) const{
        Hash ans(hsh1, hsh2);
        ans.hsh1 += other.hsh1;
        if(ans.hsh1 >= MOD1) {
            ans.hsh1 -= MOD1;
        }
        ans.hsh2 += other.hsh2;
        if(ans.hsh2 >= MOD2) {
            ans.hsh2 -= MOD2;
        }
        return ans;
    }

    Hash operator +(const int &x) const{
        Hash ans(hsh1, hsh2);
        ans.hsh1 += x;
        if(ans.hsh1 >= MOD1) {
            ans.hsh1 -= MOD1;
        }
        ans.hsh2 += x;
        if(ans.hsh2 >= MOD2) {
            ans.hsh2 -= MOD2;
        }
        return ans;
    }

    Hash operator -(const Hash &other) const{
        Hash ans(hsh1, hsh2);
        ans.hsh1 += MOD1 - other.hsh1;
        if(ans.hsh1 >= MOD1) {
            ans.hsh1 -= MOD1;
        }
        ans.hsh2 += MOD2 - other.hsh2;
        if(ans.hsh2 >= MOD2) {
            ans.hsh2 -= MOD2;
        }
        return ans;
    }

    Hash operator -(const int &x) const{
        Hash ans(hsh1, hsh2);
        ans.hsh1 += MOD1 - x;
        if(ans.hsh1 >= MOD1) {
            ans.hsh1 -= MOD1;
        }
        ans.hsh2 += MOD2 - x;
        if(ans.hsh2 >= MOD2) {
            ans.hsh2 -= MOD2;
        }
        return ans;
    }

    Hash operator *(const Hash &other) const{
        Hash ans(hsh1, hsh2);
        ans.hsh1 = (1LL * ans.hsh1 * other.hsh1) % MOD1;
        ans.hsh2 = (1LL * ans.hsh2 * other.hsh2) % MOD2;
        return ans;
    }

    Hash operator *(const int &x) const{
        Hash ans(hsh1, hsh2);
        ans.hsh1 = (1LL * ans.hsh1 * x) % MOD1;
        ans.hsh2 = (1LL * ans.hsh2 * x) % MOD2;
        return ans;
    }

    Hash operator /(const Hash &other) const{
        Hash ans(hsh1, hsh2);
        ans.hsh1 = (1LL * ans.hsh1 * lgput(other.hsh1, MOD1 - 2, MOD1)) % MOD1;
        ans.hsh2 = (1LL * ans.hsh2 * lgput(other.hsh2, MOD2 - 2, MOD2)) % MOD2;
        return ans;
    }

    Hash operator /(const int &x) const{
        Hash ans(hsh1, hsh2);
        ans.hsh1 = (1LL * ans.hsh1 * lgput(x, MOD1 - 2, MOD1)) % MOD1;
        ans.hsh2 = (1LL * ans.hsh2 * lgput(x, MOD2 - 2, MOD2)) % MOD2;
        return ans;
    }

    void operator =(const Hash &other) {
        hsh1 = other.hsh1, hsh2 = other.hsh2;
    }

    bool operator ==(const Hash &other) const{
        return (hsh1 == other.hsh1 && hsh2 == other.hsh2);
    }
};

Hash <MOD1, MOD2> pw[MAXN + 1];
Hash <MOD1, MOD2> hsh[MAXN + 1];

int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, j, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> a + 1;
    Hash <MOD1, MOD2> val = Hash<MOD1, MOD2>(0, 0);
    int sz = strlen(a + 1);

    for(i = 1; i <= sz; i++) {
        val = val * B + a[i] - 'a' + 1;
    }

    vector <int> p(m + 1);
    int last = 0;

    for(i = 1; i <= m; i++) {
        cin >> p[i];
        int pos = max(last, i);
        for(j = pos; j <= p[i] + sz - 1; j++) {
            sol[j] = a[j - p[i] + 1];
        }
        last = max(last, p[i] + sz);
    }

    pw[0] = Hash<MOD1, MOD2>(1, 1);
    for(i = 1; i <= n; i++) {
        pw[i] = pw[i - 1] * B;
    }

    int ans = 1;
    for(i = n; i >= 1; i--) {
        if(sol[i] == 0) {
            ans = (1LL * ans * 26) % MOD1;
            sol[i] = 'a';
        }
        hsh[i] = hsh[i + 1] + pw[n - i] * (sol[i] - 'a' + 1);
    }

    for(i = 1; i <= m; i++) {
        if(hsh[p[i]] - hsh[p[i] + sz] == val * pw[n - (p[i] + sz - 1)]) {

        }
        else {
            ans = 0;
        }
    }

    cout << ans;

    return 0;
}