#ifdef LOCAL
#include <iostream>
#include <vector>
#include <queue>
#else
#include <bits/stdc++.h>
#endif
using namespace std;
#define pii pair<int,int>
const int maxn = 2e5 + 5;
int a[maxn],c[maxn];
priority_queue<pii> pq;
vector<int> ans[maxn];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,k;
  cin >> n >> k;
  for(int i = 0; i <= max(n,k); i++) ans[i].clear();
  for(int i = 0; i < n; i++) cin >> a[i];
  sort(a,a+n);
  for(int i = 0; i < n/2; i++) swap(a[i],a[n-1-i]);
  for(int i = 1; i <= k; i++) cin >> c[i];
  while(!pq.empty()) pq.pop();
  int cnt = 0;
  for(int i = 0; i < n; i++)
  {
    if(pq.empty() || -pq.top().first == c[a[i]])
    {
      ans[cnt].push_back(a[i]);
      pq.push({-1,cnt++});
    }
    else
    {
      pii x = pq.top();
      pq.pop();
      x.first--;
      ans[x.second].push_back(a[i]);
      pq.push(x);
    }
  }
  cout << pq.size() << endl;
  for(int i = 0; i < pq.size(); i++)
  {
    cout << ans[i].size();
    for(auto k:ans[i]) cout << ' ' << k;
    cout << '\n';
  }
  return 0;
}