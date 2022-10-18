#ifdef ONPC
    # define _GLIBCXX_DEBUG
#endif
#ifdef ONPC
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

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    ll h;
    cin >> h;
    vector<ll> a(n);
    for (ll &i : a)
        cin >> i;
    vector<ll> cur;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cur.push_back(a[i]);
        int pos = (int)cur.size() - 1;
        while (pos > 0 && cur[pos - 1] > cur[pos])
        {
            swap(cur[pos], cur[pos - 1]);
            pos--;
        }
        ll sum = 0;
        for (int j = (int)cur.size() - 1; j >= 0; j -= 2)
            sum += cur[j];
        if (sum <= h)
            ans = i + 1;
    }
    cout << ans << endl;
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