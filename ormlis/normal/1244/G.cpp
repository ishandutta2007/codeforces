#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;
const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 1e5 + 1;
const int P = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n; ll k; cin >> n >> k;
    ll s = 1ll * n * (n + 1) / 2;
    if (s > k) {
        cout << -1;
        return;
    }
    vector<int> a(n, - 1);
    int j = n - 1;
    for(int i = 0; i < n; ++i) {
        if (i >= j) break;
        if (s + j - i <= k) {
            s += j - i;
            a[i] = j;
            j--;
        }
    }
    cout << s << "\n";
    range(i, n) cout << i + 1 << " ";
    cout << "\n";
    j = 1;
    range(i, n) {
        if (a[i] == -1) {
            cout << j << " ";
            j++;
        } else {
            cout << a[i] + 1 << " ";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}