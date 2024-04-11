#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 400000 + 2000;
const int md = 998244353;
const int md2 = 1e9 + 7;

// double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n; cin >> n;
    int cp = n, cm = n;
    vector<int> a(n), b(n);
    range(i, n) {
        cin >> a[i];
        if (a[i] == -1 && cm == n) cm = i;
        if (a[i] == 1 && cp == n) cp = i;
    }
    range(i, n) cin >> b[i];
    for(int i = n - 1; i >= 0; --i) {
        if (a[i] == b[i]) continue;
        if (a[i] < b[i] && cp < i) {
            continue;
        }
        if (a[i] > b[i] && cm < i) {
            continue;
        }
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}