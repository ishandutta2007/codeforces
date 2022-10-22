#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define endl "\n"
#define int long long
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
const int inf = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(2);
    int n, mincost = 1e9 + 8, minnum = 0; cin >> n;
    vector <int> a(10);
    for (int i = 1; i <= 9; ++i) {
        cin >> a[i];
        if (mincost >= a[i]) {
            mincost = a[i];
            minnum = i;
        }
    }
    if (mincost > n) {
        cout << -1; return 0;
    }
    int ansSize = n / mincost;
    string ans = "";
    for (int i = 0; i < ansSize; ++i) ans += '0' + (char)minnum;
    n -= mincost * ans.size();
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 9; j > minnum; --j){
            if (a[j] <= n + mincost) {
                ans[i] = (char)('0' + j);
                n -= a[j];
                n += mincost;
                break;
            }
        }
    }
    cout << ans;
}