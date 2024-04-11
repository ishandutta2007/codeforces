#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using i128 = __int128;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;

int Bit(int mask, int b) { return (mask >> b) & 1; }

template<class T>
bool ckmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool ckmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}

const int INFi = 2e9;
const ll INF = 2e18;
const int LG = 20;
const int maxN = 1000 + 20;

int g[maxN];
void calc() {
    g[0] = 0;
    g[1] = 1;
    for(int i = 2; i < maxN; ++i) {
        ll mask = 0;
        mask |= 1ll << (g[i - 2]);
        for(int j = 0; j < i / 2 + 1; ++j) {
            int res = 0;
            res ^= g[j - 1];
            res ^= g[i - j - 2];
            mask |= (1ll << (ll)res);
        }
        ll t = mask;
        t ^= (t + 1);
        t &= mask;
        t++;
        g[i] = __builtin_ctzll(t);
        //cout << g[i] << ',';
    }
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int A = 0, B = 0;
    for(auto x : s) {
        if (x == 'R') A++;
        else B++;
    }
    if (A > B) {
        cout << "Alice\n";
        return;
    }
    if (B > A) {
        cout << "Bob\n";
        return;
    }
    int ans = 0;
    for (int l = 0, r = 0; l < n; l = r) {
        r = l + 1;
        while (r < n && s[r] != s[r - 1]) r++;
        int len = r - l - 1;
        while(len >= maxN) len -= 34;
        ans ^= g[len];
    }
    if (ans) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(15) << fixed;
    calc();
    int t = 1;
    cin >> t;

    range(i, t) {
        solve();
    }
    return 0;
}