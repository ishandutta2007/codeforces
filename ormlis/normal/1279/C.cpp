#include <bits/stdc++.h>
#include <unordered_set>

#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    range(i, n) {
        cin >> a[i];
    }
    range(i, m) {
        cin >> b[i];
    }
    ll ans = 0;
    int cur = 0;
    vector<int> used(n + 1, 0);
    range(i, n) {
        used[a[i]] = 1;
        if (a[i] == b[cur]) {
            ans += (i - cur) * 2;
            while (cur < m && used[b[cur]]) {
                cur++;
                ans++;
            }
            if (cur == m) {
                break;
            }
        }
    }
    cout << ans << '\n';
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int tests;
    cin >> tests;
    //tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}