#include <bits/stdc++.h>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const ll INF = 2e18;
const int INFi = 2e9 + 5;
const int maxN = 2e5 + 1;
const int md = 998244353;

void solve() {
    int n; cin >> n;
    vector<int> cnt(100, 0);
    vector<pair<ll, int>> to;
    range(i, n) {
        ll x; cin >> x;
        to.emplace_back(x, 0);
        int w = 0;
        while(x % 2 == 0) {
            w++;
            x /= 2;
        }
        cnt[w]++;
        to.back().second = w;
    }
    int mx = max_element(all(cnt)) - cnt.begin();
    cout << n - cnt[mx] << '\n';
    for(auto &[a, b] : to) {
        if (b == mx) continue;
        cout << a << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
//    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}