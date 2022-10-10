#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <iomanip>
#include <bitset>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

const int M = 50000;

vector <int> ok[M];
map <vector <int>, int> ind;
int ops[M][10];

int sz = 0;

int go(int cur, int d)
{
    if (ops[cur][d] != -1) return ops[cur][d];
    vector <int> l, r;
    for (int x : ok[cur]) l.push_back(x - d);
    for (int x : ok[cur]) r.push_back(x + d);
    vector <int> go(l.size() + r.size());
    merge(l.begin(), l.end(), r.begin(), r.end(), go.begin());
    go.resize(unique(go.begin(), go.end()) - go.begin());
    if (ind.count(go))
    {
        return ops[cur][d] = ind[go];
    }
    else
    {
        ind[go] = sz;
        ok[sz] = go;
        sz++;
        return ops[cur][d] = sz - 1;
    }
}

const int N = 21;

ll dp[N][N][M];

int kek = 0;

ll dfs(int i, int k, int cur)
{
    if (dp[i][k][cur] != -1)
    {
        return dp[i][k][cur];
    }
    if (i == 19)
    {
        bool good = false;
        for (int x : ok[cur])
        {
            if (abs(x) <= k)
            {
                good = true;
            }
        }
        if (good)
        {
            return dp[i][k][cur] = 1;
        }
        else
        {
            return dp[i][k][cur] = 0;
        }
    }
    else
    {
        ll ans = 0;
        for (int d = 0; d < 10; d++)
        {
            ans += dfs(i + 1, k, go(cur, d));
        }
        return dp[i][k][cur] = ans;
    }
}

ll get(ll x, int k)
{
    string s = "";
    int it = 19;
    while (it--)
    {
        s += (x % 10 + '0');
        x /= 10;
    }
    reverse(s.begin(), s.end());
    int v = 0;
    ll ans = 0;
    for (int i = 0; i < (int) s.size(); i++)
    {
        for (int d = 0; d < s[i] - '0'; d++)
        {
            int to = go(v, d);
            ans += dfs(i + 1, k, to);
        }
        v = go(v, s[i] - '0');
    }
    return ans + dfs(19, k, v);
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    for (int i = 0; i < M; i++) for (int j = 0; j < 10; j++) ops[i][j] = -1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                dp[i][j][k] = -1;
            }
        }
    }
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector <int> t = {0};
    ok[0] = t;
    ind[t] = 0;
    sz = 1;
    for (int k = 0; k <= 9; k++)
    {
        dfs(0, k, 0);
    }
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--)
    {
        ll l, r;
        int k;
        cin >> l >> r >> k;
        cout << get(r, k) - get(l - 1, k) << '\n';
    }
}