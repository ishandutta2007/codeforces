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
long long a[maxn];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for(int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  if(n == 1)
  {
    cout << "1 1" << endl;
    cout << -a[0] << endl;
    cout << "1 1" << endl;
    cout << a[0] << endl;
    cout << "1 1" << endl;
    cout << -a[0] << endl;
    return 0;
  }
  cout << 1 << " " << n << endl;
  for(int i = 0; i < n; i++)
  {
    cout << -n * a[i] << " ";
  }
  cout << endl;
  cout << 1 << " " << n-1 << endl;
  for(int i = 0; i < n-1; i++)
  {
    cout << (n-1) * a[i] << " ";
  }
  cout << endl;
  cout << n << " " << n << endl;
  cout << (n-1) * a[n-1] << endl;
  return 0;
}