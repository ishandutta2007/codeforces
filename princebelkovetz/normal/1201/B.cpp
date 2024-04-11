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
    int n, sum = 0, mx = 0; cin >> n;
    vector <int> a(n);
    for (auto& x : a) {
        cin >> x;
        mx = max(mx, x);
        sum += x;
    }
    if (sum & 1 or mx > sum / 2) cout << "NO\n";
    else cout << "YES\n";


}