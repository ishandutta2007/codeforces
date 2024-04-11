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
    int n;
    if (!(cin >> n))
        return 1;
    int df = 0;
    vector<ll> a(n);
    vector<ll> b(n);
    for (ll &i : a)
        cin >> i;
    for (ll &i : b)
        cin >> i;
    for (int i = 0; i < n; i++)
        if (a[i] != b[i])
            df = b[i] - a[i];
    if (df < 0)
    {
        cout << "NO\n";
        return 0;
    }
    for (int i = 0; i < n; i++)
        if (a[i] != b[i] && df != b[i] - a[i])
        {
            cout << "NO\n";
            return 0;
        }
    int stt = 0;
    for (int i = 0; i < n; i++)
        if (a[i] != b[i])
        {
            if (stt == 2)
            {
                cout << "NO\n";
                return 0;
            }
            else if (stt == 0)
                stt = 1;
        }
        else if (stt == 1)
            stt = 2;
    cout << "YES\n";
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