#include <bits/stdc++.h>
using namespace std;
int main()
{
  int T;
  cin >> T;
  while(T--)
  {
    int a,b,c,r, ans = 0;
    cin >> a >> b >> c >> r;
    if(a > b) swap(a,b);
    if(b <= c-r) ans = b-a;
    else if(a >= c+r) ans = b-a;
    else
    {
      if(a < c-r) ans += c-r-a;
      if(b > c+r) ans += b-(c+r);
    }
    cout << ans << endl;
  }
  return 0;
}