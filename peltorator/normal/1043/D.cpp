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

vector<vector<int> > a, rev;

int solve()
{
    int n, m;
    cin >> n >> m;
    a.assign(m, vector<int>(n + 1, -1));
    rev = a;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            a[i][j]--;
            rev[i][a[i][j]] = j;
        }
    ll ans = 0;
    int last = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        bool ok = 1;
        if (i != n - 1)
            for (int j = 1; j < m; j++)
                if (a[j][rev[j][a[0][i]] + 1] != a[0][i + 1])
                    ok = 0;
        if (ok)
            last++;
        else
            last = 1;
        ans += last;
    }
    cout << ans << endl;
    return 1;
}

int32_t main()
{
    #ifdef ONPC
        freopen("in.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0); cin.tie(0);
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