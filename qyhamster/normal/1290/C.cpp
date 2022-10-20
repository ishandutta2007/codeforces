#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define int long long
using namespace std;
const int maxn = 6e5 + 5;
int a[maxn],num[maxn][2],fa[maxn],dif[maxn];
vector<pii> edge[maxn];
pii union_find(int x,int carry)
{
  if(fa[x] == x) return {x,carry};
  pii res = union_find(fa[x],carry ^ dif[x]);
  fa[x] = res.first;
  dif[x] = res.second ^ carry;
  return res;
}
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,k;
  string s;
  cin >> n >> k;
  cin >> s;
  s = "#" + s;
  for(int i = 1; i <= k; i++)
  {
    int t;
    cin >> t;
    for(int j = 0; j < t; j++)
    {
      int x;
      cin >> x;
      if(a[x] == 0) a[x] = i;
      else
      {
        edge[x].push_back({a[x],i});
        a[x] = 0;
      }
    }
  }
  for(int i = 1; i <= k; i++)
  {
    num[i][0] = 1;
    num[i][1] = 0;
    dif[i] = 0;
    fa[i] = i;
  }
  for(int i = maxn/2+1; i <= k+maxn/2; i++)
  {
    num[i][0] = maxn;
    num[i][1] = 0;
    dif[i] = 0;
    fa[i] = i;
  }
  for(int i = 1; i <= n; i++)
  {
    if(a[i])
    {
      edge[i].push_back({a[i],a[i]+maxn/2});
    }
  }
  long long ans = 0;
  for(int i = 1; i <= n; i++)
  {
    for(int j = 0; j < edge[i].size(); j++)
    {
      if(union_find(edge[i][j].first,0).first == union_find(edge[i][j].second,0).first) continue;
      pii p = union_find(edge[i][j].first,0), q = union_find(edge[i][j].second,0);
      int sign = (s[i] == '0');
      sign = sign ^ p.second ^ q.second;
      fa[p.first] = q.first;
      dif[p.first] = sign;
      ans -= min(num[p.first][0], num[p.first][1]);
      ans -= min(num[q.first][0], num[q.first][1]);
      num[q.first][0] += num[p.first][sign];
      num[q.first][1] += num[p.first][sign^1];
      num[p.first][0] = num[p.first][1] = 0;
      ans += min(num[q.first][0], num[q.first][1]);
      // cout << i << "...." << p.second << " " << q.second << " " << num[q.first][0] << " " << num[q.first][1] << '\n';
    }
    cout << ans << '\n';
  }
  return 0;
}