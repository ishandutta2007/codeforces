#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define sz(c) (int)(c).size()
#define ALL(c) (c).begin(), (c).end()

void solve (int n)
{
    int m, q;
    cin >> m >> q;

    vector<vector<pair<int, int>>> who(n, vector<pair<int, int>>(m));
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        who[i][j] = mp(i, j);
    vvi res(n, vi(m));

    int row = 0, col = 0;
    for (int i = 0; i < q; i++)
    {
        int t;
        cin >> t;
        if (t == 3)
        {
            int r, c, x;
            cin >> r >> c >> x;
            r--, c--;
            res[who[r][c].first][who[r][c].second] = x;
        }
        else if (t == 1)
        {
            int r;
            cin >> r;
            --r;
            rotate(who[r].begin(), who[r].begin() + 1, who[r].end());
        }
        else if (t == 2)
        {
            int c;
            cin >> c;
            --c;
            auto fst = who[0][c];
            for (int j = 1; j < n; j++)
                who[j - 1][c] = who[j][c];
            who[n - 1][c] = fst;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << res[i][j] << " \n"[j + 1 == m];
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while (cin >> n)
        solve(n);
}