#ifdef ONPC
    # define _GLIBCXX_DEBUG
    #define deb(a) cerr << "========" << #a << " = " << a << endl;
#else
    #define deb(a)
#endif
#define sz(a) ((int)((a).size()))
#include <bits/stdc++.h>

using namespace std;
mt19937 rnd(239);

#define X first
#define Y second
#define pb push_back
#define eb emplace_back
#define ob pop_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    vector<vector<int> > a(n, vector<int>(n));
    int cnt = 0;
    for (int i = 0; i < n; i += 4)
    {
        for (int j = 0; j < n; j += 4)
        {
            for (int k = 0; k < 4; k++)
                for (int l = 0; l < 4; l++)
                    a[i + k][j + l] = cnt++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
    return 0;
    set<int> q;
    for (int i = 0; i < n; i++)
    {
        int t = 0;
        for (int j = 0; j < n; j++)
            t ^= a[i][j];
        q.insert(t);
        t = 0;
        for (int j = 0; j < n; j++)
            t ^= a[j][i];
        q.insert(t);
    }
    for (int i : q)
        cout << i << ' ' ;
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
}