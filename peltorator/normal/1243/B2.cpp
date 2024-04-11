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
    string s, t;
    cin >> s >> t;
    vector<int> ps;
    vector<pair<int, int> > ans;
    bool ok = 1;
    for (int i = 0; i < n; i++)
        if (s[i] != t[i])
        {
            int j = i + 1;
            while (j < n && t[j] != t[i])
                j++;
            if (j != n)
            {
                swap(s[i], t[j]);
                ans.push_back({i, j});
                continue;
            }
            j = i + 1;
            while (j < n && s[j] != t[i])
                j++;
            if (j == n)
            {
                ok = 0;
                break;
            }
            swap(s[j], t[i + 1]);
            ans.push_back({j, i + 1});
            swap(s[i], t[i + 1]);
            ans.push_back({i, i + 1});
        }
    if (ok)
    {
        cout << "Yes\n";
        cout << sz(ans) << endl;
        for (auto it : ans)
            cout << it.first + 1 << ' ' << it.second + 1 << '\n';
    }
    else
        cout << "No\n";
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