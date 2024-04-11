#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn],d1[maxn],dn[maxn];
bool vis[maxn];
vector<int> e[maxn];
pii l[maxn],r[maxn];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m,k;
  cin >> n >> m >> k;
  for(int i = 0; i < k; i++) cin >> a[i];
  for(int i = 0; i < m; i++)
  {
    int u,v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  queue<int> q;
  q.push(1);
  vis[1] = 1;
  while(!q.empty())
  {
    int x = q.front();
    q.pop();
    for(auto k:e[x])
    {
      if(vis[k]) continue;
      q.push(k);
      d1[k] = d1[x] + 1;
      vis[k] = 1;
    }
  }
  memset(vis,0,sizeof(vis));
  q.push(n);
  vis[n] = 1;
  while(!q.empty())
  {
    int x = q.front();
    q.pop();
    for(auto k:e[x])
    {
      if(vis[k]) continue;
      q.push(k);
      dn[k] = dn[x] + 1;
      vis[k] = 1;
    }
  }
  for(int i = 0; i < k; i++)
  {
    l[i] = make_pair(d1[a[i]],a[i]);
    r[i] = make_pair(dn[a[i]],a[i]);
  }
  sort(l,l+k);
  sort(r,r+k);
  int lb = 0, rb = n * 2;
  while(lb < rb)
  {
    int mid = (lb + rb + 1) / 2;
    int check = 0, cur = k;
    pii mx[2]={{-maxn,-1},{-maxn,-1}};
    for(int i = 0; i < k; i++)
    {
      while(cur > 0 && l[i].first + r[cur-1].first >= mid)
      {
        cur--;
        pii target = {d1[r[cur].second], r[cur].second};
        if(target > mx[0])
        {
          mx[1] = mx[0];
          mx[0] = target;
        }
        else if(target > mx[1]) mx[1] = target;
      }
      if(l[i].second == mx[0].second)
      {
        if(dn[l[i].second] + mx[1].first >= mid)
        {
          check = 1;
          break;
        }
      }
      else
      {
        if(dn[l[i].second] + mx[0].first >= mid)
        {
          check = 1;
          break;
        }
      }
    }
    if(check) lb = mid;
    else rb = mid - 1;
  }
  cout << min(d1[n], lb + 1) << '\n';
  return 0;
}