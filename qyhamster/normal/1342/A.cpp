#ifdef LOCAL
#include <iostream>
#include <vector>
#else
#include <bits/stdc++.h>
#endif
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while(T--)
  {
    long long x,y,a,b;
    cin >> x >> y >> a >> b;
    b = min(b,a*2);
    cout << min(x,y)*b + (max(x,y)-min(x,y))*a << endl;
  }
  return 0;
}