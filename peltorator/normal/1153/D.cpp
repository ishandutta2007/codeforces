#ifdef ONPC
    # define _GLIBCXX_DEBUG
    #define deb(a) cerr << "========" << #a << " = " << a << endl;
#else
    #define deb(a)
#endif
#define sz(a) (int)(a).size()


#include <bits/stdc++.h>

using namespace std;
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnd(time(0));

typedef long long ll;

const int N = 300005;

vector<int> g[N];
int c[N];

int dfs(int v)
{
    if (!sz(g[v]))
        return 1;
    int sum = 0, mn = 1e9;
    for (int u : g[v])
    {
        int cnt = dfs(u);
        sum += cnt;
        mn = min(mn, cnt);
    }
    if (!c[v])
        return sum;
    else
        return mn;
}

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    for (int i = 0; i < n; i++)
        g[i].clear();
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 1; i < n; i++)
    {
        int x;
        cin >> x;
        g[x - 1].push_back(i);
    }
    int k = 0;
    for (int i = 0; i < n; i++)
        if (!sz(g[i]))
            k++;
    cout << k - dfs(0) + 1 << endl;
    /*
    int l = 0, r = k;
    while (r - l > 1)
    {
        int mid = (r + l) / 2;
        if (dfs(0, mid) <= mid)
            r = mid;
        else
            l = mid;
    }
    cout << r << endl;*/
    return 0;
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
    return 0;
}