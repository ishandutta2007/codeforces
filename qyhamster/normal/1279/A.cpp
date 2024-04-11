#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int a[3],T;
  cin >> T;
  while(T--)
  {
    cin >> a[0] >> a[1] >> a[2];
    sort(a,a+3);
    if(a[0] + a[1] + 1 >= a[2]) cout << "Yes" << '\n';
    else cout << "No" << '\n';
  }
  return 0;
}