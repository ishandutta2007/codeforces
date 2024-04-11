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
#include <bitset>
#include <functional>

#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';

using namespace std;
const int mod = 1e9 + 7, p = 239;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(8);
    int n; cin >> n;
    vector <int> a(n);
    for (auto& x : a) cin >> x;
    vector <int> ids(n);
    iota(ids.begin(), ids.end(), 0);
    sort(ids.begin(), ids.end(), [&](int i, int j) {return a[i] != a[j] ? (a[i] > a[j]) : (i < j); });
    int m; cin >> m;
    while (m--) {
        int k, pos; cin >> k >> pos;
        vector <int> ok;
        for (int j = 0; j < k; ++j) ok.push_back(ids[j]);
        sort(ok.begin(), ok.end());
        cout << a[ok[--pos]] << '\n';
    }
    return 0;
}