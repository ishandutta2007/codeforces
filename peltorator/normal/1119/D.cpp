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
    vector<ll> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    sort(s.begin(), s.end());
    vector<ll> v;
    for (int i = 1; i < n; i++)
        v.push_back(s[i] - s[i - 1]);
    sort(v.begin(), v.end());
    vector<ll> pref(n, 0);
    for (int i = 0; i < (int)v.size(); i++)
        pref[i + 1] = pref[i] + v[i];
    int q;
    cin >> q;
    while (q--)
    {
        ll x, y;
        cin >> x >> y;
        y -= x;
        y++;
        int l = -1, r = (int)v.size();
        while (r - l > 1)
        {
            int mid = (r + l) / 2;
            if (v[mid] > y)
                r = mid;
            else
                l = mid;
        }
        cout << (ll)(n - r) * y + pref[r] << ' ';
    }
    cout << endl;
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