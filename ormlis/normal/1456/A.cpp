#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

// using namespace __gnu_pbds;
using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 3e5 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n, p, k;
    cin >> n >> p >> k;
    vector<int> a(n);
    vector<ll> need(k);
    p--;
    range(i, n) {
        char x;
        cin >> x;
        if (x == '1') a[i] = 1;
        else {
            if (i >= p) need[i % k]++;
        }
    }
    int x, y;
    cin >> x >> y;
    range(i, k) need[i] *= 1ll * x;
    ll answer = INF;
    range(i, n) {
        if (i + p >= n) break;
        ll S = need[(i+p) % k] + 1ll * i * y;
        answer = min(answer, S);
        if (!a[(i+p)]) need[(i+p) % k] -= x;
    }
    cout << answer << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}