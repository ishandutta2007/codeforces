#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 3e5 + 1;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

map<int, int> mp;
void solve() {
    int a; cin >> a;
    if (mp[a]) {
        cout << mp[a] << "\n";
        return;
    }
    int w = 0;
    range(i, 26) {
        if ((1 << i) & a) w = i;
    }
    w = a ^ ((1 << (w + 1)) - 1);
    if (w) {
        mp[a] = __gcd(a ^ w, a & w);
        cout << mp[a] << "\n";
        return;
    }
    mp[a] = 1;
    for(int d = 2; d * d < a; ++d) {
        if (a % d == 0) {
            mp[a] = a / d;
            break;
        }
    }
    cout << mp[a] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests; cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}