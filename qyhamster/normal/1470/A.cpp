#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <queue>
#define pii pair<long long,long long>
using namespace std;
const int maxn = 300000 + 10;
const int MOD = 1000000007;
#define int long long
int a[maxn],b[maxn];
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
    priority_queue<int> pq;
    for(int i = 0; i < n; i++)
    {
      cin >> a[i];
      pq.push(a[i]);
    }
    for(int i = 1; i <= m; i++) cin >> b[i];
    int cnt = 1, ans = 0;
    while(!pq.empty() && pq.top() >= cnt)
    {
      ans += b[cnt++];
      pq.pop();
    }
    while(!pq.empty())
    {
      ans += b[pq.top()];
      pq.pop();
    }
    cout << ans << endl;
  }
}