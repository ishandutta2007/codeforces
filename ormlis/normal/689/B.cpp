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
const int maxN = 2e3;
const int md = 998244353;
const ll INF = 2e18;

void solve() {
    int n; cin >> n;
    queue<int> q;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    range(i, n) a[i]--;
    q.push(0);
    vector<int> ans(n, INFi);
    ans[0] = 0;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        if (v != n - 1 && ans[v + 1] == INFi) {
            ans[v + 1] = ans[v] + 1;
            q.push(v + 1);
        }
        if (ans[a[v]] == INFi) {
            ans[a[v]] = ans[v] + 1;
            q.push(a[v]);
        }
        if (v && ans[v - 1] == INFi) {
            ans[v - 1] = ans[v] + 1;
            q.push(v - 1);
        }
    }
    range(i, n) cout << ans[i] << ' ';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}