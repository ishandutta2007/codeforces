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
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    string s = "";
    for (int i = 0; i < n; i++)
        s.push_back('0');
    vector<string> ans(n + 1, s);
    int cnt = 0;
    for (int i = n; i > 0; i--)
        for (int j = 0; j < n; j++)
        {
            if (a[j] != i)
                continue;
            cnt++;
            for (int k = 0; k < i; k++)
                ans[(k + cnt) % (n + 1)][j] = '1';
        }
    cout << n + 1 << endl;
    for (int i = 0; i < n + 1; i++)
        cout << ans[i] << '\n';
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