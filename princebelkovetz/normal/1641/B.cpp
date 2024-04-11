#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <string>
#include <stack>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#include <locale>
#include <numeric>
#include <random>
#include <functional>
#include <set>

#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';
#define int long long

using namespace std;
const int mod = 1e9 + 7, N = 10;

void ins(vector <int> &a, int l, int r) {
    vector <int> newA;
    for (int i = 0; i <= r; ++i)
        newA.push_back(a[i]);
    for (int i = l + 1; i < r; ++i)
        newA.push_back(a[i]);
    for (int i = r - 1; i > l; --i)
        newA.push_back(a[i]);
    for (int i = r + 1; i < a.size(); ++i)
        newA.push_back(a[i]);
    a = newA;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);
    
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector <int> a(n);
        for (auto& x : a) cin >> x;
        if (n & 1) {
            cout << "-1\n";
            continue;
        }
        int cur = 0, cnt = 0;
        vector <int> res;
        vector <pair <int, int>> ans;
        while (cur < a.size()) {
            int nxt = cur + 1;
            while (nxt < a.size() and a[nxt] != a[cur]) {
                nxt++;
            }
            if (nxt == a.size()) break;
            ins(a, cur, nxt);
            for (int i = cur + 1; i < nxt; ++i)
                ans.push_back({ nxt + i - cur, a[i] });
            res.push_back(2 * (nxt - cur));
            cur += 2 * (nxt - cur);
            cnt++;
        }
        if (cnt != n / 2) {
            cout << "-1\n";
            continue;
        }
        cout << ans.size() << '\n';
        for (auto& x : ans) cout << x.first << ' ' << x.second << '\n';
        cout << res.size() << '\n';
        for (auto& x : res) cout << x << ' ';
        cout << '\n';
    }


    return 0;
}