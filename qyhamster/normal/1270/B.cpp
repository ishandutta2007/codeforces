#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn];
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
    for(int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    bool found = 0;
    for(int i = 1; i < n; i++)
    {
      if(abs(a[i] - a[i-1]) > 1)
      {
        found = 1;
        cout << "YES" << '\n';
        cout << i << " " << i+1 << '\n';
        break;
      }
    }
    if(!found) cout << "NO" << '\n';
  }
  return 0;
}