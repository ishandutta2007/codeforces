#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <unordered_map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#include <locale>
#include <numeric>
#include <random>

#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';
#define int long long

using namespace std;
const int root = 212, mod = 1e9 + 7, N = 1e6 + 7;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(8);

    string s; cin >> s;
    int n = s.size();
    s += s;
    vector <string> a(n);
    for (int i = 0; i < n; ++i) 
        a[i] = s.substr(i, n);
    ld ans = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < n;) {
        int j = i;
        while (j < n and a[j][0] == a[i][0])
            j++;
        int mxCnt = 0;
        for (int id = 1; id < n; ++id) {
            vector <int> cnt(26);
            for (int x = i; x < j; ++x) {
                cnt[a[x][id] - 'a']++;
            }
            int curCnt = 0;
            for (auto& x : cnt) curCnt += (x == 1);
            mxCnt = max(mxCnt, curCnt);
        }
        ans += (ld)mxCnt / n;
        i = j;
    }
    cout << ans << '\n';
    return 0;
}