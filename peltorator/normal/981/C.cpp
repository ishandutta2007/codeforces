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

const int N = 200001;

vector<int> g[N];

int solve()
{
    ios::sync_with_stdio(0);
    int n;
    if (!(cin >> n))
    {
        return 1;
    }
    for (int i = 1; i <= n; i++)
        g[i].clear();
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int x = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (g[i].size() > 2)
            x++, cnt = i;
    if (x == 0)
    {
        cout << "Yes\n";
        cout << 1 << endl;
        vector<int> q;
        for (int i = 1; i <= n; i++)
            if (g[i].size() == 1)
                q.push_back(i);
        cout << q[0] << ' ' << q[1] << endl;
    }
    else if (x == 1)
    { 
        cout << "Yes\n";
        int kek = 0;
        for (int i = 1; i <= n; i++)
            if (g[i].size() == 1)
                kek++;
        cout << kek << endl;
        for (int i = 1; i <= n; i++)
            if (g[i].size() == 1)
                cout << cnt << ' ' << i << '\n';
        cout << endl;
        return 0;
    }   
    else
    {
        cout << "No\n";
        return 0;
    }
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