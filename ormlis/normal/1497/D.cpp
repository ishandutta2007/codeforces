#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

typedef long long ll;

using namespace std;
//using namespace __gnu_pbds;

const int INFi = 2e9 + 5;
const int maxN = 1e7 + 5;
const int md = 1e9 + 7;
const ll INF = 2e18;

void solve() {
    int n;
    cin >> n;
    vector<int> tag(n), s(n);
    range(i, n) cin >> tag[i];
    range(i, n) cin >> s[i];
    vector<ll> dp(n);
    for (int i = 1; i < n; ++i) {
        auto newdp = dp;
        for (int j = i - 1; j >= 0; --j) {
            if (tag[j] == tag[i]) continue;
            newdp[j] = max(newdp[j], newdp[i] + abs(s[i] - s[j]));
            newdp[i] = max(newdp[i], dp[j] + abs(s[i] - s[j]));
        }
        swap(dp, newdp);
    }
    cout << *max_element(all(dp)) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}