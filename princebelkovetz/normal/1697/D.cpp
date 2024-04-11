#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <cassert>
#include <numeric>
#include <climits>

#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';

using namespace std;
const int root = 212, mod = 1e9 + 7, B = 60, N = 1e3 + 15;

int query_1st(int id) {
    cout << "? 1 " << id + 1 << endl;
    char res; cin >> res;
    return res - 'a';
}

int query_2nd(int l, int r) {
    cout << "? 2 " << l + 1 << ' ' << r + 1 << endl;
    int res; cin >> res;
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    int n; cin >> n;
    vector <int> ans = { query_1st(0) };
    vector <int> last(26, -1);
    last[ans[0]] = 0;
    for (int i = 1; i < n; i++) {
        vector <pair <int, int>> have;
        for (int j = 0; j < 26; j++) {
            if (last[j] != -1) have.push_back({ last[j], j });
        }
        sort(have.begin(), have.end());
        if (query_2nd(0, i) > have.size()) {
            ans.push_back(query_1st(i));
            last[ans.back()] = i;
        }
        else {
            int l = -1, r = have.size();
            while (l + 1 < r) {
                int m = (l + r) / 2;
                int res = query_2nd(have[m].first, i);
                if (res > have.size() - m) r = m;
                else l = m;
            }
            ans.push_back(have[l].second);
            last[have[l].second] = i;
        }
    }
    cout << "! ";
    for (auto& x : ans) cout << char(x + 'a');
    cout << endl;
    return 0;
}