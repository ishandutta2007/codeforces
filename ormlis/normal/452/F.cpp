#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define ar array
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()


typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

//using namespace __gnu_pbds;

const ll INF = 2e18 + 5;
const int INFi = 2e9;
const int maxN = 3e5 + 1;
const int md2 = 998244353;
const int md = 1e9 + 7;


int add(int a, int b) {
    if (a + b >= md) return a + b - md;
    return a + b;
}

int sub(int a, int b) {
    if (a - b < 0) return a - b + md;
    return a - b;
}

int mul(int a, int b) {
    return (1ll * a * b) % md;
}

int binpow(int a, int b) {
    if (b <= 0) return 1;
    if (b % 2) return mul(a, binpow(a, b - 1));
    int m = binpow(a, b / 2);
    return mul(m, m);
}


int rev(int a) {
    return binpow(a, md - 2);
}

int fact[maxN];
int rfact[maxN];
int stP[maxN];
int P = 0;

void init() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    while (P < 1000) {
        P = rng() % md;
    }
    stP[0] = 1;
    for (int i = 1; i < maxN; ++i) stP[i] = mul(stP[i - 1], P);
    fact[0] = 1;
    for (int i = 1; i < maxN; ++i) fact[i] = mul(fact[i - 1], i);
    rfact[maxN - 1] = rev(fact[maxN - 1]);
    for (int i = maxN - 1; i >= 1; --i) rfact[i - 1] = mul(rfact[i], i);
}

int C(int n, int k) {
    if (k > n || k < 0) return 0;
    return mul(fact[n], mul(rfact[k], rfact[n - k]));
}


struct fenwick {
    vector<int> fenw{};
    int n{};

    void build(int k) {
        n = k;
        fenw.resize(n);
    }

    void upd(int i, int x) {
        for (; i < n; i |= (i + 1)) fenw[i] = add(fenw[i], x);
    }

    int get(int i) {
        int res = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1) res = add(res, fenw[i]);
        return res;
    }
};

void solve() {
    init();
    int n;
    cin >> n;
    fenwick f1;
    fenwick f2;
    f1.build(n);
    f2.build(n);
    vector<int> h1(n), h2(n);
    range(i, n) h1[i] = stP[i];
    for (int i = n - 1; i >= 0; --i) {
        h2[i] = stP[n - 1 - i];
    }
    auto get1 = [&] (int l, int r) {
        int res = mul(sub(f1.get(r), f1.get(l - 1)), rev(h1[l]));
        return res;
    };

    auto get2 = [&] (int l, int r) {
        int res = mul(sub(f2.get(r), f2.get(l - 1)), rev(h2[r]));
        return res;
    };


    auto check = [&](int x) {
        int d = min(x, n - x - 1);
        if (d == 0) return;
        int hl = get1(x - d, x - 1);
        int hr = get2(x + 1, x + d);
        if (hl == hr) return;
        cout << "YES\n";
        exit(0);
    };
    range(i, n) {
        int x;
        cin >> x;
        x--;
        check(x);
        f1.upd(x, h1[x]);
        f2.upd(x, h2[x]);
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}