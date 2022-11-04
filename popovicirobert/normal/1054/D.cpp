#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

map <int, int> mp;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, k;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    ll ans = 1LL * n * (n + 1) / 2;
    int x = 0, y;
    mp[0]++;
    for(i = 1; i <= n; i++) {
        cin >> y;
        x ^= y;
        y = (x ^ ((1 << k) - 1));
        if(mp[x] > mp[y]) {
            swap(x, y);
        }
        ans -= mp[x];
        mp[x]++;
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}