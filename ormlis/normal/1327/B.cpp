#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef unsigned long long ll;

using namespace std;
const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 2e5 + 5;
const int P = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n; cin >> n;
    vector<int> used(n, 0);
    int ansi = -1;
    range(i, n) {
        int k; cin >> k;
        bool find = false;
        range(j, k) {
            int a; cin >> a;
            a--;
            if (used[a]) continue;
            if (!find) {
                find = true;
                used[a] = 1;
            }
        }
        if (!find) ansi = i;
    }
    if (ansi != -1) {
        cout << "IMPROVE\n";
        range(j, n) {
            if (!used[j]) {
                cout << ansi + 1 << " " << j + 1 << "\n";
                return;
            }
        }
    } else {
        cout << "OPTIMAL\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests; cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}