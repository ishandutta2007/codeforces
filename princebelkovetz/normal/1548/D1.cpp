#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <queue>
#include <cassert>
#include <bitset>

using namespace std;

#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long 

const int mod = 1e9 + 7, N = 52;

int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    int n; cin >> n;
    vector <pair <int, int>> a(n);
    for (auto& x : a) cin >> x.first >> x.second;
    sort(a.begin(), a.end());
    for (auto& x : a) {
        x.first /= 2, x.second /= 2;
        x.first %= 2, x.second %= 2;
        x.first += 2, x.second += 2;
        x.first %= 2, x.second %= 2;
    }
    vector <vector <vector <int>>> cnt(2, vector <vector <int>>(2, vector <int>(n + 1)));
    for (int i = 0; i < n; ++i) {
        cnt[a[i].first][a[i].second][i + 1]++;
        for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 2; ++k)
                cnt[j][k][i + 1] += cnt[j][k][i];
    }
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i].first != a[j].first or a[i].second != a[j].second) {
                for (int i1 = 0; i1 < 2; ++i1) {
                    for (int i2 = 0; i2 < 2; ++i2) {
                        if (i1 == a[i].first and i2 == a[i].second)
                            ans += cnt[i1][i2][i];
                        if (i1 == a[j].first and i2 == a[j].second)
                            ans += cnt[i1][i2][i];
                    }
                }
            }
            else {
                for (int i1 = 0; i1 < 2; ++i1) {
                    for (int i2 = 0; i2 < 2; ++i2) {
                        ans += cnt[i1][i2][i];
                    }
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}