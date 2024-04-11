#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn],n,k;
pii query()
{
  cout << "?";
  for(int i = 1; i <= k; i++)
  {
    cout << " " << a[i];
  }
  cout << endl;
  fflush(stdout);
  int x,y;
  cin >> x;
  if(x == -1) exit(0);
  cin >> y;
  return {x,y};
}
int main()
{
  cin >> n >> k;
  for(int i = 1; i <= k; i++) a[i] = i;
  pii pivot = query();
  a[pivot.first] = n;
  pii cmp = query();
  a[pivot.first] = pivot.first;
  bool greater;
  if(cmp.second > pivot.second) greater = 1;
  else greater = 0;
  int ans = 1;
  for(int i = 1; i <= k; i++)
  {
    if(i == pivot.first) continue;
    a[i] = n;
    pii res = query();
    a[i] = i;
    if(greater)
    {
      if(res.second != pivot.second) ans++;
    }
    else
    {
      if(res.second == pivot.second) ans++;
    }
  }
    cout << "! " << ans << endl;
    fflush(stdout);
  return 0;
}