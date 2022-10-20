#ifdef LOCAL
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <map>
#else
#include <bits/stdc++.h>
#endif
#define pii pair<long long,long long>
using namespace std;
typedef unsigned long long uint64;
const int maxn = 3e5 + 5;
long long dis(pii x, pii y)
{
  return abs(x.first - y.first) + abs(x.second - y.second);
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long x,y,ax,ay,bx,by;
  cin >> x >> y >> ax >> ay >> bx >> by;
  vector<pii> point;
  point.push_back({x,y});
  while(x <= 3e16 && y <= 3e16)
  {
    x = x * ax + bx;
    y = y * ay + by;
    point.push_back({x,y});
  }
  int ans = 0;
  long long T;
  pii pos;
  cin >> pos.first >> pos.second >> T;
  for(int i = 0; i < point.size(); i++)
  {
    if(min(dis(pos,point[0]),dis(pos,point[i])) + dis(point[0],point[i]) <= T) ans = max(ans,i+1);
    for(int j = i; j >= 0; j--)
    {
      if(T - dis(point[i], pos) >= dis(point[i],point[j])) ans = max(ans, i-j+1);
    }
  }
  cout << ans << endl;
  return 0;
}