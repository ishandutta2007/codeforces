#include <bits/stdc++.h>
#include <cstdlib>
#include <string>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 1e5 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n, k; cin >> n >> k;
    vector<char> s(n);
    range(i, n) cin >> s[i];
    sort(all(s));
    if (s[k-1] != s[0] || n == k) {
        cout << s[k-1] << '\n';
        return;
    }
    if (s[n-1] == s[k]) {
        cout << s[0];
        range(i, (n - 1) / k) {
            cout << s[k];
        }
        cout << '\n';
        return;
    }
    string ans = "";
    ans += s[0];
    for(int i = k; i < n; ++i) ans += s[i];
    cout << ans << '\n';
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