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
    string a, b; cin >> a >> b;
    range(i, n) {
        if (a[i] > b[i]) {
            cout << "-1\n";
            return;
        }
    }
    int ans = 0;
    range(e, 20) {
        char c = 'a';
        c += e;
        char m = 'z';
        int cnt = 0;
        range(i, n) {
            if (a[i] == c && a[i] != b[i]) {
                cnt++;
                m = min(m, b[i]);
            }
        }
        if (cnt == 0) continue;
        ans++;
        range(i, n) {
            if (a[i] == c && a[i] != b[i]) {
                a[i] = m;
            }
        }
    }
    cout << ans << "\n";
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