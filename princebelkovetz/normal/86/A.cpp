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
int rev(int n) {
    int ans = 0, cur = 1;
    while (n) {
        ans += (9 - n % 10) * cur;
        cur *= 10;
        n /= 10;
    }
    return ans;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(6);
    int l, r; cin >> l >> r;
    int ans = 0;
    for (int i = 5; i <= r; i *= 10) {
        if (i < l) continue;
        ans = max(ans, i * rev(i));
    }
    ans = max(ans, rev(l) * l);
    ans = max(ans, rev(r) * r);
    cout << ans << "\n";

    return 0;
}