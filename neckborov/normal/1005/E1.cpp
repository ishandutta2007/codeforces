#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    map<int, int> mp[2];
    vector<int> cnt(2);
    int ok = 0;
    ll ans = 0; 
    mp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x < m) {
            cnt[0]++;
        } else if (x > m) {
            cnt[1]++;
        } else {
            ok = 1;
        }
        if (ok && mp[i % 2].count(cnt[0] - cnt[1] + 1)) {
            ans += mp[i % 2][cnt[0] - cnt[1] + 1];
        }
        if (ok && mp[(i + 1) % 2].count(cnt[0] - cnt[1])) {
            ans += mp[(i + 1) % 2][cnt[0] - cnt[1]];
        }
        if (!ok) mp[i % 2][cnt[0] - cnt[1]]++;
    }
    cout << ans << endl;
}