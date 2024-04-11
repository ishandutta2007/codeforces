#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 4e18;
const int INFi = 2e9;
const int maxN = 5000 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n, m; cin >> n >> m;
    vector<string> a(n);
    range(i, n) cin >> a[i];
    range(i, m) {
        string s = a[0];
        char x = '0';
        bool bad = false;
        range(j, n) {
            int cnt = 0;
            range(e, m) {
                if (e == i) continue;
                if (a[j][e] != s[e]) cnt++;
            }
            if (!cnt) continue;
            if (cnt == 1) {
                if (x == '0') {
                    x = a[j][i];
                }
                if (x == a[j][i]) {
                    continue;
                }
            }
            bad = true;
            break;
        }
        if (bad) continue;
        if (x == '0') x = 'a';
        range(e, m) {
            if (e == i) cout << x;
            else cout << s[e];
        }
        cout << "\n";
        return;
    }
    cout << "-1\n";
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