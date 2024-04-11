#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <deque>
#include <iterator>
#include <sstream>
#define endl "\n"
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(6);
    int n, m; cin >> n >> m;
    vector <int> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    sort(b.begin(), b.end());
    int ans = 1e9 + 1;
    for (int i = 0; i < n; ++i) {
        int cur = 0;
        if (a[i] <= b[0]) cur = b[0] - a[i];
        else cur = m + b[0] - a[i];
        vector <int> temp(n);
        for (int i = 0; i < n; ++i)
            temp[i] = (a[i] + cur) % m;
        sort(temp.begin(), temp.end());
        if (temp == b) ans = min(ans, cur);
    }
    cout << ans << "\n";
    return 0;
}