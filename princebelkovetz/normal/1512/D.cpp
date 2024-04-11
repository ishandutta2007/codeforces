#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <cassert>
#include <functional>
using namespace std;
#define int long long
#define ld long double
#define debug(x) cout << #x << " actually equals " << x << '\n';
constexpr int mod = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, sum = 0; cin >> n;
        n += 2;
        vector <int> a(n);
        for (auto& x : a) 
            cin >> x, sum += x;
        multiset <int> ok = { a.begin(), a.end() };
        bool was = false;
        for (int i = 0; i < n; ++i) {
            ok.erase(ok.find(a[i]));
            int x = sum - a[i] - a[i];
            if (ok.find(x) != ok.end()) {
                ok.erase(ok.find(x));
                for (auto y : ok) cout << y << ' ';
                was = true;
                break;
            }
            ok.insert(a[i]);
        }
        if (!was) cout << -1;
        cout << '\n';
    }
    return 0;
}