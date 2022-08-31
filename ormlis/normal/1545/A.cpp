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
const int maxN = 1e7 + 1;
const int md = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> a, b;
    range(i, n) {
        int x; cin >> x;
        if (i & 1) b.push_back(x);
        else a.push_back(x);
    }
    vector<int> c;
    sort(rall(a));
    sort(rall(b));
    range(i, n) {
        if (i & 1) {
            c.push_back(b.back());
            b.pop_back();
        } else {
            c.push_back(a.back());
            a.pop_back();
        }
    }
    auto d = c;
    sort(all(d));
    if (c == d) cout << "YES\n";
    else cout << "NO\n";
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