#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld double
#define ll __int128

mt19937 rnd(51);

const int K = 500, N = 1e5 + 10;
int go[N][N / K];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> last(n, -1);
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        last[r] = l;
    }
    for (int j = 0; j < N / K; j++) {
        if (j == 0 || j * K >= n) {
            continue;
        }
        vector<int> mx(n);
        iota(mx.begin(), mx.end(), 0);
        for (int i = 0; i <= j * K; i++) {
            if (last[i] != -1) {
                mx[last[i]] = max(mx[last[i]], i);
            }
        }
        deque<int> q;
        for (int i = n - 1; i >= 0; i--) {
            while (q.size() > 0 && mx[i] >= q.back()) {
                mx[i] = max(mx[i], mx[q.back()]);
                q.pop_back();
            }
            go[i][j] = mx[i];
            q.pb(i);
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        int can = y / K, now = -1;
        if (can == 0) {
            now = x;
        } else {
            now = go[x][can];
        }
        for (int i = can * K; i <= y; i++) {
            if (x <= last[i] && last[i] <= now) {
                now = i;
            }
        }
        cout << now + 1 << '\n';
    }
    return 0;
}