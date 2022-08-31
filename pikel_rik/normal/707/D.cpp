#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e3;
const int Q = 1e5 + 5;

int n, m, q, ans[Q];
vector<int> g[Q];
vector<pair<int, pair<int, int>>> qi(1);

bitset<N> bk[N];
int total, sum[N];

void dfs(int x) {
    bool ok = false;
    if (qi[x].first == 1) {
        int i = qi[x].second.first - 1, j = qi[x].second.second - 1;
        if (!bk[i][j])
            bk[i][j] = true, ok = true;
        if (ok) sum[i]++, total++;
    } else if (qi[x].first == 2) {
        int i = qi[x].second.first - 1, j = qi[x].second.second - 1;
        if (bk[i][j])
            bk[i][j] = false, ok = true;
        if (ok) sum[i]--, total--;
    } else if (qi[x].first == 3) {
        int i = qi[x].second.first - 1;
        bk[i] = ~bk[i];
        total = total - sum[i] + m - sum[i];
        sum[i] = m - sum[i];
        ok = true;
    }

    ans[x] = total;
    for (int &i : g[x]) {
        dfs(i);
    }

    if (ok) {
        if (qi[x].first == 1) {
            int i = qi[x].second.first - 1, j = qi[x].second.second - 1;
            bk[i][j] = false;
            sum[i]--;
            total--;
        } else if (qi[x].first == 2) {
            int i = qi[x].second.first - 1, j = qi[x].second.second - 1;
            bk[i][j] = true;
            sum[i]++;
            total++;
        } else if (qi[x].first == 3) {
            int i = qi[x].second.first - 1;
            bk[i] = ~bk[i];
            total = total - sum[i] + m - sum[i];
            sum[i] = m - sum[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> q;

    int next = 0;
    for (int i = 1; i <= q; i++) {
        pair<int, pair<int, int>> f;
        cin >> f.first;

        if (f.first <= 2) {
            cin >> f.second.first >> f.second.second;
            g[next].push_back(i);
            next = i;
        }
        else if (f.first == 3) {
            cin >> f.second.first;
            g[next].push_back(i);
            next = i;
        }
        else {
            cin >> f.second.first;
            next = f.second.first;
            if (qi[next].first == 4)
                next = qi[next].second.second;
            f.second.second = next;
        }
        qi.push_back(f);
    }

    dfs(0);
    for (int i = 1; i <= q; i++) {
        if (qi[i].first == 4)
            ans[i] = ans[qi[i].second.second];
        cout << ans[i] << "\n";
    }
    return 0;
}