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
const int maxN = 3e5 + 20;

int n;

vi ord;
int query(const vi &a) {
    rep(i, a.size()) {
        if (a[ord[i]] == 1) cout << 'T';
        else cout << 'F';
    }
    cout << endl;
    int k;
    cin >> k;
    assert(k != -1);
    if (k == n) exit(0);
    return k;
}

void solve() {
    cin >> n;
    ord.resize(n);
    iota(all(ord), 0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    shuffle(all(ord), rng);
    vi a(n);
    int zeros = query(a);
    auto ask = [&](const vi &a) {
        int ch = query(a) - zeros;
        int k = accumulate(all(a), 0);
        // cnt_1 + cnt_0 = k
        // cnt_1 - cnt_0 = ch
        return (k + ch) / 2;
    };
    vi ans(n);
    for(int l = 0; l < n;) {
        if (n - l <= 3) {
            vi cur(n);
            cur[l] = 1;
            ans[l] = ask(cur);
            l++;
            continue;
        }
        vi cur(n);
        cur[l] = cur[l + 1] = 1;
        int s01 = ask(cur);
        if (s01 != 1) {
            ans[l] = ans[l + 1] = s01/2;
            l += 2;
            continue;
        }
        cur[l + 1] = 0;
        cur[l + 2] = 1;
        int s02 = ask(cur);
        if (s02 != 1) {
            ans[l] = ans[l + 2] = s02 / 2;
            ans[l + 1] = ans[l]^1;
            l += 3;
            continue;
        }
        cur[l] = 0;
        cur[l + 1] = 1;
        cur[l + 3] = 1;
        int s123 = ask(cur);
        ans[l + 3] = s123 % 2;
        s123 -= ans[l + 3];
        ans[l + 1] = ans[l + 2] = s123 / 2;
        ans[l] = ans[l + 1] ^ 1;
        l += 4;
    }
    ask(ans);
}

signed main() {
    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    //cout << setprecision(15) << fixed;
    int t = 1;
//    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}