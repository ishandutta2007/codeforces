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
const int maxN = 2e4 + 5;
const int LG = 20;

using cp = complex<ld>;
const ld PI = atan2(0, -1);

void fft(vector<cp> &s, vector<cp> &res, int n, cp x, int ss = 0, int step = 1, int rs = 0) {
    if (n == 1) {
        res[rs] = s[ss];
        return;
    }
    fft(s, res, n / 2, x * x, ss, step * 2, rs);
    fft(s, res, n / 2, x * x, ss + step, step * 2, rs + n / 2);
    cp c = 1;
    for (int i = rs; i < rs + n / 2; ++i) {
        auto a = res[i], b = res[i + n / 2];
        res[i] = a + b * c;
        res[i + n / 2] = a - b * c;
        c *= x;
    }
}

vector<ll> multiply(vector<ll> &a, vector<ll> &b) {
    vector<cp> as(all(a)), bs(all(b));
    int n = 1;
    while (n < a.size() || n < b.size()) n *= 2;
    n *= 2;
    as.resize(n);
    bs.resize(n);
    cp t = {cos(2 * PI / n), sin(2 * PI / n)};
    vector<cp> resa(n), resb(n);
    fft(as, resa, n, t);
    fft(bs, resb, n, t);
    range(i, n)resa[i] *= resb[i];
    t = {cos(-2 * PI / n), sin(-2 * PI / n)};
    vector<cp> result(n);
    fft(resa, result, n, t);
    vector<ll> res(n);
    range(i, n)res[i] = llround(result[i].real() / n);
    return res;
}

void solve() {
    int n, x; cin >> n >> x;
    vl A(n + 1);
    A[0]++;
    int w = 0;
    rep(i, n) {
        int t; cin >> t;
        if (t < x) w++;
        A[w]++;
    }
    vl B(n + 1);
    rep(i, n + 1) B[i] = A[n - i];
    auto res = multiply(A, B);
    res.resize(n + 1);
    res[n] -= n + 1;
    res[n] /= 2;
    rep(i, n + 1) cout << res[n - i] << ' ';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(20 - 7) << fixed;
    int t = 1;
    //cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}