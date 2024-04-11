#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define ar array
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()


typedef long long ll;
typedef long double ld;
using namespace std;

//using namespace __gnu_pbds;

const ll INF = 1e18 + 5;
const int INFi = 1e9;
const int maxN = 20;
const int md2 = 998244353;
const int md = 1e9 + 7;


void solve() {
    int n;
    cin >> n;
    vector<int> w(n);
    vector<int> order(n);
    iota(all(order), 0);
    range(i, n) cin >> w[i];
    sort(rall(order), [&](int i, int j) {
        return w[i] < w[j];
    });
    vector<int> deg(n);
    range(_, n - 1) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        deg[u]++;
        deg[v]++;
    }
    int j = 0;
    ll ans = accumulate(all(w), 0ll);
    range(i, n - 1) {
        cout << ans << ' ';
        while (j < n && deg[order[j]] == 1) j++;
        if (j != n) {
            deg[order[j]]--;
            ans += w[order[j]];
        }
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}