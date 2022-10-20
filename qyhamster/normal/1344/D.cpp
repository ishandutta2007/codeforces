#ifdef LOCAL
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#else
#include <bits/stdc++.h>
#endif
#define pii pair<long long,long long>
using namespace std;
const int maxn = 2e5 + 5;
long long a[maxn],ans[maxn];
long long query(long long thres, long long C)
{
  if(C+thres-1 < 0) return 0;
  long long sq = sqrt((C+thres-1)/3);
  sq = min(sq,C);
  if(sq*(sq+1) <= (C+thres-1)/3 || sq == 0) return sq;
  return sq-1;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n,k;
  cin >> n >> k;
  for(int i = 0; i < n; i++) cin >> a[i];
  long long l = -4e18, r = 4e18;
  while(l < r)
  {
    long long mid = (l+r)/2;
    long long sum = 0;
    for(int i = 0; i < n; i++)
      sum += query(mid,a[i]);
    if(sum >= k) r = mid;
    else l = mid+1;
  }
  int sum = -k;
  priority_queue<pii> pq;
  for(int i = 0; i < n; i++)
  {
    ans[i] = query(l,a[i]);
    sum += ans[i];
    pq.push({3*ans[i]*ans[i]+3*ans[i]-a[i],i});
  }
  for(int i = 0; i < sum; i++)
  {
    ans[pq.top().second]--;
    pq.pop();
  }
  for(int i = 0; i < n; i++) cout << ans[i] << " ";
  cout << endl;
  return 0;
}