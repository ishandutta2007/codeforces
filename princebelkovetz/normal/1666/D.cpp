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
#include <chrono>
#include <unordered_set>

#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';

using namespace std;
const int root = 212, mod = 1e18 + 7, N = 5e5 + 2;


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    int tt; cin >> tt;
    while (tt--) {
        string s, t; cin >> s >> t;
        vector <vector <int>> ids(26);
        vector <int> cnt(26);
        for (int i = 0; i < s.size(); ++i) {
            ids[s[i] - 'A'].push_back(i);
        }
        for (auto& x : t) cnt[x - 'A']++;

        set <int> ok;
        for (int i = 0; i < 26; ++i) {
            if (!cnt[i] or ids[i].size() < cnt[i]) continue;
            for (int j = ids[i].size() - 1; j >= ids[i].size() - cnt[i]; --j)
                ok.insert(ids[i][j]);
        }

        string res;
        for (auto& x : ok) res += s[x];

        cout << (res != t ? "NO" : "YES") << '\n';


    }

    return 0;
}