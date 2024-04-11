#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;
using namespace __gnu_pbds;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 4e5 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

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

int fact[maxN];

int rev(int a) {
    return binpow(a, md - 2);
}

void init() {
    fact[0] = 1;
    for (int i = 1; i < maxN; ++i) fact[i] = mul(fact[i - 1], i);
}

int C(int n, int k) {
    if (k > n || k < 0) return 0;
    return mul(fact[n], rev(mul(fact[k], fact[n - k])));
}

void solve() {
    set<int> s;
    int n, k; cin >> n >> k;
    vector<int> a(n), b(k);
    vector<int> pos(n);
    range(i, n) {
        cin >> a[i];
        a[i]--;
        pos[a[i]] = i;
    }
    range(i, k) {
        cin >> b[i];
        b[i]--;
    }
    range(i, n) s.insert(i);
    vector<int> can(n, 1);
    range(i, k) can[pos[b[i]]] = 0;
    int ans = 1;
    range(i, k) {
        auto it = s.upper_bound(pos[b[i]]);
        auto it2 = it;
        it2--;
        int l = -1, r = -1;
        if (it2 != s.begin()) {
            it2--;
            l = *it2;
        }
        if (it != s.end()) {
            r = *it;
        }
        int sp = 0;
        if (l != -1 && can[l]) {
            sp++;
        }
        if (r != -1 && can[r]) sp++;
        ans = mul(ans, sp);
        if (ans == 0) {
            break;
        }
        s.erase(pos[b[i]]);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}