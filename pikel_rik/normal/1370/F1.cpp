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
const int N = 1e3 + 5;

int n, d[N], st[N], fi[N], T;
vector<int> g[N];

void dfs(int x, int p = 0, int de = 0) {
    d[x] = de;
    st[x] = T++;

    for (int &i : g[x]) {
        if (i == p) continue;
        dfs(i, x, de + 1);
    }

    fi[x] = T++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        for (int i = 1; i < N; i++)
            g[i].clear();

        cin >> n;
        for (int i = 1; i < n; i++) {
            int u, v; cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        cout << "? " << n << " ";
        for (int i = 1; i <= n; i++) cout << i << " "; cout << "\n"; cout.flush();

        int root, main_d;
        cin >> root >> main_d;

        T = 0;
        dfs(root);
        int lo = 0, hi = *max_element(d + 1, d + n + 1), ans1, ans2;

        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;

            vector<int> temp;
            for (int i = 1; i <= n; i++) {
                if (d[i] >= mid)
                    temp.push_back(i);
            }

            cout << "? " << temp.size() << " ";
            for (int i : temp) cout << i << " "; cout << "\n"; cout.flush();

            int x, dist;
            cin >> x >> dist;

            if (dist == main_d)
                lo = mid, ans1 = x;
            else hi = mid - 1;
        }

        if (lo == main_d) {
            cout << "! " << ans1 << " " << root; cout << "\n"; cout.flush();
            string s; cin >> s;
            if (s == "Incorrect")
                return 0;
            continue;
        }

        vector<int> temp;
        for (int i = 1; i <= n; i++) {
            if (d[i] == main_d - lo and i != ans1 and !(st[i] <= st[ans1] and fi[i] >= fi[ans1]))
                temp.push_back(i);
        }

        cout << "? " << temp.size() << "\n";
        for (int i : temp) cout << i << " "; cout << "\n"; cout.flush();

        cin >> ans2 >> main_d;

        cout << "! " << ans1 << " " << ans2; cout << "\n"; cout.flush();
        string s; cin >> s;

        if (s == "Incorrect")
            return 0;
    }
    return 0;
}