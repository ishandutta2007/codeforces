#ifdef ONPC
    # define _GLIBCXX_DEBUG
    #define deb(a) cerr << "========" << #a << " = " << a << endl;
#else
    #define deb(a)
#endif
#define sz(a) ((int)((a).size()))
#include <bits/stdc++.h>
//#define string basic_string<unsigned char>
#define char unsigned char

using namespace std;
//mt19937 rnd(239);
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;

int solve()
{
    ll n;
    if (!(cin >> n))
        return 1;
    ll m;
    cin >> m;
    bool ok = 0;
    if (n == 1)
    {
        if (m == 1)
            ok = 1;
    }
    else if (n == 2)
    {
        if (m < 4)
            ok = 1;
    }
    else if (n == 3)
    {
        if (m < 4)
            ok = 1;
    }
    else
        ok = 1;
    cout << (ok ? "Yes\n" : "No\n");
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