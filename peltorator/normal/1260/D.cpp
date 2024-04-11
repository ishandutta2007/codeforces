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
    int m;
    if (!(cin >> m))
        return 1;
    int n;
    cin >> n;
    int k, t;
    cin >> k >> t;
    vector<int> a(m);
    for (int i = 0; i < m; i++)
        cin >> a[i];
    sort(a.rbegin(), a.rend());
    vector<int> l(k), r(k), d(k);
    for (int i = 0; i < k; i++)
        cin >> l[i] >> r[i] >> d[i];
    int L = 0, R = m + 1;
    while (R - L > 1)
    {
        int mid = (R + L) / 2;
        int sml = a[mid - 1];
        vector<pair<int, int> > v;
        for (int i = 0; i < k; i++)
            if (d[i] > sml)
                v.push_back({l[i] - 1, -1}), v.push_back({r[i], 1});
        int cnt = 0;
        int bal = 0;
        int lst = 0;
        sort(v.begin(), v.end());
        for (int i = 0; i < sz(v); i++)
        {
            if (bal)
                cnt += v[i].first - lst;
            lst = v[i].first;
            bal += v[i].second;
        }
        if (2 * cnt + n + 1 <= t)
            L = mid;
        else
            R = mid;
    }
    cout << L << endl;
    return 0;
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int TET = 1e9;
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