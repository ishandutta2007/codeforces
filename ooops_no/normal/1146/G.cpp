#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

struct query {
    int l, r, x, c;
};

const int N = 52, INF = 1e18;
int n, h, m, sum[N][N][N], dp[N][N][N];

int solve(int l, int r, int k) {
    if (k == 0) {
        return 0;
    }
    if (dp[l][r][k] != -INF) {
        return dp[l][r][k];
    }
    vector<int> dpp(r + 1, -INF);
    int res = -sum[l][r][k];
    for (int i = l; i <= r; i++) {
        dpp[i] = res + sum[l][i][k] + solve(l, i, k - 1);
    }
    dpp[l] = max(dpp[l], res + k * k);
    for (int i = l; i < r; i++) {
        dpp[i + 1] = max(dpp[i + 1], dpp[i] + k * k);
        for (int j = i + 1; j <= r; j++) {
            dpp[j] = max(dpp[j], dpp[i] + solve(i + 1, j, k - 1) + sum[i + 1][j][k]);
        }
    }
    dp[l][r][k] = dpp[r];
    return dp[l][r][k];
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                dp[i][j][k] = -INF;
            }
        }
    }
    cin >> n >> h >> m;
    vector<query> u(m);
    for (int i = 0; i < m; i++) {
        cin >> u[i].l >> u[i].r >> u[i].x >> u[i].c;
        u[i].l--, u[i].r--;
    }
    sort(u.begin(), u.end(), [&] (query a, query b) {return a.x < b.x;});
    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            int j = 0, res = 0;
            for (int k = 0; k <= h; k++) {
                while (j < u.size() && u[j].x < k) {
                    if (l <= u[j].l && u[j].r <= r) res += u[j].c;
                    j++;
                }
                sum[l][r][k] = res;
            }
        }
    }
    cout << solve(0, n - 1, h) << endl;
    return 0;
}