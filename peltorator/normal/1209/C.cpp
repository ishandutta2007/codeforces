#ifdef ONPC
    # define _GLIBCXX_DEBUG
    #define deb(a) cerr << "========" << #a << " = " << a << endl;
#else
    #define deb(a)
#endif
#define sz(a) ((int)((a).size()))
#include <bits/stdc++.h>

using namespace std;
//mt19937 rnd(239);
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;

int solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t = s;
    sort(t.begin(), t.end());
    int pos = 0;
    vector<int> col(n, 2);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == t[pos])
        {
            col[i] = 1;
            pos++;
        }
    }
    vector<int> a;
    for (int i = 0; i < n; i++)
        if (col[i] == 1)
            a.push_back(s[i] - '0');
    for (int i = 0; i < n; i++)
        if (col[i] != 1)
            a.push_back(s[i] - '0');
    bool ok = 1;
    for (int i = 1; i < (int)a.size(); i++)
        if (a[i] < a[i - 1])
            ok = 0;
    if (ok)
    {
        for (int i = 0; i < n; i++)
            if (col[i] == 1)
                cout << '1';
            else
                cout << '2';
    }
    else
    {
        cout << "-";
    }
    cout << '\n';
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