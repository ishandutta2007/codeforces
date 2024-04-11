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

ll ask1(int i, int j, int k)
{
    cout << "1 " << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
    ll x;
    cin >> x;
    return x;
}

ll ask2(int i, int j, int k)
{
    cout << "2 " << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
    ll x;
    cin >> x;
    return x;
}

vector<int> v[2];

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    v[0] = {0, 1};
    v[1] = {1, 0};
    vector<ll> s(n, 0);
    for (int j = 2; j < n; j++)
    {
        s[j] = ask1(0, 1, j);
        ll t = ask2(0, 1, j);
        int ind = (t == 1 ? 1 : 0);
        int bst = 1;
        for (int i = 0; i < sz(v[ind]); i++)
            if (s[v[ind][i]] > s[v[ind][bst]])
                bst = i;
        ll t2 = ask2(v[ind][0], v[ind][bst], j);
        bool fir = 1;
        if (t2 == 1)
            fir = 0;
        if (fir)
        {
            int x = 0;
            while (x < bst && s[v[ind][x]] < s[j])
                x++;
            v[ind].push_back(0);
            for (int k = sz(v[ind]) - 1; k > x; k--)
                v[ind][k] = v[ind][k - 1];
            v[ind][x] = j;
        }
        else
        {
            int x = sz(v[ind]) - 1;
            while (x > bst && s[v[ind][x]] < s[j])
                x--;
            x++;
            v[ind].push_back(0);
            for (int k = sz(v[ind]) - 1; k > x; k--)
                v[ind][k] = v[ind][k - 1];
            v[ind][x] = j;
        }
    }
    cout << "0 ";
    for (int i : v[0])
        cout << i + 1 << ' ';
    for (int i = 1; i + 1 < sz(v[1]); i++)
        cout << v[1][i] + 1 << ' ';
    cout << '\n';
    return 1;
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