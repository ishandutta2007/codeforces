#ifdef ONPC
    # define _GLIBCXX_DEBUG
    #define deb(a) cerr << "========" << #a << " = " << a << endl;
#else
    #define deb(a)
#endif
#define sz(a) (int)(a).size()
#include <bits/stdc++.h>

using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;

string a[3];

vector<vector<int> > p = {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};

const int N = 2e5;
const int D = 26;

const int Q = 260;

int used[N];

int nxt[D][N];

int curr[D];

int dp[Q][Q][Q];


int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    int q;
    cin >> q;
    string s;
    cin >> s;
    for (int i = 0; i < n + 5; i++)
        used[i] = 0;
    for (int i = 0; i < 26; i++)
        curr[i] = n + 1;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < D; j++)
            nxt[j][i + 1] = curr[j];
        curr[s[i] - 'a'] = i + 1;
    }
    for (int j = 0; j < D; j++)
        nxt[j][0] = curr[j];
    for (int i = 0; i < 3; i++)
        a[i] = "";
    dp[0][0][0] = 0;
    for (int zz = 0; zz < q; zz++)
    {
        char c;
        cin >> c;
        int pos;
        cin >> pos;
        pos--;
        if (c == '+')
        {
            char x;
            cin >> x;
            a[pos].push_back(x);
            int ch = x - 'a';
            if (pos == 2)
            {
                int k = sz(a[pos]) - 1;
                for (int i = 0; i <= sz(a[0]); i++)
                    for (int j = 0; j <= sz(a[1]); j++)
                        dp[i][j][k + 1] = n + 1;
                for (int i = 0; i <= sz(a[0]); i++)
                    for (int j = 0; j <= sz(a[1]); j++)
                    {
                        if (dp[i][j][k] != n + 1)
                        {
                            int go = nxt[ch][dp[i][j][k]];
                            dp[i][j][k + 1] = min(dp[i][j][k + 1], go);
                        }
                        if (dp[i][j][k + 1] != n + 1)
                        {
                            if (i < sz(a[0]))
                            {
                                dp[i + 1][j][k + 1] = min(dp[i + 1][j][k + 1], nxt[a[0][i] - 'a'][dp[i][j][k + 1]]);
                            }
                            if (j < sz(a[1]))
                            {
                                dp[i][j + 1][k + 1] = min(dp[i][j + 1][k + 1], nxt[a[1][j] - 'a'][dp[i][j][k + 1]]);
                            }

                        }
                    }
            }
            else if (pos == 1)
            {
                int j = sz(a[pos]) - 1;
                for (int i = 0; i <= sz(a[0]); i++)
                    for (int k = 0; k <= sz(a[2]); k++)
                        dp[i][j + 1][k] = n + 1;
                for (int i = 0; i <= sz(a[0]); i++)
                    for (int k = 0; k <= sz(a[2]); k++)
                    {
                        if (dp[i][j][k] != n + 1)
                        {
                            int go = nxt[ch][dp[i][j][k]];
                            dp[i][j + 1][k] = min(dp[i][j + 1][k], go);
                        }
                        if (dp[i][j + 1][k] != n + 1)
                        {
                            if (i < sz(a[0]))
                            {
                                dp[i + 1][j + 1][k] = min(dp[i + 1][j + 1][k], nxt[a[0][i] - 'a'][dp[i][j + 1][k]]);
                            }
                            if (k < sz(a[2]))
                            {
                                dp[i][j + 1][k + 1] = min(dp[i][j + 1][k + 1], nxt[a[2][k] - 'a'][dp[i][j + 1][k]]);
                            }

                        }
                    }
            }
            else if (pos == 0)
            {
                int i = sz(a[pos]) - 1;
                for (int j = 0; j <= sz(a[1]); j++)
                    for (int k = 0; k <= sz(a[2]); k++)
                        dp[i + 1][j][k] = n + 1;
                for (int j = 0; j <= sz(a[1]); j++)
                    for (int k = 0; k <= sz(a[2]); k++)
                    {
                        if (dp[i][j][k] != n + 1)
                        {
                            int go = nxt[ch][dp[i][j][k]];
                            dp[i + 1][j][k] = min(dp[i + 1][j][k], go);
                        }
                        if (dp[i + 1][j][k] != n + 1)
                        {
                            if (j < sz(a[1]))
                            {
                                dp[i + 1][j + 1][k] = min(dp[i + 1][j + 1][k], nxt[a[1][j] - 'a'][dp[i + 1][j][k]]);
                            }
                            if (k < sz(a[2]))
                            {
                                dp[i + 1][j][k + 1] = min(dp[i + 1][j][k + 1], nxt[a[2][k] - 'a'][dp[i + 1][j][k]]);
                            }
                        }
                    }
            }


        }
        else
        {
            a[pos].pop_back();
        }
        
        cout << (dp[sz(a[0])][sz(a[1])][sz(a[2])] <= n ? "YES\n" : "NO\n");
    }
    return 1;
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int TET = 1e9;
    //cin >> TET;
    while (TET--)
    {
        if (solve())
            break;
        #ifdef ONPC
            cout << "\n__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}