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
int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(6);
    int tt; cin >> tt;
    while (tt-- > 0) {
        int m, d, w;
        cin >> m >> d >> w;
        w /= gcd(w, d - 1);
        int ans = 0;
        int mn = (min(m, d) - 1) / w;
        ans = mn * (mn + 1) / 2;
        ans *= w;
        ans -= mn * ((w - (min(m, d)) % w) % w);
        cout << ans << "\n";
        /*if (d == w + 1) cout << m * (m - 1) / 2;
        else {
            w /= gcd(w, d - 1);
        }*/
    }
    return 0;
}