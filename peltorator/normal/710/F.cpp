#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <unordered_set>
#include <complex>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cmpl;

vector<vector<int> > pusto;
vector<int> pustota;
vector<ll> pustota1;
vector<string> pokeku;

struct aho
{
    vector<vector<int> > g, gr;
    vector<string> str;
    int root;
    int sz;
    vector<ll> ending;
    vector<int> link;
    aho():
        g(pusto),
        gr(pusto),
        str(pokeku),
        root(0),
        sz(0),
        ending(pustota1),
        link(pustota) {}
    aho(vector<string> q)
    {
        sz = q.size();
        str = q;
        g.clear();
        gr.clear();
        ending.clear();
        link.clear();
        root = 0;
        g.push_back(vector<int>(26, -1));
        ending.assign(1, 0);
        for (int i = 0; i < q.size(); i++)
        {
            int v = root;
            for (int j = 0; j < q[i].size(); j++)
            {
                if (g[v][q[i][j] - 'a'] == -1)
                {
                    g[v][q[i][j] - 'a'] = g.size();
                    g.push_back(vector<int>(26, -1));
                    ending.push_back(0);
                }
                v = g[v][q[i][j] - 'a'];
            }
            ending[v]++;
        }
        link.assign(g.size(), -1);
        link[root] = root;
        queue<int> que;
        que.push(root);
        while (que.size())
        {
            int v = que.front();
            que.pop();
            for (int i = 0; i < 26; i++)
                if (g[v][i] == -1)
                {
                    if (v == root)
                        g[v][i] = v;
                    else
                        g[v][i] = g[link[v]][i];
                }
                else
                {
                    que.push(g[v][i]);
                    if (v == root)
                        link[g[v][i]] = v;
                    else
                        link[g[v][i]] = g[link[v]][i];
                }
        }
        gr.resize(g.size());
        for (int i = 0; i < g.size(); i++)
            if (i != root)
                gr[link[i]].push_back(i);
        dfslink(root);
    }
    void dfslink(int v)
    {
        for (int u : gr[v])
        {
            ending[u] += ending[v];
            dfslink(u);
        }
    }
    ll go(string s)
    {
        ll ans = 0;
        int v = root;
        for (int i = 0; i < s.size(); i++)
        {
            v = g[v][s[i] - 'a'];
            ans += ending[v];
        }
        return ans;
    }
};

const int LG = 20, T = 2;

aho a[T][LG];

int main()
{
 //   freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    int m;
    cin >> m;
    int asz = 0, bsz = 0;
    for (int i = 0; i < m; i++)
    {
        int t;
        string s;
        cin >> t >> s;
        if (t < 3)
        {
            t--;
            vector<string> newaho;
            newaho.push_back(s);
            int i = 0;
            while (a[t][i].sz > 0)
            {
                for (int j = 0; j < a[t][i].str.size(); j++)
                    newaho.push_back(a[t][i].str[j]);
                a[t][i] = aho();
                i++;
            }
            a[t][i] = aho(newaho);
        }
        else
        {
            ll ans = 0;
            for (int i = 0; i < T; i++)
            {
                ll curans = 0;
                for (int j = 0; j < LG; j++)
                    if (a[i][j].sz > 0)
                        curans += a[i][j].go(s);
                if (i)
                    ans -= curans;
                else
                    ans += curans;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}