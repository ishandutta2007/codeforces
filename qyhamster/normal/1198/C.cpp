#include <iostream>
#include <vector>
using namespace std;
const int maxn = 500005;
int u[maxn],v[maxn],a[maxn];
bool vis[maxn];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while(T--)
  {
    vector<int> ans;
    int n,m;
    cin >> n >> m;
    for(int i = 0; i <=  n * 3; i++) vis[i] = a[i] = 0;
    for(int i = 1; i <= m; i++)
    {
       cin >> u[i] >> v[i];
       if(a[u[i]] == 0 && a[v[i]] == 0)
       {
         a[u[i]] = v[i];
         a[v[i]] = u[i];
         ans.push_back(i);
       }
    }
    if(ans.size() >= n)
    {
      cout << "Matching" << endl;
      for(int i = 0; i < n; i++)
        cout << ans[i] << " ";
      cout << '\n';
    }
    else
    {
      cout << "IndSet" << endl;
      int cnt = n;
      for(int i = 1; i < n * 3; i++)
      {
        if(a[i]) continue;
        cout << i << " ";
        cnt--;
        if(cnt == 0) break;
      }
      cout << '\n';
    }
  }
  return 0;
}