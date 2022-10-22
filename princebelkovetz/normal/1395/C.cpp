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
    vector <int> a(n), b(m);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    vector <vector <int>> bitsa(n, vector <int>(9)), bitsb(m, vector <int>(9));
    for (int i = 0; i < n; ++i) {
        for (int cur = 0; a[i]; ++cur, a[i] /= 2) {
            bitsa[i][cur] = a[i] % 2;
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int cur = 0; b[i]; ++cur, b[i] /= 2) {
            bitsb[i][cur] = b[i] % 2;
        }
    }
    vector <int> ans(9);
    vector <set <int>> pos(n);
    for (auto& x : pos) {
        for (int i = 0; i < m; ++i)
            x.insert(i);
    }
    for (int i = 8; i >= 0; --i) {
        bool c = true;
        for (int j = 0; j < n; ++j) {
            if (!bitsa[j][i]) continue;
            bool d = false;
            for (auto x: pos[j])
                if (!bitsb[x][i]) {
                    d = true; break;
                }
            c = c && d;
        }
        if (c) {
            for (int j = 0; j < n; ++j) {
                if (!bitsa[j][i]) continue;
                vector <int> ind;
                for (auto x : pos[j])
                    if (bitsb[x][i]) {
                        ind.push_back(x);
                    }
                for (auto x : ind) pos[j].erase(x);
            }
        }
        else ans[i] = 1;
    }
    int res = 0;
    for (int i = 8; i >= 0; --i) res += ans[i] * pow(2, i);
    cout << res << "\n";
    return 0;
}