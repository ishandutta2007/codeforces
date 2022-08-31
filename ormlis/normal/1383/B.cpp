#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 4e5;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    for(int bb = 29; bb >= 0; --bb) {
        int b = 1 << bb;
        int cnt = 0;
        range(i, n) {
            if (b & a[i]) {
                cnt++;
            }
        }
        if (cnt % 2 == 0) continue;
        if ((cnt / 2) % 2 == 1 && n % 2 == 0) {
            cout << "WIN\n";
            return;
        }
        if ((cnt / 2) % 2 == 1 && n % 2 == 1) {
            cout << "LOSE\n";
            return;
        }
        if ((cnt / 2) % 2 == 0) {
            cout << "WIN\n";
            return;
        }
        cout << "LOSE\n";
        return;
    }
    cout << "DRAW\n";
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