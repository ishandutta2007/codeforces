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
    set<int> q;
    while (n--)
    {
        int x;
        cin >> x;
        q.insert(x);
    }
    if (sz(q) > 3)
    {
        cout << "-1\n";
        return 0;
    }
    if (sz(q) == 1)
    {
        cout << "0\n";
        return 0;
    }
    if (sz(q) == 2)
    {
        int x = *q.begin();
        q.erase(q.begin());
        int y = *q.begin();
        if (x % 2 == y % 2)
            cout << (y - x) / 2 << endl;
        else
            cout << y - x << endl;
        return 0;
    }
    vector<int> a;
    for (int i : q)
        a.push_back(i);
    if (a[0] + a[2] == a[1] + a[1])
        cout << a[2] - a[1] << endl;
    else
        cout << "-1\n";
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