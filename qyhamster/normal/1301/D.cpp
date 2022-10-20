#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn];
vector<pii> sol;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m,k;
  cin >> n >> m >> k;
  if (k > 4*n*m - 2*n - 2*m)
  {
    cout << "NO" << '\n';
    exit(0);
  }
  cout << "YES" << '\n';
  int step;
  for(int i = 1; i < m; i++)
  {
    step = min(k,n-1);
    sol.push_back({0,step});
    k -= step;
    if(!k) break;
    step = min(k,n-1);
    sol.push_back({2,step});
    k -= step;
    if(!k) break;
    k--;
    sol.push_back({1,1});
    if(!k) break;
  }
  if(k > 0)
  {
    step = min(k,n-1);
    sol.push_back({0,step});
    k -= step;
  }
  if(k > 0)
  {
    for(int i = 1; i < n; i++)
    {
      step = min(k,m-1);
      sol.push_back({3,step});
      k -= step;
      if(!k) break;
      step = min(k,m-1);
      sol.push_back({1,step});
      k -= step;
      if(!k) break;
      k--;
      sol.push_back({2,1});
      if(!k) break;
    }
  }
  if(k > 0)
  {
    sol.push_back({3,k});
  }
  int ignore = 0;
  for(int i = 0; i < sol.size(); i++)
  {
    if(sol[i].second == 0) ignore++;
  }
  cout << sol.size() - ignore << '\n';
  for(int i = 0; i < sol.size(); i++)
  {
    if(sol[i].second == 0) continue;
    cout << sol[i].second << ' ';
    if(sol[i].first == 0) cout << 'D';
    if(sol[i].first == 1) cout << 'R';
    if(sol[i].first == 2) cout << 'U';
    if(sol[i].first == 3) cout << 'L';
    cout << '\n';
  }
  return 0;
}