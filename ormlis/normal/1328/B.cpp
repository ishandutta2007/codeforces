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
    ll n, k; cin >> n >> k;
    bool flag = false;
    range(i, n) {
        ll current;
        if (flag) {
            current = n - i - 1;
        } else {
            current = (n - i - 1) * (n - i - 2) / 2;
        }
        if (k > current) {
            k -= current;
            cout << 'b';
            if (flag) {
                for(int j = i + 1; j < n; ++j) cout << 'a';
                break;
            } else {
                flag = true;
            }
        } else {
            cout << 'a';
        }
    }
    cout << '\n';
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