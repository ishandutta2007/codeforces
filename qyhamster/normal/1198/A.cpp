#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 400005;
int a[maxn],s[maxn];
int s_(int x)
{
  if(x < 0)return 0;
  return s[x];
}
int main()
{
  int n,k;
  cin >> n >> k;
  k = k * 8 / n;
  k = min(k, 30);
  int threshold = (1<<k);
  for(int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  sort(a,a+n);
  int r = 0, diff = 1, mx = 0;
  for(int i = 0; i < n; i++)
  {
    while(r < n && diff <= threshold)
    {
      r++;
      if(a[r] != a[r-1]) diff++;
    }
    mx = max(mx, r-i);
    if(a[i] != a[i+1]) diff--;
  }
  cout << n-mx << endl;
  return 0;
}