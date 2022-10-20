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
    string s;
    cin >> s;
    int n = s.length(), ans = 0;
    s = "#" + s;
    for(int i = 2; i <= n; i++)
    {
      if(s[i] == s[i-1] || s[i] == s[i-2])
      {
        ans++;
        s[i] = '@';
      }
    }
    cout << ans << endl;
  }
}