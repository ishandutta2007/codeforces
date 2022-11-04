#include <bits/stdc++.h>
#define ull unsigned long long

using namespace std;

const int MAXN = (int) 1e5 + 5;

const int MOD1 = (int) 1e9 + 7;
const int MOD2 = (int) 1e9 + 9;
const int B = 666013;


template <int MOD1, int MOD2>
struct Hash {
    int hsh1, hsh2;
    Hash(int _hsh1, int _hsh2) {
        hsh1 = _hsh1, hsh2 = _hsh2;
    }

    Hash() : hsh1(0), hsh2(0) {}

    bool operator <(const Hash &other) const {
        if(hsh1 == other.hsh1) return hsh2 < other.hsh2;
        return hsh1 < other.hsh1;
    }

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

    void operator =(const Hash &other) {
        hsh1 = other.hsh1, hsh2 = other.hsh2;
    }

    bool operator ==(const Hash &other) const{
        return (hsh1 == other.hsh1 && hsh2 == other.hsh2);
    }
};

char s[MAXN + 1], t[MAXN + 1];
Hash <MOD1, MOD2> pw[MAXN + 1];
Hash <MOD1, MOD2> pref[MAXN + 1], suff[MAXN + 1];

vector < Hash <MOD1, MOD2> > a, b;

inline void solve(char *s, int n, vector < Hash <MOD1, MOD2> > &a) {
    int i, j;
    for(i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] * B + s[i] - 'a' + 1;
    }
    for(i = n; i >= 1; i--) {
        suff[i] = suff[i + 1] + pw[n - i] * (s[i] - 'a' + 1);
    }
    for(i = 0; i <= n; i++) {
        for(j = 0; j < 26; j++) {
            Hash <MOD1, MOD2> x = pref[i] * pw[n - i + 1] + pw[n - i] * (j + 1) + suff[i + 1];
            a.push_back(x);
        }
    }
}

int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> s + 1 >> t + 1;

    pw[0] = Hash<MOD1, MOD2>(1, 1);
    for(i = 1; i <= n + 1; i++) {
        pw[i] = pw[i - 1] * B;
    }

    a.reserve(26 * (n + 1));
    b.reserve(26 * (n + 1));

    solve(s, n, a);
    solve(t, n, b);

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    b.resize(unique(b.begin(), b.end()) - b.begin());

    int ans = 0;
    for(auto it : a) {
        int cur = lower_bound(b.begin(), b.end(), it) - b.begin();
        if(cur != b.size() && b[cur] == it) {
            ans++;
        }
    }

    cout << ans;

    return 0;
}