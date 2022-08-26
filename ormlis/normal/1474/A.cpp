#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define ar array
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()


typedef long long ll;
typedef long double ld;
using namespace std;

//using namespace __gnu_pbds;

const ll INF = 1e18 + 5;
const int INFi = 2e9;
const int maxN = 1e6 + 1;
const int md2 = 998244353;
const int md3 = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    string b;
    cin >> b;
    int c = b[0] - '0';
    c++;
    string ans = "1";
    for(int i = 1; i < n; ++i) {
        if ((b[i] - '0') + 1 == c) {
            ans += "0";
        } else {
            ans += "1";
        }
        c = b[i] - '0' + ans[i] - '0';
    }
    cout << ans <<'\n';
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