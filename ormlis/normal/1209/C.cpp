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
const int INFi = 2e9 + 5;
const int maxN = 2e5 + 1;
const int md = 998244353;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    range(i ,n) {
        char x; cin >> x;
        a[i] = x - '0';
    }
    for(int num = 0; num <= 9; ++num) {
        vector<int> col(n);
        int last = -1;
        int nl = -1;
        bool ok = true;
        range(i, n) {
            if (a[i] < num) {
                if (a[i] < nl) {
                    ok = false;
                    break;
                }
                nl = a[i];
                last = i;
                col[i] = 1;
            }
        }
        if (!ok) continue;
        for(int i = last + 1; i < n; ++i) {
            if (a[i] == num) {
                col[i] = 1;
            }
        }
        nl = num;
        range(i, n) {
            if (col[i]) continue;
            if (a[i] < nl) {
                ok = false;
                break;
            }
            nl = a[i];
            col[i] = 2;
        }
        if (!ok) continue;
        range(i, n) cout << col[i];
        cout << '\n';
        return;
    }
    cout << "-\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}