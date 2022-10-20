#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;
int a[200005];
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
      cin >> a[i];
    int ans = 0;
    sort(a,a+n);
    reverse(a,a+n);
    unordered_set<int> s;
    for(int i = 0; i < n; i++)
    {
      int x = a[i];
      bool found = 0;
      while(x < 1e9)
      {
        if(s.count(x))
        {
          found = 1;
          break;
        }
        x <<= 1;
      }
      if(found)continue;
      x = a[i];
      while((x&1) == 0)
      {
        ans++;
        x >>= 1;
      }
      s.insert(a[i]);
    }
    cout << ans << '\n';
  }
  return 0;
}