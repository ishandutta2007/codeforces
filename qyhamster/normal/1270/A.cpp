#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while(T--)
  {
    int n,u,v;
    cin >> n >> u >> v;
    bool ok = 0;
    for(int i = 0; i < u; i++)
    {
      int x;
      cin >> x;
      if(x == n) ok = 1;
    }
    for(int i = 0; i < v; i++)
    {
      int x;
      cin >> x;
    }
    if(ok) cout << "YES" << '\n';
    else cout << "NO" << '\n';
  }
  return 0;
}