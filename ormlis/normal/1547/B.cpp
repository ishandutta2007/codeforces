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
    string s; cin >> s;
    int l = 0, r = (int)s.size() - 1;
    int n = s.size();
    for(int i = n - 1; i >= 0; --i) {
        char x = 'a' + i;
        if (s[l] == x) {
            l++;
        } else if (s[r] == x) {
            r--;
        } else {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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