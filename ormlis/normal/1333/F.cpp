#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 500000 + 2000;
const int md = 998244353;
const int md2 = 1e9 + 7;

// double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

int p[maxN];

void solve() {
    int n; cin >> n;
    int cnt = 1;
    vector<int> used(n + 1, 0);
    for(int i = 2; i <= n; ++i) {
        if (!p[i]) {
            for (int j = i; j <= n; j += i) {
                if (!p[j]) p[j] = i;
            }
            cnt++;
            used[i] = 1;
        }
    }
    used[1] = 1;
    vector<int> ans(n + 1, 0);
    for(int i = 1; i <= cnt; ++i) ans[i] = 1;
    vector<int> pw;
    for(int i = 1; i <= n; ++i) {
        if (p[i] == i) {
            pw.push_back(i);
        }
        int prev = cnt;
        for(auto &x: pw) {
            if (x > p[i]) break;
            if (1ll * x * i > n) break;
            if (used[x * i]) continue;
            used[x*i]=1;
            cnt++;
        }
        for(int j = prev + 1; j <= cnt; ++j) ans[j] = i;
    }
    range(i, n - 1) cout << ans[i + 2] << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}