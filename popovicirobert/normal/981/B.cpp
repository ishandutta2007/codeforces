#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

map <int, int> mp;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, m, a, x, i;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> a >> x;
        mp[a] = x;
    }
    cin >> m;
    for(i = 1; i <= m; i++) {
        cin >> a >> x;
        mp[a] = max(mp[a], x);
    }
    ll ans = 0;
    for(auto it : mp) {
        ans += it.second;
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}