#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for(int i = 0; i < n; i++)
  {
      cin >> a[i];
  }
  int ans = 0;
  for(int j = 0; j <= 30; j++)
  {
    int mx = 0;
    for(int i = 0; i < n; i++)
    {
      if(a[i] > j)
      {
        mx = 0;
        continue;
      }
      mx += a[i];
      if(mx < 0) mx = 0;
      ans = max(ans,mx-j);
    }
  }
  cout << ans << endl;
  return 0;
}