#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define range(i, n) for(int i = 0; i < n; ++i)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

void solve() {
    int n; cin >> n;
    map<pair<int, int>, int> mp;
    auto ask = [&] (int l, int r) {
        if (mp.count({l, r})) return mp[{l, r}];
        cout << "? " << l << "  " << r << endl;
        int x; cin >> x;
        return mp[{l, r}] = x;
    };
    vector<int> ans(n+1);
    ans[1] = ask(1, 3) - ask(2, 3);
    for(int i = 2; i <= n; ++i) {
        ans[i] = ask(i-1, i) - ans[i-1];
    }
    cout << "! ";
    range(i, n) cout << ans[i+1] << " ";
}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    //cout.tie(nullptr);
    int tests = 1;
     //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}