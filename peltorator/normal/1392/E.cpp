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
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ll x = i + j - 1;
            cout << (1LL << x) * (ll)(i % 2) << ' ';
        }
        cout << '\n';
    }
    cout << endl;
    int q;
    cin >> q;
    while (q--)
    {
        ll cnt;
        cin >> cnt;
        int x = 0, y = 0;
        cout << "1 1\n";
        while (x != n - 1 || y != n - 1)
        {
            ll t = x + y;
            ll kek = (cnt >> t) & 1LL;
            if (x % 2 == kek)
                y++;
            else
                x++;
            cnt -= (1LL << t) * (ll)(x % 2);
            cout << x + 1 << ' ' << y + 1 << '\n';
        }
        cout << endl;
    }
    return 0;
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int TET = 1;
    //cin >> TET;
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