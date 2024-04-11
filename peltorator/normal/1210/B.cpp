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

const int N = 7123;

pair<ll, ll> v[N];
ll good[N];

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    for (int i = 0; i < n; i++)
        cin >> v[i].first;
    for (int i = 0; i < n; i++)
        cin >> v[i].second;
    sort(v, v + n);
    int ss = 0;
    for (int i = 0; i < n; i++)
        if (i + 1 < n && (!i || v[i - 1].first != v[i].first) && v[i + 1].first == v[i].first)
            good[ss++] = v[i].first;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        bool ok = 0;
        for (int j = 0; j < ss; j++)
            if ((good[j] & v[i].first) == v[i].first)
            {
                ok = 1;
                break;
            }
        if (ok)
            ans += v[i].second;

    }
    cout << ans << endl;
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