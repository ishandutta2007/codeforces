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
#include <iomanip>

#ifdef ONPC
    #define deb(a) cerr << "       " << #a << " = " << a << endl;
#else
    #define deb(a)
#endif

using namespace std;

mt19937 rnd(time(0));


const int N = 505;
const int T = 26;

int dp[N][N];
int dp2[N][N][T];

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    string s;
    cin >> s;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            dp[i][j] = 1e9;
            for (int k = 0; k < T; k++)
                dp2[i][j][k] = 1e9;
        }
    for (int i = 0; i < N; i++)
        dp[i][i] = 0;
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j < n && s[j] == s[i])
        {
            j++;
            dp[i][j] = 1;
        }
    }
    for (int l = 1; l <= n; l++)
        for (int i = 0; i + l <= n; i++)
        {
            int j = i + l;
            for (int k = i + 1; k < j; k++)
            {
                int cnt = 0;
                if (k < j && s[k - 1] == s[k])
                    cnt++;
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] - cnt);
                dp2[i][j][s[k - 1] - 'a'] = min(dp2[i][j][s[k - 1] - 'a'], dp[i][k] + dp[k][j] - 1);
                dp[i][j] = min(dp[i][j], dp2[i][k][s[k] - 'a'] + dp[k][j]);
            }
            
        }
    cout << dp[0][n] << endl;
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