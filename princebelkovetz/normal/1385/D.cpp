#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#define endl "\n"
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
const ld eps = 1e-8;
int cou(string s, char x) {
    int ans = 0, n = (int)s.size();
    int cou1 = 0, cou2 = 0;
    for (int i = 0; i < n / 2; ++i)
        if (s[i] == x) ++cou1;
    for (int i = n / 2; i < n; ++i)
        if (s[i] == x) ++cou2;
    if (s.size() == 1) ans = 1 - (int)(s[0] == x);
    else {
        string c1 = s.substr(0, n / 2), c2 = s.substr(n / 2, n / 2);
        ans = min(n / 2 - cou2 + cou(c1, x + 1), n / 2 - cou1 + cou(c2, x + 1));
    }
    //debug(ans); debug(s); debug(x)
    return ans;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(7);
    int t; cin >> t;
    while (t-- > 0) {
        int n, ans = 0; cin >> n;
        string s; cin >> s;
        cout << cou(s, 'a') << endl;
    }
}