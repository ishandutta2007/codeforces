#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <unordered_set>
#include <complex>
#include <unordered_map>
#include <bitset>
#include <ctime>
#include <cassert>
#include <random>

#ifdef ONPC
    #define deb(a) cerr << "       " << #a << " = " << a << endl;
#else
    #define deb(a)
#endif

using namespace std;

mt19937 rnd(time(0));

typedef long long ll;
typedef long double ld;

const int N = 2010;
const int INF = 1e9;
const int T = 26;

string s[N];

int d[N][N];
int cnt[N][N];

int dx[] = {0, 1};
int dy[] = {1, 0};

vector<pair<int, int> > mem[T][N];

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    int k;
    cin >> k;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            d[i][j] = INF;
    //if (s[0][0] == 'a')
        d[0][0] = 0;
 //   else
   //     d[0][0] = 1;
    queue<pair<int, int> > q;
    q.push({0, 0});
    while (q.size())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 2; i++)
        {
            int X = x + dx[i], Y = y + dy[i];
            if (X == n || Y == n)
                continue;
            int nd = d[x][y];
            if (s[x][y] != 'a')
                nd++;
            if (d[X][Y] > nd)
            {
                d[X][Y] = nd;
                q.push({X, Y});
            }
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cnt[i][j] = 0;
    for (int sum = 2 * n - 3; sum >= 0; sum--)
    {
        int li = min(sum, n - 1);
        vector<pair<pair<char, int>, pair<int, int> > > q;
        for (int i = li; i >= 0 && sum - li < n; i--)
        {
            int j = sum - i;
            cnt[i][j] = 1e9;
            for (int k = 0; k < 2; k++)
            {
                int x = i + dx[k], y = j + dy[k];
                if (x < n && y < n)
                    cnt[i][j] = min(cnt[i][j], cnt[x][y]);
            }
           // mem[s[i][j] - 'a'][cnt[i][j]].push_back({i, j});
            q.push_back({{s[i][j], cnt[i][j]}, {i, j}});
        }
        sort(q.begin(), q.end());
        int cur = 0;
        cnt[q[0].second.first][q[0].second.second] = cur;
        for (int i = 1; i < q.size(); i++)
        {
            if (q[i].first != q[i - 1].first)
                cur++;
            cnt[q[i].second.first][q[i].second.second] = cur;
        }
    }
    int bx = 0, by = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (d[i][j] <= k && (i + j > bx + by || (i + j == bx + by && cnt[i][j] < cnt[bx][by])))
            {
                bx = i;
                by = j;
            }
   // cout << bx + 1 << ' ' << by + 1 << endl;
    string ans = "";
        for (int i = 0; i < bx + by; i++)
            ans.push_back('a');
    if (d[n - 1][n - 1] < k || (d[n - 1][n - 1] == k && s[n - 1][n - 1] == 'a'))
    {
        cout << ans << 'a' << endl;
        return 0;
    }
    ans.push_back(s[bx][by]);
    while (bx < n - 1 || by < n - 1)
    {
        int x = -1, y = -1;
        for (int i = 0; i < 2; i++)
        {
            int X = bx + dx[i], Y = by + dy[i];
            if (X < n && Y < n && (x == -1 || cnt[x][y] > cnt[X][Y]))
                x = X, y = Y;
        }
        bx = x;
        by = y;
        ans.push_back(s[x][y]);
    }
    cout << ans << endl;
    return 0;
}

int32_t main()
{
    #ifdef ONPC
        freopen("in.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int T = 100;
    //cin >> T;
    for (int i = 1; i <= T; i++)
    {
        #ifdef ONPC
            cout << "Test #" << i << ":\n";
        #endif
        if (solve())
            break;
        #ifdef ONPC
            cout << "__________________________\n";
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1000LL / CLOCKS_PER_SEC << " ms" << endl;
    #endif
    return 0;
}