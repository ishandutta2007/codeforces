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

#ifdef ONPC
const int N = 100;
#else
const int N = 1123456;
#endif

string s[N];
string tt[N];

int n, m;

int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};

bool check(int x, int y)
{
    return x >= 0 && y >= 0 && x < n && y < m;
}

vector<vector<int>> d, d2;

bool f(int t)
{
    queue<pair<int, int> > q;
    d.assign(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (s[i][j] == '.')
            {
                d[i][j] = 0;
                q.push({i, j});
            }
    while (sz(q))
    {
        auto it = q.front();
        q.pop();
        int x = it.first, y = it.second;
        if (d[x][y] != t)
            for (int i = 0; i < 8; i++)
            {
                int xx = x + dx[i], yy = y + dy[i];
                if (check(xx, yy) && d[xx][yy] == -1)
                {
                    d[xx][yy] = d[x][y] + 1;
                    q.push({xx, yy});
                }
            }
    }
    d2.assign(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (i >= t && j >= t && i < n - t && j < m - t && d[i][j] == -1)
                q.push({i, j}), d2[i][j] = 0, tt[i][j] = 'X';
            else
                tt[i][j] = '.';
    while (sz(q))
    {
        auto it = q.front();
        q.pop();
        int x = it.first, y = it.second;
        if (d2[x][y] != t)
            for (int i = 0; i < 8; i++)
            {
                int xx = x + dx[i], yy = y + dy[i];
                if (check(xx, yy) && d2[xx][yy] == -1)
                {
                    d2[xx][yy] = d2[x][y] + 1;
                    q.push({xx, yy});
                }
            }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if ((d2[i][j] == -1) ^ (s[i][j] == '.'))
                return false;
    return true;
}

int solve()
{
    if (!(cin >> n))
        return 1;
    cin >> m;
    for (int i = 0; i < n; i++)
        cin >> s[i], tt[i] = s[i];
    int l = 0, r = n + m + 10;
    while (r - l > 1)
    {
        int mid = (r + l) / 2;
        if (f(mid))
            l = mid;
        else
            r = mid;
    }
    f(l);
    cout << l << endl;
    for (int i = 0; i < n; i++)
        cout << tt[i] << '\n';
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