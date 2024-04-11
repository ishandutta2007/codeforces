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
    int tt; cin >> tt;
    while(tt--) {
        int n; cin >> n;
        string s; cin >> s;
        vector <vector <int>> ok;
        stack <int> n1, n0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                if (n0.empty()) {
                    ok.push_back({ i });
                    n1.push((int)ok.size() - 1);
                }
                else {
                    ok[n0.top()].push_back(i);
                    n1.push(n0.top());
                    n0.pop();
                }
            }
            else {
                if (n1.empty()) {
                    ok.push_back({ i });
                    n0.push((int)ok.size() - 1);
                }
                else {
                    ok[n1.top()].push_back(i);
                    n0.push(n1.top());
                    n1.pop();
                }
            }
        }
        vector <int> ans(n);
        for (int i = 0; i < (int)ok.size(); ++i) {
            for (auto x : ok[i]) ans[x] = i + 1;
        }
        cout << ok.size() << "\n";
        for (auto x : ans) cout << x << ' ';
        cout << "\n";
    }
    return 0;
}