#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 4e18;
const int INFi = 2e9;
const int maxN = 2e5 + 1;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n; cin >> n;
    if (n < 4) {
        cout << "-1\n";
        return;
    }
    int o = n % 4;
    if (o == 0) {
        for(int i = 1; i <= n; i += 4) {
            cout << i + 1 << " " << i + 3 << " " << i << " " << i + 2 << ' ';
        }
        cout << '\n';
        return;
    }
    if (o == 1) {
        for(int i = 1; i < n; i += 4) {
            cout << i + 1 << " " << i + 3 << " " << i << " " << i + 2 << ' ';
        }
        cout << n;
        cout << '\n';
        return;
    }
    if (o == 2) {
        cout << "1 4 2 5 3 6 ";
        for(int i = 7; i <= n; i += 4) {
            cout << i + 1 << " " << i + 3 << " " << i << " " << i + 2 << ' ';
        }
        cout << "\n";
        return;
    }
    if (n == 7) {
        cout << "1 5 2 6 3 7 4\n";
        return;
    }
    if (o == 3) {
        cout << "1 4 2 5 3 6 ";
        for(int i = 7; i < n; i += 4) {
            cout << i + 1 << " " << i + 3 << " " << i << " " << i + 2 << ' ';
        }
        cout << n;
        cout << "\n";
        return;
    }
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