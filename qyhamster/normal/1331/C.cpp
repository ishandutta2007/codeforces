#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >> n;
  int ans = 0;
  if(n&1) ans += 16;
  if(n&16) ans += 1;
  if(n&2) ans += 2;
  if(n&4) ans += 8;
  if(n&8) ans += 4;
  if(n&32) ans += 32;
  cout << ans << endl;
  return 0;
}