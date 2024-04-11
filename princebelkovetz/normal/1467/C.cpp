#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cassert>
#include <map>
#include <set>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define int long long
int s[3], m[3];
signed main() {
    int n, q, k; cin >> n >> q >> k;
    vector <int> a(n), b(q), c(k);
    int s1 = 0, s2 = 0, s3 = 0;
    int m1 = 1e9, m2 = 1e9, m3 = 1e9;
    for (auto x : a)
        cin >> x, s[0] += x, m1 = min(m1, x);
    for (auto x : b)
        cin >> x, s[1] += x, m2 = min(m2, x);
    for (auto x : c)
        cin >> x, s[2] += x, m3 = min(m3, x);
    m[0] = m1, m[1] = m2, m[2] = m3;
    int v1 = 0, v2 = 0;
    for (int i = 0; i < 3; ++i) {
        v1 = max(v1, s[i] + s[(i + 1) % 3] - s[(i + 2) % 3]);
        v2 = max(v2, s[i] + s[(i + 1) % 3] + s[(i + 2) % 3] - 2 * (m[i] + m[(i + 1) % 3]));
    }
    cout << max(v1, v2) << '\n';
    return 0;
}