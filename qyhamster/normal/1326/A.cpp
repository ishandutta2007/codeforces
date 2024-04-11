#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for(int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    if(x == 1)
    {
      cout << -1 << endl;
      continue;
    }
    cout << 2;
    for(int i = 1; i < x; i++) cout << 3;
    cout << '\n';
  }
  return 0;
}