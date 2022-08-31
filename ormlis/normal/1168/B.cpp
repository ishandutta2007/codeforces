#include <bits/stdc++.h>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;
typedef long double ld;


void solve() {
    string s;
    cin >> s;
    int l = -1;
    ll ans = 0;
    for (int i = 0; i < (int) s.size(); ++i) {
        for (int j = 1; i - j * 2 >= max(0, l); ++j) {
            if (s[i] == s[i - j] && s[i] == s[i - j * 2]) {
                l = i - j * 2;
                break;
            }
        }
        ans += l + 1;
    }
    cout << ans << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}