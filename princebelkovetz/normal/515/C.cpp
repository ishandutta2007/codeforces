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

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(6);
    int n; cin >> n;
    string s; cin >> s;
    multiset <char> ans;
    for (auto x : s) {
        int cur = x - '0';
        if (cur == 1 or cur == 0) continue;
        if (cur == 2) ans.insert(x);
        if (cur == 3) ans.insert(x);
        if (cur == 4) {
            ans.insert('2');
            ans.insert('2');
            ans.insert('3');
        }
        if (cur == 5) ans.insert(x);
        if (cur == 6) {
            ans.insert('5');
            ans.insert('3');
        }
        if (cur == 7) ans.insert(x);
        if (cur == 8) {
            ans.insert('7');
            ans.insert('2');
            ans.insert('2');
            ans.insert('2');
        }
        if (cur == 9) {
            ans.insert('7');
            ans.insert('2');
            ans.insert('3');
            ans.insert('3');
        }
    }
    string ok;
    for (auto x : ans) ok = x + ok;
    cout << ok << "\n";
    return 0;
}