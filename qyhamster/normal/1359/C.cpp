#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while(T--)
  {
    long double h,c,t;
    cin >> h >> c >> t;
    h -= c;
    t -= c;
    long double mid = h/2;
    if(h <= 1e-13) cout << 1 << endl;
    else if(t <= mid+1e-13) cout << 2 << endl;
    else
    {
      long long k = ceil(h / (t-mid)/4 - 0.5 + 1e-13);
      long double mn = 1e10;
      long long cand = 0;
      for(int i = max(0LL,k-10); i <= k+10; i++)
      {
        long double res = abs((long double)(i+1)/(long double)(i*2+1)*h - t);
        if(res < mn-1e-13)
        {
          mn = res;
          cand = i*2+1;
        }
      }
      cout << cand << endl;
    }
  }
  return 0;
}