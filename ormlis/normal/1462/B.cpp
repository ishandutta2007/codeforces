#include <bits/stdc++.h>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define ar array
#define all(a) (a).begin(), (a).end()
typedef long long ll;
typedef long double ld;
using namespace std;

const ll INF = 1e18 + 5;
const int INFi = 1e9;
const int maxN = 1e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int c1 = 0;
    int c2 = 0;
    string t = "2020";
    range(i, 4) {
        if (s[i] == t[i]) c1++;
        else break;
    }
    reverse(all(s));
    reverse(all(t));
    range(i, 4) {
        if (s[i] == t[i]) c2++;
        else break;
    }
    if (c1 + c2 >= 4) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}