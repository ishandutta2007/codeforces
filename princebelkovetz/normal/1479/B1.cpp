#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cassert>
using namespace std;
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    
    int n; cin >> n;
    vector <int> a(n);
    for (auto& x : a) cin >> x;
    vector <vector <int>> ok;
    for (int i = 0; i < n; ++i) {
        int j = i;
        while (j < n and a[j] == a[i]) {
            j++;
        }
        ok.push_back({ a[i], j - i });
        i = j - 1;
    }
    int ans = 0;
    int l = -1, cnt = 0;
    for (int i = 0; i < ok.size(); ++i) {
        if (ok[i][1] == 1) {
            ans++;
            if (ok[i][0] == l and cnt == 1) cnt = 2;
            else cnt--;
        }
        else {
            if (l == ok[i][0] and cnt > 0) ans--;
            l = ok[i][0], cnt = 2;
            ans += 2;
        }
    }
    cout << ans << '\n';
    return 0;
}