#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <queue>
#define pii pair<long long,long long>
using namespace std;
const int maxn = 3e5 + 10;
const int maxr = 1e6 + 10;
const int MOD = 1000000007;
#define int long long
vector<int> e[maxn];
int a[maxn];
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while(T--)
  {
    int n,m;
    cin >> n >> m;
    for(int i = 0; i <= n; i++)
    {
      e[i].clear();
      a[i] = 0;
    }
    for(int i = 0; i < m; i++)
    {
      int u,v;
      cin >> u >> v;
      e[u].push_back(v);
      e[v].push_back(u);
    }
    vector<int> ans;
    set<int> avail;
    avail.insert(1);
    int cnt = 0;
    while(!avail.empty())
    {
      int x = *(avail.begin());
      avail.erase(avail.begin());
      if(a[x] == -1) continue;
      ans.push_back(x);
      a[x] = -1;
      cnt++;
      for(auto k:e[x])
      {
        if(a[k] != -1)
        {
            a[k] = -1;
            cnt++;
            for(auto l: e[k])
            {
              if(a[l] != -1) avail.insert(l);
            }
        }
      }
    }
 
    if(cnt == n)
    {
      cout << "YES" << '\n';
      cout << ans.size() << '\n';
      for(auto k: ans) cout << k << " ";
      cout << '\n';
    }
    else cout << "NO" << '\n';
  }
}