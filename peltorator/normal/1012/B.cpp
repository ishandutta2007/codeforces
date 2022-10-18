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

using namespace std;

mt19937 rnd(239);

typedef long long ll;
typedef long double ld;

map<int, vector<int> > x, y;
map<int, int> used1, used2;
map<pair<int, int>, int> used;

void dfs(int xx, int yy)
{
    used[{xx, yy}] = 1;
    if (!used1[xx])
    {
        used1[xx] = 1;
        for (int i : x[xx])
            if (!used[{xx, i}])
                dfs(xx, i);
    }
    used1[xx] = 1;
    if (!used2[yy])
    {
        used2[yy] = 1;
        for (int i : y[yy])
            if (!used[{i, yy}])
                dfs(i, yy);
    }
    used2[yy] = 1;
}

int solve()
{
    ios::sync_with_stdio(0);
    ll n, m, q;
    if (!(cin >> n))
        return 1;
    cin >> m >> q;
    x.clear();
    y.clear();
    used2.clear();
    used.clear();
    used1.clear();
    vector<pair<int, int> > v;
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
        x[a].push_back(b);
        y[b].push_back(a);
    }  
    ll t = n + m - x.size() - y.size();
    ll k = 0;
    for (auto it : v)
        if (!used[it])
        {
            k++;
            dfs(it.first, it.second);
        }
    cout << k - 1 + t  << endl;
    return 0;
}

int32_t main()
{
    #ifdef ONPC
        freopen("in.txt", "r", stdin);
    #endif
    int T = 100;
    //cin >> T;
    for (int i = 1; i <= T; i++)
    {
        #ifdef ONPC
            cerr << "Test #" << i << ":\n";
        #endif
        if (solve())
            break;
        #ifdef ONPC
            cerr << "_______________________________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1000LL / CLOCKS_PER_SEC << " ms" << endl;
    #endif
    return 0;
}