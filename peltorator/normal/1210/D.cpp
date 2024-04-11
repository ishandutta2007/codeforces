#ifdef ONPC
    # define _GLIBCXX_DEBUG
    #define deb(a) cerr << "========" << #a << " = " << a << endl;
#else
    #define deb(a)
#endif
#define sz(a) ((int)((a).size()))
#include <bits/stdc++.h>

using namespace std;
//mt19937 rnd(239);
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;

const int N = 100005;

vector<int> in[N], out[N];
int insz[N], outsz[N];
int t[N];
int cnt[N];

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        cnt[x]++;
        cnt[y]++;
        if (x > y)
            swap(x, y);
        in[x].push_back(y);
        out[y].push_back(x);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (ll)in[i].size() * (ll)out[i].size();
        insz[i] = in[i].size();
        outsz[i] = out[i].size();
    }
    cout << ans << endl;
    int q;
    cin >> q;
    int cnt1 = n;
    const int QQ = 3;
    for (int _ = 0; _ < q; _++)
    {
        int v;
        cin >> v;
        v--;
        ans -= (ll)insz[v] * (ll)outsz[v];
        for (int u : in[v])
        {
            if (t[u] < t[v])
                continue;
            ans -= (ll)insz[u];
            if (sz(in[u]) < QQ * cnt[u])
                in[u].push_back(v);
            insz[u]++;
            outsz[u]--;
            outsz[v]++;
            if (sz(out[v]) < QQ * cnt[v])
                out[v].push_back(u);
            ans += (ll)outsz[u];
        }
        in[v].clear();
        insz[v] = 0;
        cout << ans << '\n';
        t[v] = cnt1++;
    }
    return 0;
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int TET = 1e9;
    // cin >> TET;
    for (int i = 1; i <= TET; i++)
    {
        if (solve())
            break;
        cout << '\n';
        #ifdef ONPC
            cout << "\n__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}