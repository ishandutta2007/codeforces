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
    int n, m; cin >> n >> m;
    int x, y; cin >> x >> y;
    vector <bool> used(n + 1);
    for (; ;) {
        cout << x << ' ' << y << "\n";
        int last = 1;
        for (int i = 1; i <= m; ++i) {
            if (i == y) continue;
            cout << x << ' ' << i << "\n";
            last = i;
        }
        used[x] = true;
        x = -1;
        for (int i = 1; i <= n; ++i) 
            if (!used[i]) {
                x = i; break;
            }
        if (x == -1) break;
        y = last;
    }
    return 0;
}