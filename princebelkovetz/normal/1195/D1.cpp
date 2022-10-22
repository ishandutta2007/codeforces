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
    int n; cin >> n;
    vector <int> a(n);
    for (auto& x : a) cin >> x;
    int ans = 0, mod = 998244353;
    for (auto x : a) {
        int cur = x, pow = 1;
        while (cur) {
            ans = (ans + (((cur % 10) * pow) * n) % mod) % mod;
            ans = (ans + ((((cur % 10) * 10 * pow) % mod) * n) % mod) % mod;
            cur /= 10;
            pow = (pow * 100) % mod;
        }
    }
    cout << ans << "\n";
    return 0;
}