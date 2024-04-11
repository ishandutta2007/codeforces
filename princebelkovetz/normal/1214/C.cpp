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
    cout << fixed << setprecision(7);
    int n; cin >> n;
    string s; cin >> s;
    int cnt1 = 0, cnt2 = 0, cur = 0, mn = 1e9;
    for (auto x : s) {
        if (x == '(') {
            cnt1++;
            cur++;
        }
        else {
            cnt2++;
            cur--;
        }
        mn = min(cur, mn);
    }
    if (cnt1 == cnt2 and s.size() % 2 == 0 and mn >= -1) cout << "Yes\n";
    else cout << "No\n";
}