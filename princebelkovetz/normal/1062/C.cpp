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
const int mod = 1e9 + 7;
int fpow(int a, int n) {
    if (!n) return 1;
    if (n & 1) return (fpow(a, n - 1) * a) % mod;
    int t = fpow(a, n / 2) % mod;
    return (t * t) % mod;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(6);
    int n, q; cin >> n >> q;
    string s; cin >> s;
    vector <int> pref(n + 1);
    for (int i = 0; i < n; ++i)
        pref[i + 1] = pref[i] + (int)(s[i] - '0');
    while (q--) {
        int l, r; cin >> l >> r;
        int num1 = pref[r] - pref[l - 1], num0 = r - l + 1 - num1;
        int geom = fpow(2, num1) - 1;
        int geom2 = (geom * (fpow(2, num0) - 1)) % mod;
        cout << (geom + geom2) % mod << "\n";
    }
}