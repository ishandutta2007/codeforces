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
const int N = 2e5 + 5;

int n, a[N][2], b[N][2];
vector<int> pos[N];
bool visited[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) pos[i].clear();

        for (int i = 0; i < n; i++) {
            cin >> a[i][0];
            pos[a[i][0]].push_back(i);
            b[i][0] = a[i][0];
        }
        for (int i = 0; i < n; i++) {
            cin >> a[i][1];
            pos[a[i][1]].push_back(i);
            b[i][1] = a[i][1];
        }

        bool ok = true;
        for (int i = 1; i <= n; i++) {
            if (pos[i].size() != 2)
                ok = false;
        }

        if (!ok) {
            cout << "-1\n";
            continue;
        }

        fill(visited, visited + n + 1, false);
        vector<int> ans;

        for (int x = 1; x <= n; x++) {
            if (pos[x][0] == pos[x][1] or visited[x]) continue;

            int i = pos[x][0], cur = x;
            visited[cur] = true;

            vector<int> temp = {i};
            while (i != pos[x][1]) {
                if (b[i][0] != cur)
                    swap(b[i][0], b[i][1]);

                cur = b[i][1];
                visited[cur] = true;

                if (i == pos[cur][0])
                    i = pos[cur][1];
                else i = pos[cur][0];
                temp.push_back(i);
            }

            if (b[i][0] != cur)
                swap(b[i][0], b[i][1]);

            int c = 0;
            for (int j : temp) {
                c += (a[j][0] != b[j][0]);
            }

            for (int j : temp) {
                if (c <= temp.size() - c and a[j][0] != b[j][0])
                    ans.push_back(j);
                else if (c > temp.size() - c and a[j][0] == b[j][0])
                    ans.push_back(j);
            }
        }

        cout << ans.size() << "\n";
        for (int i : ans) cout << i + 1 << " "; cout << "\n";
    }
    return 0;
}