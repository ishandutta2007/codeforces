#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 2e5 + 1;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    range(i, n) cin >> a[i];
    int prev = a[0];
    int k = 0;
    for(int i = 1; i < n; ++i) {
        ll c = prev - a[i];
        if (c <= 0) {
            prev = a[i];
            continue;
        }
        int f = 64 - (__builtin_clzll(c));
        k = max(k, f);
    }
    cout << k << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}