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
    int l, r, a; cin >> l >> r >> a;
    if (l > r) swap(l, r);
    if (a < r - l) {
        l += a;
        a = 0;
    }
    else {
        a -= r - l;
        l = r;
    }
    cout << 2 * (l + a / 2) << "\n";
    return 0;
}