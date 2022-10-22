#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
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
    int t; cin >> t;
    while (t-- > 0) {
        int n; cin >> n;
        vector <int> a(2 * n), ans;
        for (auto& x : a) cin >> x;
        set <int> ok;
        for (auto x : a) {
            if (ok.find(x) != ok.end()) continue;
            ok.insert(x);
            ans.push_back(x);
        }
        for (auto x : ans) cout << x << ' ';
        cout << endl;
    }
}