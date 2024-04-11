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

typedef long long ll;
typedef long double ld;

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    int m;
    cin >> m;
    vector<vector<int> > v(n);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        v[x].push_back((y - x + n) % n);
    }
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        mx = max(mx, (int)v[i].size());
        sort(v[i].rbegin(), v[i].rend());
    }
    int lst = 0;
    for (int i = 0; i < n; i++)
        if (v[i].size() == mx)
            lst = max(lst, i + v[i].back());
    for (int i = 0; i < n; i++)
    {
       /* cout << (mx - 1) * n + lst << ' ';
        lst--;
        if (v[i].size() == mx)            
            lst = max(lst, n - 1 + v[i].back());*/
        ll ans = 0;
        for (int j = 0; j < n; j++)
        {
            int k = (i + j) % n;
            if (v[k].size())
                ans = max(ans, (ll)j + (ll)((int)v[k].size() - 1) * (ll)n + (ll)v[k].back());
        }
        cout << ans << ' ';
    }
    cout << endl;
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