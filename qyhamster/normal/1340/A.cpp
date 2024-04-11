#ifdef LOCAL
#include <iostream>
#include <vector>
#include <queue>
#else
#include <bits/stdc++.h>
#endif
using namespace std;
const int maxn = 4e5 + 5;
int a[maxn];
bool vis[maxn];
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
      vis[i] = vis[i+1] = 0;
    }
    vis[0] = 1;
    int last = -1;
    bool ok = 1;
    for(int i = n-1; i >= 0; i--)
    {
      if(last == -1)
      {
        vis[a[i]] = 1;
        last = a[i];
        if(vis[last-1]) last = -1;
      }
      else
      {
        if(a[i] != last-1)
        {
          ok = 0;
          break;
        }
        last = a[i];
        if(vis[last-1]) last = -1;
      }
    }
    if(ok) cout << "Yes" << '\n';
    else cout << "No" << '\n';
  }
  return 0;
}