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
    int tt; cin >> tt;
    while (tt --> 0) {
        int n, cnte1 = 0, cnto1 = 0; cin >> n;
        vector <int> a(n);
        for (auto& x : a) {
            cin >> x;
            if (x & 1) cnte1++;
            else cnto1++;
        }
        int m, cnte2 = 0, cnto2 = 0; cin >> m;
        vector <int> b(m);
        for (auto& x : b) {
            cin >> x;
            if (x & 1) cnte2++;
            else cnto2++;
        }
        cout << cnte1 * cnte2 + cnto1 * cnto2 << "\n";

    }
    return 0;
}