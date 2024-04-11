#ifdef ONPC
    # define _GLIBCXX_DEBUG
    #define deb(a) cerr << "========" << #a << " = " << a << endl;
#else
    #define deb(a)
#endif
#define sz(a) (int)(a).size()


#include <bits/stdc++.h>

using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;

int solve()
{
    string s;
    if (!(cin >> s))
        return 1;
    int c = 0;
    for (int i = 0; i < sz(s); i++)
        if (s[i] == 'a')
            c++;
    c = (sz(s) - c) / 2;
    string t = s;
    while (c--)
        s.pop_back();
    string q = s;
    for (int i = 0; i < sz(s); i++)
        if (s[i] != 'a')
            q.push_back(s[i]);
    if (q == t)
        cout << s << endl;
    else
        cout << ":(\n";
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