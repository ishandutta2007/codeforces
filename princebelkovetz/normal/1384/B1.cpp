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

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(6);
    int tt; cin >> tt;
    while (tt-- > 0) {
        int n, k, l;
        cin >> n >> k >> l;
        vector <int> d(n);
        for (auto& x : d) cin >> x;
        vector <int> t;
        for (int i = 0; i <= k; ++i)
            t.push_back(i);
        for (int i = k - 1; i >= 1; --i)
            t.push_back(i);
        //for (auto x : t) cout << x << ' ';
        //cout << "\n";
        vector <bool> cur(2 * k);
        for (int i = 0; i < 2 * k; ++i) {
            if (d[0] + t[i] <= l) cur[i] = true;
        }
        //for (auto x : cur) cout << x << ' ';
        //cout << "\n";
        for (int i = 1; i < n; ++i) {
            vector <bool> res(2 * k);
            for (int j = 0; j < 2 * k; ++j) {
                if (cur[j] and d[i] + t[(j + 1) % (2 * k)] <= l) res[(j + 1) % (2 * k)] = true;
            }
            for (int j = 0; j < 2 * k; ++j) {
                if (res[(j + 1) % (2 * k)] or !res[j]) continue;
                int ok = (j + 1) % (2 * k);
                while (ok != j and d[i] + t[ok] <= l) {
                    res[ok] = true;
                    ok = (ok + 1) % (2 * k);
                }
            }
            cur = res;
            //for (auto x : cur) cout << x << ' ';
            //cout << "\n";
        }
        bool c = false;
        for (int i = 0; i < 2 * k; ++i) {
            if (cur[i]) c = true;
        }
        if (c) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}