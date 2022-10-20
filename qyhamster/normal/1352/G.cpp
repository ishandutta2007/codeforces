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
    int n;
    cin >> n;
    if(n < 4)
    {
      cout << -1 << endl;
      continue;
    }
    for(int i = 0; i < n/4-1; i++)
    {
      cout << i*4 + 2 << " " << i*4 + 4 << " " << i*4 + 1 << " " << i*4 + 3 << " ";
    }
    int base = (n/4-1)*4;
    if(n%4 == 0)
    {
      cout << base + 2 << " " << base + 4 << " " << base + 1 << " " << base + 3 << " ";
    }
    if(n%4 == 1)
    {
      cout << base + 2 << " " << base + 5 << " " << base + 3 << " " << base + 1 << " " << base + 4 << " ";
    }
    if(n%4 == 2)
    {
      cout << base + 2 << " " << base + 6 << " " << base + 3 << " " << base + 5 << " " << base + 1 << " " << base + 4 << " ";
    }
    if(n%4 == 3)
    {
      cout << base + 2 << " " << base + 4 << " " << base + 7 << " " << base + 5 << " " << base + 1 << " " << base + 3 << " " << base + 6 << " ";
    }
    cout << endl;
  }
  return 0;
}