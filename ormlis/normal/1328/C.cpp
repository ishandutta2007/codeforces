#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;
const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 1000001;
const int P = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n;
    cin >> n;
    vector<char> x(n), a(n), b(n);
    range(i, n) cin >> x[i];
    bool flag = false;
    for (int i = 0; i < n; ++i) {
        if (flag) {
            a[i] = '0';
            b[i] = x[i];
        } else {
            if (x[i] == '2') a[i] = b[i] = '1';
            if (x[i] == '1') {
                a[i] = '1';
                b[i] = '0';
                flag = true;
            }
            if (x[i] == '0') a[i] = b[i] = '0';
        }
    }
    range(i, n) cout << a[i];
    cout << "\n";
    range(i, n) cout << b[i];
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}