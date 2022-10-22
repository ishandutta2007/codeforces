#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <string>
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
    int n; cin >> n;
    vector <int> a(n);
    for (auto& x : a) cin >> x;
    sort(a.begin(), a.end());
    int i = 0, j = n - 1, s1 = 0, s2 = 0;
    for (int x = 0; x < n; ++x) {
        if (x & 1) s1 += a[i++];
        else s2 += a[j--];
    }
    cout << s1 * s1 + s2 * s2 << "\n";
    return 0;
}