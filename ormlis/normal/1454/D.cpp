#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace __gnu_pbds;
using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 2e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 9;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    ll n; cin >> n;
    vector<ll> ans;
    for(ll i = 2; i * i <= n; ++i) {
        if (n % i) continue;
        int c = 0;
        while(n % i == 0) {
            if (c == ans.size()) ans.emplace_back(1);
            ans[c] *= i;
            n /= i;
            c++;
        }
    }
    if (n != 1) {
        if (ans.empty()) ans.emplace_back(1);
        ans[0] *= n;
    }
    reverse(all(ans));
    cout << ans.size() << "\n";
    for(auto &x: ans) cout << x << " ";
    cout << '\n';
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