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

const int N = 123;

string s[N];
string t[N];

vector<char> c;

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    int m;
    cin >> m;
    int k;
    cin >> k;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        t[i] = s[i];
        for (int j = 0; j < m; j++)
            if (s[i][j] == 'R')
                cnt++;
    }
    int per = cnt / k, num = cnt % k;
    vector<pair<int, int> > q;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            for (int j = 0; j < m; j++)
                q.push_back({i, j});
        else
            for (int j = m - 1; j >= 0; j--)
                q.push_back({i, j});
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            t[i][j] = c[k - 1];
    int ind = 0;
    for (int i = 0; i < k; i++)
    {
        int cur = per;
        if (i < num)
            cur++;
        while (cur)
        {
            t[q[ind].first][q[ind].second] = c[i];
            if (s[q[ind].first][q[ind].second] == 'R')
                cur--;
            ind++;
        }
    }
    for (int i = 0; i < n; i++)
        cout << t[i] << '\n';
    return 0;
}

int32_t main()
{
    for (char x = 'a'; x <= 'z'; x++) c.push_back(x);
    for (char x = 'A'; x <= 'Z'; x++) c.push_back(x);
    for (char x = '0'; x <= '9'; x++) c.push_back(x);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int TET = 1e9;
    cin >> TET;
    for (int i = 1; i <= TET; i++)
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