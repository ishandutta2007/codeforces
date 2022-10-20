#include <bits/stdc++.h>
using namespace std;
int main()
{
  int T;
  cin >> T;
  while(T--)
  {
    int n;
    cin >> n;
    if(n&1)
    {
      cout << 7;
      n -= 3;
    }
    n >>= 1;
    for(int i = 0; i < n; i++) cout << 1;
    cout << endl;
  }
  return 0;
}