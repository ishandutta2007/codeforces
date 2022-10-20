#ifdef LOCAL
#include <iostream>
#include <vector>
#else
#include <bits/stdc++.h>
#endif
#define pii pair<int,int>
using namespace std;
const int maxn = 2e5 + 5;
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
    for(int i = 0; i < n; i++) vis[i] = false;
    for(int i = 0; i < n; i++)
    {
      int x; cin >> x;
      int pos = i + x;
      pos %= n;
      if(pos < 0) pos += n;
      vis[pos] = 1;
    }
    bool ok = 1;
    for(int i = 0; i < n; i++)
    {
      if(!vis[i]) ok = 0;
    }
    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}