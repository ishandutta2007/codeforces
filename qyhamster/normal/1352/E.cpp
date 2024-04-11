#ifdef LOCAL
#include <iostream>
#include <vector>
#include <queue>
#else
#include <bits/stdc++.h>
#endif
#define pii pair<int,int>
using namespace std;
const int maxn = 1e5;
long long a[maxn],s[maxn];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while(T--)
  {
    int n, ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) s[i] = s[i-1] + a[i];
    for(int i = 1; i <= n; i++)
    {
      int cur = 0;
      for(int j = 0; j < n; j++)
      {
        while(cur <= n && s[cur] - s[j] < a[i]) cur++;
        if(cur == n+1) break;
        if(s[cur] - s[j] == a[i] && cur - j > 1)
        {
          ans++;
          break;
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}