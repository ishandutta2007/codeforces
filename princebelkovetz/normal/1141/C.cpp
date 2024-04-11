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
    int n, mn = 0; cin >> n;
    vector <int> q(n - 1), a(n);
    for (int i = 0; i < n - 1; ++i) {
        cin >> q[i];
        a[i + 1] = a[i] + q[i];
        mn = min(mn, a[i + 1]);
    }
    for (auto& x : a)
        x -= mn - 1;
    vector <bool> is(n);
    bool c = true; int cnt = 0;
    for (auto x : a) {
        if (x <= n and x >= 1 and !is[x - 1])
            is[x - 1] = true;
        else c = false;
    }
    if (c) {
        for (auto x : a)
            cout << x << ' ';
        cout << "\n";
    }
    else cout << -1 << "\n";
    return 0;
}