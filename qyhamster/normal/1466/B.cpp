#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
const int maxn = 1000000;
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
    a[0] = -1;
    for(int i = 1; i <= n; i++)
    {
      cin >> a[i];
    }
    sort(a+1,a+n+1);
    int ans = 0, potential = 0;
    for(int i = 1; i <= n; i++)
    {
      if(a[i] != a[i-1]) ans++;
      if(a[i] == a[i-1]) potential = 1;
      if(a[i] > a[i-1] + 1)
      {
        ans += potential;
        potential = 0;
      }
    }
    ans += potential;
    cout << ans << endl;
  }
}