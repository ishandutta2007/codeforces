#include <bits/stdc++.h>


#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a.size())
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
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

const int INFi = 1e9 + 10;
const ll INF = 2e18;
const int maxN = 4e6 + 20;
const int LG = 30;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int l = 0;
    map<char, char> to;
    for(char x = 'a'; x <= 'z'; ++x) to[x] = x;
    for (char x = 'a', y = 'a'; x <= 'z'; x = y) {
        int r = l;
        int j = l;
        while (r < n && (int) s[r] <= (int) x + (int) k) {
            s[r] = to[s[r]];
            if (s[r] > s[j]) j = r;
            r++;
        }
        for (int i = l; i < r; ++i) cout << min(s[i], x);
        if (l != r) {
            if (s[j] > x) {
                k -= (s[j] - x);
                y = s[j];
                for (char p = x; p <= y; ++p) to[p] = x;
            }
        }
        l = r;
        y++;
    }
    cout << '\n';
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}