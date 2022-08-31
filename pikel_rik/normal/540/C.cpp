#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define all(x) (x).begin(), (x).end()

typedef tree <int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef unsigned long long ull;
typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 500;

int n, m, r1, c1, r2, c2;
string a[N];

int dirx[] = {0, 0, 1, -1};
int diry[] = {1, -1, 0, 0};

bool bfs() {
    queue<pair<int, int>> q;
    q.push({r1, c1});

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int newx = cur.first + dirx[i], newy = cur.second + diry[i];

            if (newx >= 0 and newx < n and newy >= 0 and newy < m) {
                if (a[newx][newy] == 'X' and newx == r2 and newy == c2)
                    return true;

                if (a[newx][newy] == '.') {
                    a[newx][newy] = 'X';
                    q.push({newx, newy});
                }
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];

    cin >> r1 >> c1; --r1; --c1;
    cin >> r2 >> c2; --r2; --c2;

    bfs() ? cout << "YES\n" : cout << "NO\n";
    return 0;
}