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

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    vector <int> a;
    for (int i = 1; i < n; ++i)
        if (gcd(i, n) == 1) a.push_back(i);
    int last = 0, res = 1;
    for (int i = 0; i < a.size(); ++i) {
        res = (res * a[i]) % n;
        if (res == 1) last = i;
    }
    cout << last + 1 << '\n';
    for (int i = 0; i <= last; ++i) cout << a[i] << ' ';
    cout << '\n';
    return 0;
}