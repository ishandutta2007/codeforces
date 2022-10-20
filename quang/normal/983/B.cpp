#include <bits/stdc++.h>

using namespace std;

const int N = 5010;

int n;
int a[N];
int dp[N][N];
vector<pair<int, int> > query[N];

struct BIT {
    int t[N];

    BIT() {
        memset(t, 0, sizeof t);
    }

    void add(int x, int v) {
        while (x < N) {
            t[x] = max(t[x], v);
            x += (x & -x);
        }
    }

    int get(int x) {
        int res = 0;
        while (x) {
            res = max(res, t[x]);
            x -= (x & -x);
        }
        return res;
    }
} t;

int res[100100];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        dp[i][i] = a[i];
    }
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            dp[i][j] = dp[i + 1][j] ^ dp[i][j - 1];
            // cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    int q;
    scanf("%d", &q);
    for (int it = 1; it <= q; it++) {
        int l, r;
        int id = it;
        scanf("%d %d", &l, &r);
        query[l].push_back(make_pair(r, id));
        // cout << l << " " << r << " " << id << endl;
    }
    for (int i = n; i; i--) {
        for (int j = i; j <= n; j++) {
            t.add(j, dp[i][j]);
            // cout << i << " " << j << " " << dp[i][j] << endl;
        }
        for (pair<int, int> u : query[i]) {
            res[u.second] = t.get(u.first);
            // cout << u.second << " " << u.first << " " << i << endl;
        }
    }
    for (int i = 1; i <= q; i++) {
        printf("%d\n", res[i]);
    }
    return 0;
}