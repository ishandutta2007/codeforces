#ifdef ONPC
    # define _GLIBCXX_DEBUG
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
    int k;
    cin >> k;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    vector<pair<int, int> > b(n);
    for (int i = 0; i < n; i++)
        b[i] = {a[i], i};
    sort(b.rbegin(), b.rend());
    vector<int> ans(n, 0);
    vector<int> l(n, 0), r(n, 0);
    for (int i = 0; i < n; i++)
        l[i] = i - 1, r[i] = i + 1;
    r[n - 1] = -1;
    int pos = 0;
    for (int i = 0;; i++)
    {
        while (pos < n && a[b[pos].second] == -1)
            pos++;
        if (pos == n)
            break;
        int j = b[pos].second;
        int kek = l[j];
        for (int cnt = 0, x = j; cnt <= k && x != -1; x = l[x], cnt++)
            a[x] = -1, ans[x] = i % 2, kek = l[x];
        int lol = r[j];
        for (int cnt = 0, x = j; cnt <= k && x != -1; x = r[x], cnt++)
            a[x] = -1, ans[x] = i % 2, lol = r[x];
        if (kek != -1)
            r[kek] = lol;
        if (lol != -1)
            l[lol] = kek;
    }
    for (int i : ans)
        cout << i + 1;
    cout << endl;
    return 0;
}

int32_t main()
{
#ifdef ONPC
    freopen("out", "w", stdout);
#endif
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