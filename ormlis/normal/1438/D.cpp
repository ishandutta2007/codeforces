#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 1e6 + 1;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    vector<int> kek;
    for (int j = 0; j + 1 < n; j += 2) {
        j = min(j, n - 3);
        int x = a[j] ^a[j + 1] ^a[j + 2];
        a[j] = a[j + 1] = a[j + 2] = x;
        kek.push_back(j);
    }
    reverse(all(kek));
    for (auto &j : kek) {
        int x = a[j] ^a[j + 1] ^a[j + 2];
        a[j] = a[j + 1] = a[j + 2] = x;
    }
    if (count(all(a), a[0]) != n) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << kek.size() * 2 << "\n";
    range(_, 2) {
        reverse(all(kek));
        for (auto &j: kek) {
            cout << j + 1 << " " << j + 2 << " " << j + 3 << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}