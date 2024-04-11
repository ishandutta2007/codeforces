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
    int ans = 0, mod = 998244353;
    vector <int> a(n);
    map <int, int> cou;
    for (auto& x : a) {
        cin >> x;
        int cur = x, cnt = 0;
        while (cur) {
            ++cnt; cur /= 10;
        }
        cou[cnt]++;
    }
    for (auto x : a) {
        int res = 0;
        for (auto y : cou) {
            int n1 = y.first, cur = x, got = 0;
            int pow = 1, flag = 1;
            while (cur) {
                if (flag) {
                    got = (got + (cur % 10 * pow) % mod) % mod;
                    cur /= 10;
                    pow = (pow * 10) % mod;
                }
                if (!flag and n1) {
                    pow = (pow * 10) % mod;
                    --n1;
                }
                flag = 1 - flag;
            }
            res = (res + (got * y.second) % mod) % mod;
        }
        for (auto y : cou) {
            int n1 = y.first, cur = x, got = 0;
            int pow = 1, flag = 1;
            while (cur) {
                if (!flag) {
                    got = (got + (cur % 10 * pow) % mod) % mod;
                    cur /= 10;
                    pow = (pow * 10) % mod;
                }
                if (flag and n1) {
                    pow = (pow * 10) % mod;
                    --n1;
                }
                flag = 1 - flag;
            }
            res = (res + (got * y.second) % mod) % mod;
        }
        ans = (ans + res) % mod;
    }
    
    cout << ans << "\n";
    return 0;
}