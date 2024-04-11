#include <bits/stdc++.h>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 5e5 + 1;
const int md = 1e9 + 7;

void solve() {
    int n, m; cin >> n >> m;
    vector<string> a(n);
    range(i, n) cin >> a[i];
    int s;
    if (n % 3 == 0) s = 1;
    else s = 0;
    for(int i = s; i < n; i += 3) {
        range(j, m) a[i][j] = 'X';
        if (i + 3 < n) {
            bool was = false;
            range(j, m) {
                if (a[i + 1][j] == 'X' || a[i + 2][j] == 'X') {
                    was = true;
                    a[i + 1][j] = a[i + 2][j] = 'X';
                    break;
                }
            }
            if (!was) {
                a[i + 1][0] = a[i + 2][0] = 'X';
            }
        }
    }
    range(i, n) cout << a[i] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}