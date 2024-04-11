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
bool cmp(pair <int, int> a, pair <int, int> b) {
    ld absa = (ld)a.second / a.first, absb = (ld)b.second / b.first;
    if (absa != absb) return absa < absb;
    return a.first < b.first;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(6);
    int tt; cin >> tt;
    while (tt --> 0) {
        int n; cin >> n;
        map <int, int> m;
        while (n --> 0) {
            int x; cin >> x;
            m[x]++;
        }
        vector <int> a;
        for (auto x : m) {
            if (x.second >= 4) {
                a.push_back(x.first);
                a.push_back(x.first);
            }
            else if (x.second >= 2)
                a.push_back(x.first);
        }
        vector <pair <int, int>> b;
        for (int i = 1; i < a.size(); ++i) {
            b.push_back({ a[i - 1], a[i] });
        }
        sort(b.begin(), b.end(), cmp);
        cout << b[0].first << " " << b[0].first << " ";
        cout << b[0].second << " " << b[0].second << "\n";
    }
    return 0;
}