#ifdef ONPC
    # define _GLIBCXX_DEBUG
    #define deb(a) cerr << "========" << #a << " = " << a << endl;
#else
    #define deb(a)
#endif
#define sz(a) ((int)((a).size()))
#include <bits/stdc++.h>

using namespace std;
//mt19937 rnd(239);
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;

const int N = 4, M = 111, BB = (1 << N);

int bst[BB][M];
int dp[BB][M];
int a[N][M];

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    int m;
    cin >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    int B = (1 << n);
    for (int i = 0; i < B; i++)
        for (int j = 0; j < m; j++)
            bst[i][j] = dp[i][j] = 0;
    for (int ms = 0; ms < B; ms++)
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int cur = 0;
                for (int k = 0; k < n; k++)
                {
                    int l = (k - j + n) % n;
                    if ((ms >> k) & 1)
                        cur += a[l][i];
                }
                bst[ms][i] = max(bst[ms][i], cur);
            }
        }
    for (int ms = 0; ms < B; ms++)
        for (int i = 0; i < m; i++)
        {
            dp[ms][i] = bst[ms][i];
            if (i)
                for (int s = ms; s > 0; s = (s - 1) & ms)
                {
                    dp[ms][i] = max(dp[ms][i], dp[s][i - 1] + bst[s ^ ms][i]);
                }
        }
    cout << dp[B - 1][m - 1] << '\n';
    return 0;
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int TET = 1e9;
    cin >> TET;
    for (int i = 1; i <= TET; i++)
    {
        if (solve())
            break;
        cout << '\n';
        #ifdef ONPC
            cout << "\n__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}