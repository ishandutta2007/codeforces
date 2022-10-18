#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <complex>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>


using namespace std;

const int N = 300010;

map<pair<int, int>, int> q;
vector<int> quer;
int ans[N];

struct edge
{
    int u, v, l, r;
    edge():
        u(0),
        v(0),
        l(0),
        r(0) {}
    edge(int u, int v, int l, int r):
        u(u),
        v(v),
        l(l),
        r(r) {}
};

vector<pair<pair<int, int>, pair<int, int> > > qq;
vector<edge> edges;

void add(int u, int v, int l, int r)
{
    qq.push_back({{u, v}, {l, r}});
}

int pr[N], sz[N], ch[N], nech[N];
int pr1[N], sz1[N];

vector<int> st;

int curans;

int findset(int v)
{
 //   cout << v << endl;
    return ((v == pr[v]) ? v : findset(pr[v]));
}

int lvl(int v)
{
    return ((v == pr[v]) ? 0 : lvl(pr[v]) + 1);
}

int bad = 0;
int num1;

int unionsets(int a, int b)
{
    int v = findset(a);
    int u = findset(b);
    int x = lvl(a);
    int y = lvl(b);
    if (u == v)
    {
        if (x % 2 == y % 2)
            num1++;
        return 0;
    }
    if (sz[v] < sz[u])
        swap(v, u);
    st.push_back(u);
    if (x % 2 == y % 2)
    {
        sz[v] += sz[u];
        pr[u] = v;
        if (nech[v] == -1)
            nech[v] = u;
    }
    else
    {
        sz[v] += sz[u];
        pr[u] = nech[v];
    }
    return 1;
}

void remove()
{
    int u = st.back();
    st.pop_back();
    if (nech[pr[u]] == u)
        nech[pr[u]] = -1;
    sz[findset(u)] -= sz[u];
    pr[u] = u;
    curans++;
}

void divide(int l, int r, vector<edge> edges)
{
  //  cout << l << " " << r << " " << bad << endl;
    if (r < l)
        return;
    if (l == r)
    {
        if (bad)
            ans[l] = 0;
        else
            ans[l] = 1;
        return;
    }
    int mid = (r + l) / 2;
    vector<edge> edges1;
    int num = 0;
    num1 = 0;
    for (auto i : edges)
    {
        if (i.l > mid || i.r < l)
            continue;
        if (i.r >= mid && i.l <= l)
            num += unionsets(i.u, i.v);
        else
            edges1.push_back(i);
    }
    int keke = num1;
    bad += keke;
    divide(l, mid, edges1);
    bad -= keke;
    for (int i = 0; i < num; i++)
        remove();
    num = 0;
    num1 = 0;
    edges1.clear();
    for (auto i : edges)
    {
        if (i.l > r || i.r <= mid)
            continue;
        if (i.l <= mid + 1 && i.r >= r)
            num += unionsets(i.u, i.v);
        else
            edges1.push_back(i);
    }
    keke = num1;
    bad += keke;
    divide(mid + 1, r, edges1);
    bad -= keke;
    for (int i = 0; i < num; i++)
        remove();
}

int main()
{
  //  freopen("in.txt", "r", stdin);
//freopen("connect.in", "r", stdin); freopen("connect.out", "w", stdout);
    ios::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    k *= 2;
    for (int i = 0; i < k; i += 2)
    {
        //char c;
        //cin >> c;
        quer.push_back(i + 1);
        {
            int u, v;
            cin >> u >> v;
            if (u > v)
                swap(u, v);
            if (!q.count(make_pair(u, v)))
                q[make_pair(u, v)] = i;
            else
            {
                add(u, v, q[make_pair(u, v)], i);
                q.erase(make_pair(u, v));
            }
        }
    }
    if (n == 1)
    {
        for (int i = 0; i < quer.size(); i++)
            cout << "1\n";
        return 0;
    }
    for (auto it : q)
    {
        int u = it.first.first;
        int v = it.first.second;
        add(u, v, it.second, k);
    }
    add(1, 2, k + 1, k + 2);
    for (int i = 0; i < N; i++)
        pr[i] = i, sz[i] = 1, ch[i] = i, nech[i] = -1, pr1[i] = i, sz1[i] = 1;
    sort(qq.begin(), qq.end());
    for (auto i : qq)
        edges.push_back(edge(i.first.first, i.first.second, i.second.first, i.second.second));
   // for (auto i : edges)
     //   cout << i.u << " " << i.v << " " << i.l << " " << i.r << endl;
    curans = n;
    divide(0, k + 2, edges);
    int j = 0;
  /*  for (int i = 0; i < 10; i++)
        cout << ans[i] << " ";
    cout << endl << endl;*/
    for (int i = 0; i < quer.size(); i++)
    {
      //  while (ans[j] < quer[i])
        //    j++;
        cout << (ans[quer[i]] ? "YES" : "NO") << "\n";
    }
    return 0;
}