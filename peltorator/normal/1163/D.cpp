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

const int N = 1005;

const int M = 55;

int f[M][M], s[M][M];

int dp[M][M][N];

int solve()
{
    string ss;
    if (!(cin >> ss))
        return 1;
    string a, b;
    cin >> a >> b;
    for (int i = 0; i <= sz(a); i++)
    {
        for (int j = 0; j < 26; j++)
        {
           f[i][j] = 0;
           string str = "";
           str += (char)(j + 'a');
           if (a[0] == j + 'a')
                f[i][j] = 1;
            for (int k = i - 1; k >= 0; k--)
            {
                str.push_back(a[k]);
                string t;
                if (sz(str) > sz(a))
                    continue;
                for (int l = 0; sz(t) < sz(str); l++)
                    t.push_back(a[l]);
                reverse(t.begin(), t.end());
                if (str == t)
                    f[i][j] = sz(str);
            }
         //   cout << f[i][j] << ' ' ;
        }
        //cout << endl;
    }
    for (int i = 0; i <= sz(b); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            s[i][j] = 0;
            string str = "";
            str += (char)(j + 'a');
            if (b[0] == j + 'a')
                s[i][j] = 1;
            for (int k = i - 1; k >= 0; k--)
            {
                str.push_back(b[k]);
                string t;
                if (sz(str) > sz(b))
                    continue;
                for (int l = 0; sz(t) < sz(str); l++)
                    t.push_back(b[l]);
                reverse(t.begin(), t.end());
                if (str == t)
                    s[i][j] = sz(str);
            }
         //   cout << s[i][j] << ' ';
        }
  //      cout << endl;
    }
    for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++)
            for (int k = 0; k < N; k++)
                dp[i][j][k] = -1e9;
    dp[0][0][0] = 0;
    int n = sz(ss);
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= sz(a); j++)
            for (int k = 0; k <= sz(b); k++)
                for (int l = 0; l < 26; l++)
                {
                    if (ss[i] != '*' && ss[i] != 'a' + l)
                        continue;
                    int cur = dp[j][k][i];
                    if (cur < -1e8)
                        continue;
                    if (f[j][l] == sz(a))
                        cur++;
                    if (s[k][l] == sz(b))
                        cur--;
                    int &t = dp[f[j][l]][s[k][l]][i + 1];
                    t = max(t, cur);
                }
    int ans = -1e9;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++)
            ans = max(ans, dp[i][j][n]);
    cout << ans << endl;
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