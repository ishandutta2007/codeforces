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
#include <iomanip>

#ifdef ONPC
    #define deb(a) cerr << "       " << #a << " = " << a << endl;
#else
    #define deb(a)
#endif

using namespace std;

mt19937 rnd(time(0));

typedef long long ll;
typedef long double ld;

const int N = 100005;
const int D = 51;

vector<int> g[N], gr[N], ng[N];
int used[N];
int was[D][N];
int can[D][N];
int cnt[D][N];
vector<int> order, component;

string s[N];

vector<int> comp[N];
 
void dfs1(int v)
{
	used[v] = 1;
	for (int i = 0; i < g[v].size(); i++)
		if (!used[g[v][i]])
			dfs1(g[v][i]);
	order.push_back(v);
}
 
void dfs2(int v, int col)
{
	used[v] = col;
    comp[col].push_back(v);
	component.push_back(v);
	for (int i = 0; i < gr[v].size(); i++)
		if (!used[gr[v][i]])
			dfs2(gr[v][i], col);
}

vector<int> kek[N];
int root[N];
int gomus[N];
int arr[N];
int go[N];
int countr = 0;
int d;

vector<pair<int, int> > mas[D][N];
int memos[D][N];
void dfs3(int day, int v, int root, int rootday)
{
    //kek[v].push_back(day);
    if (v == root)
        kek[v].push_back(day);
    mas[rootday][root].push_back({day, v});
    was[day][v] = 1;
    if (s[v][day] == '1' && !gomus[v])
    {
        countr++;
        gomus[v] = 1;
    }
    day++;
    if (d == day)
        day = 0;
    for (int u : g[v])
        if (used[u] == used[v] && !was[day][u])
            dfs3(day, u, root, rootday);
}

void dfs4(int v, int dist)
{
    go[v] = (d - dist) % d;
    arr[v] = 1;
    dist++;
    if (dist == d)
        dist = 0;
    for (int u : g[v])
        if (used[u] == used[v] && !arr[u])
            dfs4(u, dist);
}

int dp[D][N];
int daddy[D][N];

int dfs5(int v, int day)
{
    day = daddy[day][v];
    if (memos[day][v])
        return dp[day][v];
    memos[day][v] = 1;
    int ans = 0;
    for (auto i : mas[day][v])
    {
        int newday = i.first;
        int u = i.second;
        //if (v == 2)
          //  cout << u + 1 << endl;
        for (int to : g[u])
        {
            if (used[to] == used[u])
                continue;
            int goday = newday + 1 + go[to];
            goday %= d;
            ans = max(ans, dfs5(root[used[to]], goday));
        }
    }
    //cout << v + 1 << ' ' << day + 1 << ' ' << ans + can[day][v] << endl;
    dp[day][v] = ans + can[day][v];
    return dp[day][v];
}



int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    int m;
    cin >> m >> d;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        gr[y].push_back(x);
    }
    for (int i = 0; i < n; i++)
        cin >> s[i];
	for (int i = 0; i < n; i++)
		if (!used[i])
			dfs1(i);
	for (int i = 0; i < n; i++)
        used[i] = 0;
    int color = 0;
	for (int i = 0; i < n; i++)
    {
		int v = order[n - 1 - i];
		if (!used[v])
        {
            color++;
			dfs2(v, color);
		}
    }
    for (int i = 1; i <= color; i++)
        sort(comp[i].begin(), comp[i].end());
    for (int i = 0; i < n; i++)
        if (!was[0][i])
        {
            root[used[i]] = i;
            dfs4(i, 0);
            for (int j = 0; j < d; j++)
                if (!was[j][i])
                {
                    for (int i : comp[used[i]])
                    {
                        gomus[i] = 0;
                       // kek[i].clear();
                    }
                    countr = 0;
                    kek[i].clear();
                    dfs3(j, i, i, j);
                    //cout << i + 1 << ' ' << j + 1 << ' ' << countr << endl;
                    for (int day : kek[i])
                    {
                        can[day][i] = countr;
                        daddy[day][i] = kek[i][0];
                    }
                    //for (int j : comp[used[i]])
                      //  for (int k : kek[j])
                        //    mas[kek[i][0]][i].push_back({j, k});
                }
        }
    cout << dfs5(0, 0) << '\n';
    return 1;
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