#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e5 + 5;

int n, lps[N], cnt[N];
string s;
bool visited[N];

void constructLps(const string &pat) {
    int m = pat.length();

    int len = 0, i = 1;
    lps[0] = 0;

    while (i < m) {
        if (pat[i] == pat[len]) {
            len += 1;
            lps[i] = len;
            i += 1;
        }
        else if (len != 0) {
            len = lps[len - 1];
        }
        else {
            lps[i] = 0;
            i += 1;
        }
    }
}

vector<int> g[N];

void dfs(int x, int p) {
    for (int &i : g[x]) {
        if (i == p) continue;
        dfs(i, x);
        cnt[x] += cnt[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> s;
    n = s.length();

    constructLps(s);
    for (int i = 0; i < n; i++) {
        cnt[lps[i]]++;
    }

    vector<pair<int, int>> ans;
    int m = *max_element(lps, lps + n);

    for (int i = n; i >= 1; i--) {
        g[i].push_back(lps[i - 1]);
        g[lps[i - 1]].push_back(i);
    }

    dfs(0, 0);

    int cur = n;
//    for (int i = 0; i < n; i++) cout << lps[i] << " "; cout << "\n";
//    for (int i = 1; i <= m; i++) cout << cnt[i] << " "; cout << "\n";

    while (cur > 0) {
        ans.push_back({cur, 1 + cnt[cur]});
        cur = lps[cur - 1];
    }

    reverse(all(ans));

    cout << ans.size() << "\n";
    for (auto p : ans) cout << p.first << " " << p.second << "\n";
    return 0;
}