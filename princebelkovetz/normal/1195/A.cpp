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
    int n, k; cin >> n >> k;
    map <int, int> a;
    int cnt = (n + 1) / 2, ans = 0;
    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        a[x]++;
        if (a[x] == 2) {
            a[x] = 0;
            ans += 2;
            --cnt;
        }
    }
    for (auto& x : a) {
        if (x.second == 1) {
            cnt--;
            ans++;
        }
        if (!cnt) break;
    }
    cout << ans << "\n";

    return 0;
}