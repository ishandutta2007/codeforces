#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;
const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 1e6 + 1;
const int md = 998244353;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

int mul(int a, int b) {
    return (1ll * a * b) % md;
}
int add(int a, int b) {
    if (a + b >= md) return a + b - md;
    return a + b;
}

int sub(int a, int b) {
    if (a - b < 0) return a - b + md;
    return a - b;
}

int binpow(int a, int b) {
    if (b == 0) return 1;
    if (b % 2) return mul(binpow(a, b - 1), a);
    int mid = binpow(a, b / 2);
    return mul(mid, mid);
}

void solve() {
    int n, k; cin >> n >> k;
    ll ans1 = 0;
    for(int i = n; i > n - k; --i) ans1 += i;
    vector<int> p(n);
    range(i, n) cin >> p[i];
    int ans2 = 1;
    int prev = -1;
    range(i, n) {
        if (p[i] > n - k) {
            if (prev == -1) {
                prev = i;
                continue;
            }
            ans2 = mul(ans2, i - prev);
            prev = i;
        }
    }
    cout << ans1 << " " << ans2 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests=1;
    range(_, tests) {
        solve();
    }
    return 0;
}