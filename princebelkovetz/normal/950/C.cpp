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
    string s; cin >> s;
    int n = s.size();
    vector <vector <int>> ans;
    stack <int> need0, need1;
    bool c = true;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            if (need0.empty()) {
                need1.push(ans.size());
                ans.push_back({ i });
            }
            else {
                need1.push(need0.top());
                ans[need0.top()].push_back(i);
                need0.pop();
            }
        }
        else {
            if (need1.empty()) {
                c = false;
                break;
            }
            else {
                need0.push(need1.top());
                ans[need1.top()].push_back(i);
                need1.pop();
            }
        }
    }
    for (auto x : ans) {
        if (x.size() % 2 == 0) c = false;
    }
    if (c) {
        cout << ans.size() << "\n";
        for (auto x : ans) {
            cout << x.size() << ' ';
            for (auto y : x) cout << y + 1 << ' ';
            cout << "\n";
        }
    }
    else cout << -1;
    cout << "\n";
    return 0;
}