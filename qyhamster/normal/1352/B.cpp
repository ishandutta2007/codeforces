#ifdef LOCAL
#include <iostream>
#include <vector>
#else
#include <bits/stdc++.h>
#endif
#define pii pair<int,int>
using namespace std;
const int maxn = 2e5 + 5;
 
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while(T--)
  {
    int n,k;
    cin >> n >> k;
    if(n%2 && k%2 == 0)
    {
      cout << "NO" << endl;
      continue;
    }
    if(n < k) 
    {
        cout << "NO" << endl;
        continue;
    }
    int base = 1;
    if(n%2 == 0 && k%2)
    {
      if(n < k*2)
      {
        cout << "NO" << endl;
        continue;
      }
      base = 2;
    }
    int x = n;
    cout << "YES" << endl;
    for(int i = 1; i < k; i++)
    {
      cout << base << " ";
      n -= base;
    }
    cout << n << endl;
  }
  return 0;
}