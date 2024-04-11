#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

const int MAXN = 2000;

pair <int, int> pts[MAXN + 1];

map <double, int> mp;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> pts[i].first >> pts[i].second;
    }
    sort(pts + 1, pts + n + 1);
    ll ans = 1LL * n * (n - 1) * (n - 2) / 6;
    for(i = 1; i <= n; i++) {
        mp.clear();
        for(int j = i + 1; j <= n; j++) {
            int dx = pts[j].first - pts[i].first;
            int dy = pts[j].second - pts[i].second;
            if(dx == 0)
                mp[1e16]++;
            else
                mp[1.0 * dy / dx]++;
        }
        for(auto it : mp) {
            ans -= 1LL * it.second * (it.second - 1) / 2;
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}