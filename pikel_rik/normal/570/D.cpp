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
const int N = 5e5 + 5;

int n, p[N], st[N], fi[N], T;
vector<int> g[N], dist[N];
string s;

vector<vector<int>> pref[N];

void dfs(int x, int h = 1) {
    dist[h].push_back(x);
    st[x] = T++;

    for (int &i : g[x]) {
        if (i == p[x]) continue;
        dfs(i, h + 1);
    }

    fi[x] = T++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int m;
    cin >> n >> m;
    for (int i = 2; i <= n; i++) {
        cin >> p[i];
        g[i].push_back(p[i]);
        g[p[i]].push_back(i);
    }

    cin >> s;
    dfs(1);

    for (int i = 1; i <= n; i++) {
        if (dist[i].empty()) break;

//        for (int x : dist[i]) cout << x << " "; cout << "\n";

        sort(all(dist[i]), [&] (int x, int y) {
            return st[x] < st[y];
        });

        pref[i].resize(dist[i].size());

        for (int j = 0; j < dist[i].size(); j++) {
            pref[i][j] = vector<int>(26);
            pref[i][j][s[dist[i][j] - 1] - 'a']++;
        }

        for (int j = 1; j < dist[i].size(); j++) {
            for (int k = 0; k < 26; k++) {
                pref[i][j][k] += pref[i][j-1][k];
            }
        }
    }

    while (m--) {
        int v, h;
        cin >> v >> h;

        if (dist[h].empty()) {
            cout << "Yes\n";
            continue;
        }

        int idx1, idx2;

        int lo = 0, hi = dist[h].size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            int u = dist[h][mid];

            if (st[u] < st[v])
                lo = mid;
            else hi = mid - 1;
        }

        idx1 = lo;

        lo = idx1; hi = dist[h].size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int u = dist[h][mid];

            if (st[u] > fi[v])
                hi = mid;
            else lo = mid + 1;
        }

        idx2 = lo;

//        cout << idx1 << " " << idx2 << " ";
        if (idx1 == idx2) {
            cout << "Yes\n";
            continue;
        }

        if (st[dist[h][idx1]] < st[v] and st[dist[h][idx2]] > fi[v]) {
            vector<int> temp1 = pref[h][idx2 - 1];
            vector<int> temp2 = pref[h][idx1];

            for (int i = 0; i < 26; i++)
                temp1[i] -= temp2[i];

            int c = 0;
            for (int i : temp1) {
                if (i % 2 != 0)
                    c++;
            }

            if (c <= 1)
                cout << "Yes\n";
            else cout << "No\n";
        }
        else if (st[dist[h][idx1]] < st[v]) {
            vector<int> temp1 = pref[h][idx2];
            vector<int> temp2 = pref[h][idx1];

            for (int i = 0; i < 26; i++)
                temp1[i] -= temp2[i];

            int c = 0;
            for (int i : temp1) {
                if (i % 2 != 0)
                    c++;
            }

            if (c <= 1)
                cout << "Yes\n";
            else cout << "No\n";
        }
        else if (st[dist[h][idx2]] > fi[v]) {
            vector<int> temp = pref[h][idx2 - 1];
            int c = 0;

            for (int i : temp) {
                if (i % 2 != 0)
                    c++;
            }

            if (c <= 1)
                cout << "Yes\n";
            else cout << "No\n";
        }
        else {
            vector<int> temp = pref[h][idx2];
            int c = 0;

            for (int i : temp) {
                if (i % 2 != 0)
                    c++;
            }

            if (c <= 1)
                cout << "Yes\n";
            else cout << "No\n";
        }
    }
    return 0;
}