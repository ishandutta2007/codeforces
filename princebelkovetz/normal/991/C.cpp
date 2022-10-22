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
    int l = 0, r = n;
    while (l + 1 < r) {
        int m = (l + r) / 2, ok = n;
        int vasek = 0, petruha = 0;
        while (ok) {
            if (ok >= m) {
                ok -= m;
                vasek += m;
                petruha += ok / 10;
                ok -= ok / 10;
            }
            else {
                vasek += ok;
                ok = 0;
            }
        }
        if (vasek >= n / 2 + (n & 1)) r = m;
        else l = m;
    }
    cout << r << "\n";
    return 0;
}