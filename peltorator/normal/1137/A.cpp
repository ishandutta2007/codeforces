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
    vector<vector<int> > a(n, vector<int>(m, 0)), le = a, g = a, le2 = a, g2 = a;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    for (int i = 0; i < n; i++)
    {
        vector<pair<int, int> > q;
        for (int j = 0; j < m; j++)
            q.push_back({a[i][j], j});
        sort(q.begin(), q.end());
        int cnt = 0;
        for (int j = 0; j < m; j++)
        {
            int t = j;
            while (t < m && q[t].first == q[j].first)
                t++;
            t--;
            for (int k = j; k <= t; k++)
            {
                le[i][q[k].second] = cnt;
//                g[i][q[k].second] = m - t - 1;
            }
            j = t;
            cnt++;
        }
        cnt = 0;
        for (int j = m - 1; j >= 0; j--)
        {
            int t = j;
            while (t >= 0 && q[t].first == q[j].first)
                t--;
            t++;
            for (int k = t; k <= j; k++)
            {
                g[i][q[k].second] = cnt;
//                g[i][q[k].second] = m - t - 1;
            }
            j = t;
            cnt++;
        }

    }
    for (int i = 0; i < m; i++)
    {
        vector<pair<int, int> > q;
        for (int j = 0; j < n; j++)
            q.push_back({a[j][i], j});
        sort(q.begin(), q.end());
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            int t = j;
            while (t < n && q[t].first == q[j].first)
                t++;
            t--;
            for (int k = j; k <= t; k++)
            {
                le2[q[k].second][i] = cnt;
//                g2[q[k].second][i] = n - t - 1;
            }
            j = t;
            cnt++;
        }
        cnt = 0;
        for (int j = n - 1; j >= 0; j--)
        {
            int t = j;
            while (t >= 0 && q[t].first == q[j].first)
                t--;
            t++;
            for (int k = t; k <= j; k++)
            {
                g2[q[k].second][i] = cnt;
//                g[i][q[k].second] = m - t - 1;
            }
            j = t;
            cnt++;
        }

    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << max(le[i][j], le2[i][j]) + max(g[i][j], g2[i][j]) + 1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}

int32_t main()
{
    #ifdef ONPC
        freopen("in.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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