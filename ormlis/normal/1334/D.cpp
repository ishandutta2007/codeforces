#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 2e5 + 1;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n; cin >> n;
    ll l, r; cin >> l >> r;
    while(l <= r && l <= (n - 1) * 2) {
        if (l & 1) {
            cout << "1 ";
        } else {
            cout << l / 2 + 1 << " ";
        }
        l++;
    }
    ll prev = (n - 1) * 2;
    for(int i = 2; i <= n - 1; ++i) {
        while(l <= r && l - prev <= (n - i - 1) * 2 + 1) {
            if ((l - prev)  & 1) {
                cout << i << " ";
            } else {
                cout << i + (l - prev) / 2 << " ";
            }
            l++;
        }
        prev += (n - i) * 2;
        if (l == prev && l <= r) {
            cout << n << " ";
            l++;
        }
    }
    if (l <= r) {
        cout << 1;
    }
    cout << "\n";
}

// 1 2 1 3 1 4 1 5 2 3 2 4 2 5 3 4 3 5 4 5 1

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