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
    int mx = 0;
    for (int &i : a)
        cin >> i, mx = max(mx, i);
    vector<int> bst(n + 1, 0);
    int m;
    cin >> m;
    bool ok = false;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x >= mx)
            ok = true;
        bst[y] = max(bst[y], x);
    }
    for (int i = n; i > 0; i--)
        bst[i - 1] = max(bst[i], bst[i - 1]);
    if (!ok)
    {
        cout << "-1\n";
        return 0;
    }
    int cnt = 0;
    int pos = 0;
    while (pos < n)
    {
        int nxt = pos;
        int curmx = a[pos];
        while (nxt + 1 < n && bst[nxt - pos + 2] >= max(a[nxt + 1], curmx))
        {
            curmx = max(a[nxt + 1], curmx);
            nxt++;
        }
        cnt++;
        pos = nxt + 1;
    }
    cout << cnt << '\n';
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