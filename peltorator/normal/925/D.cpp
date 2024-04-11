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

#define sz(a) (int)((a).size())

using namespace std;

mt19937 rnd(239);

typedef long long ll;
typedef long double ld;

const int N = 300001;

vector<int> g[N], used, pr;

vector<int> answ, cnt;

vector<int> cur;
vector<int> dwn[N];
int n;

void win(vector<int> ans)
{
    if (answ[0] == -1 || answ.size() > ans.size())
        answ = ans;
    return;
}

void dfs(int v)
{
    cur.push_back(v);
    used[v] = 1;
    if (v == n)
    {
      //  win(cur);
    }
    for (int u : g[v])
        if (!used[u])
        {
            cnt[v]++;
            pr[u] = v;
            dwn[v].push_back(u);
            dfs(u);
        }
    cur.pop_back();
}

set<pair<int, int> > q;

int solve()
{
    ios::sync_with_stdio(0);
    if (!(cin >> n))
    {
        return 1;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
        q.insert({x, y});
        q.insert({y, x});
    }
    answ = {-1};
    cnt.assign(n + 1, 0);
    used.assign(n + 1, 0);
    pr.assign(n + 1, -1);
    dfs(1);
    if (used[n])
    {
        queue<int> q;
        q.push(1);
        vector<int> used1(n + 1, 0);
        vector<int> pr(n + 1, 0);
        while (true)
        {
            int v = q.front();
            q.pop();
            used1[v] = 1;
            if (v == n)
                break;
            for (int u : g[v])
                if (!used1[u])
                {
                    used1[u] = 1;
                    pr[u] = v;
                    q.push(u);
                }
        }
        vector<int> cur;
        int e = n;
        while (e != 1)
        {
            cur.push_back(e);
            e = pr[e];
        }
        cur.push_back(1);
        reverse(cur.begin(), cur.end());
        win(cur);
    }
    bool ok = true;
    for (int i = 1; i <= n; i++)
        if (used[i])
        {
            int j = pr[i];
            int last = i;
            while (j != -1 && ok)
            {
                if (!q.count({j, i}))
                {
                    vector<int> kek = {1, j, last, i, j, n};
                    if (j == 1)
                        kek = {1, last, i, 1, n};
                    win(kek);
                    ok = 0;
                }
                last = j;
                j = pr[j];
            }
            if (!q.count({i, 1}) && q.count({1, pr[i]}))
            {
                vector<int> kek = {1, pr[i], i, 1, n};
                win(kek);
            }
        }
    for (int i = 2; i <= n; i++)
        if (used[i] && cnt[i] > 1)
        {
            vector<int> ans = {1, dwn[i][0], i, dwn[i][1], dwn[i][0], n};
            win(ans);
        }
    if (answ[0] == -1)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << (int)answ.size() - 1 << endl;
    for (int i = 0; i < answ.size(); i++)
        cout << answ[i] << ' ';
    cout << endl;
    return 0;
}

int32_t main()
{
    #ifdef ONPC
        freopen("in.txt", "r", stdin);
    #endif
    int T = 100;
    //cin >> T;
    for (int i = 1; i <= T; i++)
    {
        #ifdef ONPC
            cerr << "Test #" << i << ":\n";
        #endif
        if (solve())
            break;
        #ifdef ONPC
            cerr << "_______________________________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1000LL / CLOCKS_PER_SEC << " ms" << endl;
    #endif
    return 0;
}