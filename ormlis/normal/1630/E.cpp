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

const int INFi = 2e9;
const ll INF = 2e18;
const int maxN = 5e4 + 5;
const int LG = 19;


const int md = 998244353; //1e9 + 7, 1e9 + 9

inline int add(const int &a, const int &b) {
    return a + b >= md ? a + b - md : a + b;
}

inline int sub(const int &a, const int &b) {
    return a - b < 0 ? a - b + md : a - b;
}

inline int mul(const int &a, const int &b) {
    return (1ll * a * b) % md;
}

int binpow(int a, int b) {
    int res = 1;
    for(; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res,  a);
    return res;
}

int rev(int a) {
    return binpow(a, md - 2);
}

const int maxF = 2e6 + 5;
int fact[maxF];
int rfact[maxF];

void init() {
    fact[0] = 1;
    for (int i = 1; i < maxF; ++i) fact[i] = mul(fact[i - 1], i);
    rfact[maxF - 1] = rev(fact[maxF - 1]);
    for (int i = maxF - 1; i >= 1; --i) {
        rfact[i - 1] = mul(rfact[i], i);
    }
}

int C(int n, int k) {
    if (k < 0 || n < k) return 0;
    return mul(fact[n], mul(rfact[k], rfact[n - k]));
}

int T(int n, int k) {
    return C(n + k - 1, k - 1);
}

void solve() {
    int n; cin >> n;
    vi a(n);
    vi res;
    rep(i, n) {
        int x; cin >> x;
        a[x-1]++;
    }
    auto calc = [&] (vector<int> &cnts, int len) {
        int cnt_all = fact[len];
        int ans = 0;
        int t = 1;
        
        
        for(auto &x : cnts) {
            cnt_all = mul(cnt_all, rfact[x]);
            t = mul(t, rfact[x]);
            
        }
        for(auto &x : cnts) {
            int cur = add(mul(x - 1, T(len - x, x)), T(len - x, x - 1));
            cur = mul(cur, mul(fact[x], t));
            cur = mul(cur, fact[len - x]);
            ans = add(ans, cur);
        }
        return pair<int, int> {cnt_all, ans};
    };
    int to = n;
    rep(i, n) {
        if (a[i] == n) {
            cout << "1\n";
            return;
        }
        if (a[i] > 0) {
            res.push_back(a[i]);
            to = __gcd(to, a[i]);
        }
    }
    int cnt_all = 0;
    int ans = 0;
    vector<int> sub1(to + 1, 0), sub2(to + 1, 0);
    vvi divs(to + 1);
    for(int i = 1; i <= to; ++i) for(int j = i * 2; j <= to; j += i) divs[j].push_back(i);
    for(int i = to; i >= 1; --i) {
        if (to % i != 0) continue;
        auto tt = res;
        for(auto &x : tt) x /= i;
        auto [cnt1, ans1] = calc(tt, n / i);
        ans1 = mul(ans1, i);
        cnt1 = sub(cnt1, sub1[i]);
        ans1 = sub(ans1, sub2[i]);
        for(auto &d : divs[i]) {
            sub1[d] = add(sub1[d], cnt1);
            sub2[d] = add(sub2[d], ans1);
        }
        cnt1 = mul(cnt1, rev(n / i));
        ans1 = mul(ans1, rev(n / i));
        cnt_all = add(cnt_all, cnt1);
        ans = add(ans, ans1);
    }
    cout << sub(n, mul(ans, rev(cnt_all))) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(20 - 7) << fixed;
    init();
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}