#include <bits/stdc++.h>
#include <cstdio>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 1e5 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    range(i, n) {
        char x; cin >> x;
        if (x == '1') a[i] = 1;
        else a[i] = 0;
    }
    range(i, n) {
        char x; cin >> x;
        if (x == '1') b[i] = 1;
        else b[i] = 0;
    }
    vector<int> ans;
    range(i, n) {
        if (i % 2) {
            if (a[n-1-i/2] != b[n-1-i]) {
                ans.push_back(1);
            }
        } else {
            if (a[i/2] == b[n-1-i]) {
                ans.push_back(1);
            }
        }
        ans.push_back(n-i);
    }
    cout << ans.size() << " ";
    for(auto &x: ans) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}