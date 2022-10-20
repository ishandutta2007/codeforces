#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 200005;
bool res[maxn];
int a[maxn], rev[maxn];
int main()
{
  int T;
  cin >> T;
  while(T--)
  {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
      cin >> a[i];
      rev[a[i]] = i;
      res[i] = 0;
    }
    int l = rev[1], r = rev[1];
    res[1] = 1;
    for(int i = 2; i <= n; i++)
    {
      l = min(rev[i], l);
      r = max(rev[i], r);
      if(r - l + 1 == i) res[i] = 1;
      else res[i] = 0;
    }
    for(int i = 1; i <= n; i++)
    {
      cout << res[i];
    }
    cout << endl;
  }
  return 0;
}