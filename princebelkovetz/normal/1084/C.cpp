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
struct point {
    int x; bool f;
};
bool cmp(point a, point b) {
    return a.x < b.x;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(6);
    string s; cin >> s;
    int flag = 0, n = s.size();
    vector <int> na, nb;
    for (int i = 0; i < n; ++i) {
        if (flag and s[i] == 'a') na.back()++;
        if ((na.empty() or !flag) and s[i] == 'a') {
            flag = 1;
            na.push_back(1);
        }
        if (!flag and s[i] == 'b' and !na.empty()) nb.back()++;
        if (flag and s[i] == 'b') {
            flag = 0;
            nb.push_back(1);
        }
    }
    int ans = 1, mod = 1e9 + 7;
    for (int i = 0; i < na.size(); ++i) {
        ans = (ans * (na[i] + 1)) % mod;
    }
    cout << --ans << "\n";
    return 0;
}