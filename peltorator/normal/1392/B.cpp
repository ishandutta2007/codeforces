#ifdef ONPC
    #define _GLIBCXX_DEBUG
    #define deb(a) cerr << "========" << #a << " = " << a << endl;
#else
    #define deb(a)
#endif
#define sz(a) ((int)((a).size()))
#include <bits/stdc++.h>
#define char unsigned char

using namespace std;
mt19937 rnd(239);
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    ll k;
    cin >> k;
    vector<ll> a(n);
    for (ll &i : a)
        cin >> i;
    ll mx = a[0], mn = a[0];
    for (int i = 0; i < n; i++)
    {
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }
    if (k % 2)
    {
        for (int i = 0; i < n; i++)
            cout << mx - a[i] << ' ';
        cout << '\n';
    }
    else
    {
        for (int i = 0; i < n; i++)
            cout << a[i] - mn << ' ';
        cout << '\n';
    }
    return 0;
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int TET = 1e9;
    cin >> TET;
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