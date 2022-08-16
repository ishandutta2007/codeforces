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
const int N = 1000 + 5;

int n, m, a[N][N], now[N];
bool visited[N][N];

bool f(int x) {
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            if (a[i][j] >= x)
                now[cnt++] = j;
        }

        for (int j = 0; j < cnt; j++) {
            for (int k = j + 1; k < cnt; k++) {
                if (visited[now[j]][now[k]])
                    return true;
                visited[now[j]][now[k]] = true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];

    int lo = 0, hi = 1e9;

    while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;
        if (f(mid))
            lo = mid;
        else hi = mid - 1;
    }

    cout << lo << "\n";
    return 0;
}