#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <queue>
using namespace std;
const int maxn = 1000000;
const int MOD = 1000000007;
#define int long long
int uni[maxn];
int tag[maxn];
int fnd(int x)
{
  return ((x==uni[x])?x:uni[x] = fnd(uni[x]));
}
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> ans;
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= m; i++)
  {
    uni[i] = i;
    tag[i] = 0;
  }
  for(int i = 1; i <= n; i++)
  {
    int d;
    cin >> d;
    if(d == 1)
    {
      int x;
      cin >> x;
      int head = fnd(x);
      if(tag[head] == 0)
      {
        tag[head] = 1;
        ans.push_back(i);
      }
    }
    if(d == 2)
    {
      int u,v;
      cin >> u >> v;
      int g = fnd(u), h = fnd(v);
      if(g != h)
      {
        if(tag[g] && tag[h]) continue;
        ans.push_back(i);
        uni[g] = h;
        tag[h] = (tag[g] || tag[h]);
      }
    }
  }
  int res = 1;
  for(int i = 0; i < ans.size(); i++) res = (res+res) % MOD;
  cout << res << " " << ans.size() << '\n';
  for(auto k:ans) cout << k << " ";
  cout << endl;
}