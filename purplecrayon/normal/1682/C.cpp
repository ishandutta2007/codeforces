#include <bits/stdc++.h>
using namespace std;

#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 5e2+10, MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;
    
    map<int, int> mp;
    for (int x : a) mp[x]++;

    int one = 0, two = 0;
    for (auto& [_, k] : mp) {
        if (k == 1) one++;
        else two++;
    }
    cout << two + (one + 1) / 2 << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}