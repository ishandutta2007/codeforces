#ifndef LOCAL
#include <bits/stdc++.h>
#else
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#endif
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while(T--)
  {
    int n;
    cin >> n;
    int sum = 0, mx = 0;
    for(int i = 0; i < n; i++)
    {
      cin >> a[i];
      sum += a[i];
      mx = max(mx,a[i]);
    }
    bool first = 0;
    if(mx > sum/2) first = 1;
    if(sum&1) first = 1;
    if(first) cout << "T" << endl;
    else cout << "HL" << endl;
  }
  return 0;
}