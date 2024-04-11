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
    vector<int> a(n);
    int sum = 0;
    vector<int> pos;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i])
        {
            sum++;
            pos.push_back(i);
        }
    }
    bool ok = 0;
    vector<int> ds;
    for (int i = 2; i <= sum; i++)
        if (sum % i == 0)
        {
            ok = 1;
            ds.push_back(i);
        }
    if (!ok)
    {
        cout << "-1\n";
        return 0;
    }
    ll anss = 1e18;
    for (int d : ds)
    {
        ll ans = 0;
        for (int i = 0; i < sum; i += d)
        {
            int x = pos[i + d / 2];
            for (int j = 0; j < d; j++)
                ans += abs(x - pos[i + j]);
        }
        anss = min(anss, ans);
    }
    cout << anss << '\n';
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