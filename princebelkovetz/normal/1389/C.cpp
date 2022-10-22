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
    while (tt-- > 0) {
        string s; cin >> s;
        int n = s.size();
        map <char, int> m;
        int ans1 = n - 2, ans2 = 0, ans3 = 0;
        for (auto x : s) {
            m[x]++;
            ans2 = max(ans2, m[x]);
        }
        ans2 = n - ans2;
        for (int i = 0; i < 10; ++i)
            for (int j = 0; j < 10; ++j) {
                if (i == j) continue;
                char c1 = (char)('0' + i), c2 = (char)('0' + j);
                int cou = 0, flag = 0;
                for (auto x : s) {
                    char cur;
                    if (flag) cur = c2;
                    else cur = c1;
                    if (x == cur) {
                        if (flag) ++cou;
                        flag = 1 - flag;
                    }
                }
                ans3 = max(ans3, cou * 2);
            }
        ans3 = n - ans3;
        cout << min(ans1, min(ans2, ans3)) << "\n";
    }
    return 0;
}