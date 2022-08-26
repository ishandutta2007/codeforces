#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 1e9;
const int maxN = 400000 + 2000;
const int md = 998244353;
const int md2 = 1e9 + 7;

// double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    range(i, n) cin >> a[i];
    int cnt = 0;
    range(i, n) if (a[i] % 2) cnt++;
    cnt /= 2;
    range(i, n) {
        if (a[i] % 2) {
            if (cnt-- > 0) cout << (a[i] + 1) / 2;
            else cout << (a[i] - 1) / 2;
        } else {
            cout << a[i] / 2;
        }
        cout << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
//    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}