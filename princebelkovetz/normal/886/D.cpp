#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <unordered_map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#include <locale>
#include <numeric>
#include <random>

#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';
#define int long long
#define NO { cout << "NO\n"; return 0; }
using namespace std;
const int root = 212, mod = 1e9 + 7, N = 1e6 + 7;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);
    int n; cin >> n;
    vector <set <int>> nxt(26), prv(26);
    set <int> full;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        for (auto& x : s)
            full.insert(x - 'a');
        for (int i = 0; i + 1 < s.size(); ++i) {
            nxt[s[i] - 'a'].insert(s[i + 1] - 'a');
            prv[s[i + 1] - 'a'].insert(s[i] - 'a');
        }
    }
    for (auto& x : nxt) 
        if (x.size() > 1) NO;
    for (auto& x : prv) 
        if (x.size() > 1) NO;
    string ans = "";
    set <int> was;
    for (auto& x : full) {
        if (prv[x].empty()) {
            int cur = x;
            while (true) {
                if (was.find(cur) != was.end()) NO;
                ans += (char)(cur + 'a');
                was.insert(cur);
                if (nxt[cur].empty()) break;
                cur = *nxt[cur].begin();
            }
        }
    }
    if (was.size() != full.size()) NO;
    cout << ans << '\n';
    return 0;
}