#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstring>
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

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(7);
    int tt; cin >> tt;
    while (tt--) {
        int a, b; cin >> a >> b;
        if (a < b) swap(a, b);
        int cur = 0;
        while (b < a) {
            ++cur;
            b += cur; 
        }
        while ((b & 1) != (a & 1)) {
            ++cur;
            b += cur;
        }
        cout << cur << endl;
    }

}