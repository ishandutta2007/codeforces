#ifdef LOCAL
#include <iostream>
#include <vector>
#include <queue>
#else
#include <bits/stdc++.h>
#endif
using namespace std;
const int maxn = 3e5 + 5;
#define pii pair<int,int>
int bit[maxn],bit2[maxn],a[maxn],res[maxn];
pair<pii,int> q[maxn];
vector<int> tim[maxn];
int sgn[maxn];
void add(int* arr, int x, int val)
{
  while(x < maxn)
  {
    arr[x] += val;
    x += (x&(-x));
  }
}
int query(int* arr, int x)
{
  int ans = 0;
  while(x)
  {
    ans += arr[x];
    x -= (x&(-x));
  }
  return ans;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n,Q;
  cin >> n >> Q;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 0; i < Q; i++)
  {
    cin >> q[i].first.first >> q[i].first.second;
    q[i].second = i;
  }
  for(int i = 1; i <= n; i++)
  {
    if(a[i] > i) continue;
    int need = i-a[i], rem = query(bit2,i);
    if(need <= rem)
    {
      add(bit,i,1);
    }
    else continue;
    int buffer = rem - need;
    int l = 1, r = i;
    while(l < r)
    {
      int m = (l+r)/2;
      if(query(bit2, m) <= buffer)
      {
        l = m+1;
      }
      else
      {
        r = m;
      }
    }
    tim[l].push_back(i);
    add(bit2,l,1);
  }
  /*for(int i = 1; i <= n; i++)
  {
    cout << i << ": ";
    for(auto k:tim[i]) cout << k << " "; cout << endl;
  }*/
  sort(q,q+Q);
  int cur = 0, sumr = 0;
  for(int i = 0; i < Q; i++)
  {
    int u = q[i].first.first, v = q[i].first.second;
    while(cur < u)
    {
      cur++;
      for(auto k:tim[cur])
      {
        add(bit,k,-1);
      }
    }
    res[q[i].second] = query(bit,n-v);
  }
  for(int i = 0; i < Q; i++) cout << res[i] << '\n';
  return 0;
}