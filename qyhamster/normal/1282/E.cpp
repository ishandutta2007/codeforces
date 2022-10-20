#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int maxn = 1e5 + 5;
vector<int> e[maxn];
vector<int> poly;
map<pii, vector<int> > mp;
bool vis[maxn];
int c[maxn],inv[maxn],nxt[maxn],prv[maxn];
struct triangle
{
  int t[3];
}a[maxn];
set<pii> s;
void add_edge(int x, int y,int id)
{
  if(x > y)swap(x,y);
  mp[make_pair(x,y)].push_back(id);
  if(s.count(make_pair(x,y))) s.erase(make_pair(x,y));
  else
  {
    s.insert(make_pair(x,y));
  }
}
void dfs(int x)
{
  poly.push_back(x);
  vis[x] = 1;
  for(auto k:e[x])
  {
    if(vis[k])continue;
    dfs(k);
  }
}
int get_mid(int x, int y, int z)
{
  if(prv[x] == y && nxt[x] == z) return x;
  if(prv[x] == z && nxt[x] == y) return x;
  swap(x,y);
  if(prv[x] == y && nxt[x] == z) return x;
  if(prv[x] == z && nxt[x] == y) return x;
  return z;
}
int main()
{
  int T;
  cin >> T;
  while(T--)
  {
    int n;
    cin >> n;
    for(int i = 0; i <= n; i++)e[i].clear();
    s.clear();
    poly.clear();
    mp.clear();
    memset(vis,0,sizeof(vis));
    memset(c,0,sizeof(c));
    for(int i = 0; i < n - 2; i++)
    {
      cin >> a[i].t[0] >> a[i].t[1] >> a[i].t[2];
      add_edge(a[i].t[0],a[i].t[1], i);
      add_edge(a[i].t[1],a[i].t[2], i);
      add_edge(a[i].t[2],a[i].t[0], i);
    }
    for(auto x:s)
    {
      e[x.first].push_back(x.second);
      e[x.second].push_back(x.first);
    }
    dfs(1);
    for(int i = 0; i < poly.size(); i++) cout << poly[i] << " "; cout << '\n';
    poly.push_back(poly[0]);
    queue<int> q;
    for(int i = 0; i < n; i++)
    {
      int x = poly[i], y = poly[i+1];
      if(x > y)swap(x,y);
      for(auto k:mp[{x,y}])
      {
        c[k]++;
        //cout << k << "???" << c[k] << endl;
        if(c[k] == 2) q.push(k);
      }
    }
    for(int i = 0; i < n; i++)
    {
      nxt[i] = i+1;
      prv[i] = i-1;
      inv[poly[i]] = i;
    }
    nxt[n-1] = 0;
    prv[0] = n-1;
    while(!q.empty())
    {
      cout << q.front() + 1 << ' ';
      int x = q.front();
      q.pop();
      int u = get_mid(inv[a[x].t[0]],inv[a[x].t[1]],inv[a[x].t[2]]);
      prv[nxt[u]] = prv[u];
      nxt[prv[u]] = nxt[u];
      //cout<< '\n' << prv[u] << " " << nxt[u] << "test " << u << endl;
      if(poly[prv[u]] > poly[nxt[u]])swap(prv[u],nxt[u]);
      for(auto k:mp[{poly[prv[u]],poly[nxt[u]]}])
      {
        c[k]++;
        //cout << u << " " << prv[u] << " " << k << "..." << c[k] << " " << nxt[u] << endl;
        if(c[k] == 2)q.push(k);
      }
    }
    cout << '\n';
  }
  return 0;
}