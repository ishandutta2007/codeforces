#ifdef LOCAL
#include <iostream>
#include <vector>
#else
#include <bits/stdc++.h>
#endif
using namespace std;
const int maxn = 3e5 + 5;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while(T--)
  {
    long long n;
    cin >> n;
    for(int i = 2; i < 30; i++)
    {
      if(n % ((1<<i)-1) == 0)
      {
        cout << n / ((1<<i)-1) << endl;
        break;
      }
    }
  }
  return 0;
}