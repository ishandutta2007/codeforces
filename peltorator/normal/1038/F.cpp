#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <unordered_set>
#include <complex>
#include <unordered_map>
#include <bitset>
#include <ctime>
#include <cassert>
#include <random>

#define sz(a) (int)((a).size())
#ifdef ONPC
    #define deb(a) cerr << "       " << #a << " = " << a << endl;
#else
    #define deb(a)
#endif

using namespace std;

mt19937 rnd(time(0));

typedef long long ll;
typedef long double ld;

const int N = 123, T = 2;

ll dp[N][N][N];
int suf[N][T];

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    string ss;
    cin >> ss;
    int m = ss.size();
    vector<int> s(m);
    for (int i = 0; i < m; i++)
        s[i] = ss[i] - '0';
    vector<int> pref(m, 0);
    for (int i = 1; i < m; i++)
    {
        int j = pref[i - 1];
        while (j && s[j] != s[i])
            j = pref[j - 1];
        if (s[j] == s[i])
            j++;
        pref[i] = j;
    }
    for (int i = 0; i < m; i++)
        suf[i][s[i]] = i + 1, suf[i][!s[i]] = (i ? suf[pref[i - 1]][!s[i]] : 0);
    suf[m][0] = suf[m][1] = m;
    ll ans = 0;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= m; j++)
            for (int k = 0; k <= m; k++)
                for (int l = 0; l <= n; l++)
                    dp[j][k][l] = 0;
        dp[i][0][0] = 1;
        for (int l = 0; l < n; l++)
            for (int i = 0; i <= m; i++)
                for (int j = 0; j <= m; j++)
                    dp[suf[i][0]][suf[j][0]][l + 1] += dp[i][j][l], dp[suf[i][1]][suf[j][1]][l + 1] += dp[i][j][l];
        ans += dp[m][i][n];
    }
    cout << ans << endl;
    return 0;
}


int32_t main()
{
    #ifdef ONPC
        freopen("in.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int T = 100;
    //cin >> T;
    for (int i = 1; i <= T; i++)
    {
        #ifdef ONPC
            cout << "Test #" << i << ":\n";
        #endif
        if (solve())
            break;
        #ifdef ONPC
            cout << "__________________________\n";
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1000LL / CLOCKS_PER_SEC << " ms" << endl;
    #endif
    return 0;
}