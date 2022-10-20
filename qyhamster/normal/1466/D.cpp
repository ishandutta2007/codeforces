#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <queue>
using namespace std;
const int maxn = 1000000;
#define int long long
int a[maxn], d[maxn];
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while(T--)
  {
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
      cin >> a[i];
      ans += a[i];
      d[i] = 0;
    }
    for(int i = 1; i < n; i++)
    {
      int u,v;
      cin >> u >> v;
      d[u]++;
      d[v]++;
    }
    priority_queue<int> pq;
    for(int i = 1; i <= n; i++)
    {
      for(int j = 1; j < d[i]; j++)
        pq.push(a[i]);
    }
    for(int i = 1; i < n; i++)
    {
      cout << ans << ' ';
      if(!pq.empty())
      {
        ans += pq.top();
        pq.pop();
      }
    }
    cout << '\n';
  }
}