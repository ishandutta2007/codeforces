#ifdef LOCAL
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#else
#include <bits/stdc++.h>
#endif
using namespace std;
int check(int x)
{
  int res = x;
  while(x)
  {
    res += x % 10;
    x /= 10;
  }
  return res;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> ans;
  for(int i = n-1; i >= max(1,n-1000); i--)
  {
    if(check(i) == n) ans.push_back(i);
  }
  sort(ans.begin(),ans.end());
  cout << ans.size() << '\n';
  for(auto k:ans) cout << k << " ";
}