#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <string>
#include <stack>
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
    int tt; cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector <string> a(n);
        for (auto& x : a) cin >> x;
        int ans = 0;
        for (int i = 0; i < m - 1; ++i)
            if (a[n - 1][i] != 'R') ++ans;
        for (int i = 0; i < n - 1; ++i)
            if (a[i][m - 1] != 'D') ++ans;
        cout << ans << "\n";
    }
    return 0;
}