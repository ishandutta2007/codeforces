#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

// using namespace __gnu_pbds;
using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 3e5 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> a(n);
    vector<int> to(k);
    vector<bool> can(n, 1);
    range(i, k) to[i] = i - 1;
    to[0] = 0;
    to[k - 1] = 0;
    range(i, n) a[i] = s[i] - 'a';
    range(i, n) {
        int mn = k;
        if (i && (a[i] < a[i - 1] || (i + 1 < n && a[i + 1] < a[i - 1]))) {
            if (i + 1 < n && a[i + 1] < a[i]) {
                swap(a[i], a[i + 1]);
                swap(a[i], a[i - 1]);
                i++;
                continue;
            }
            swap(a[i], a[i - 1]);
            continue;
        }
        if (i + 2 < n) mn = min(mn, a[i + 2]);
        if (i + 1 < n) mn = min(mn, to[a[i + 1]]);
        if (mn < to[a[i]]) {
            if (mn == to[a[i + 1]]) {
                swap(a[i], a[i + 1]);
                if (a[i] == 0) {
                    a[i + 1] = to[a[i + 1]];
                    i++;
                    continue;
                }
                a[i] = to[a[i]];
                i++;
                continue;
            }
            a[i] = to[a[i]];
            swap(a[i + 1], a[i + 2]);
            swap(a[i + 1], a[i]);
            i += 2;
            continue;
        }
        a[i] = to[a[i]];
    }
    range(i, n) cout << (char) ('a' + a[i]);
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}