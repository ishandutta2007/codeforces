#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

const ll INF = 2e18 + 5;
const int INFi = 1e9;
const int maxN = 3e5 + 100;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n; cin >> n;
    vector<string> a(3);
    range(i, 3) cin >> a[i];
    auto check = [&] (int c) {
        int d = 0;
        range(i, n * 2) {
            if (a[c][i] == '0') d++;
        }
        return d > n;
    };
    vector<int> t(3);
    range(c, 3) t[c] = check(c);
    if (t[0] == t[2]) {
        swap(a[1], a[2]);
        swap(t[1], t[2]);
    } else if (t[1] == t[2]) {
        swap(a[0], a[2]);
        swap(t[0], t[2]);
    } else {
        assert(t[0] == t[1]);
    }
    char w;
    if (t[0]) w = '0';
    else w = '1';
    vector<string> b(n + 1);
    auto go = [&] (string &k) {
        int e = 0;
        range(i, 2 * n) {
            if (k[i] == w && e != n) {
                e++;
                continue;
            }
            b[e] += k[i];
        }
    };
    go(a[0]);
    go(a[1]);
    cout << b[0];
    for(int i = 1; i <= n; ++i) {
        cout << w;
        cout << b[i];
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(2) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}