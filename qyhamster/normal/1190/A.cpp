#include <iostream>
#include <set>
using namespace std;
const int maxn = 100005;
long long a[maxn];
set<long long> s;
int main()
{
  long long n,m,k;
  cin >> n >> m >> k;
  for(int i = 0; i < m; i++)
  {
    cin >> a[i];
    s.insert(a[i]);
  }
  long long res = 1, ans = 0;
  while(!s.empty())
  {
    long long x = *s.begin();
    long long d = (x-res) / k, tmp = 0;
    while(!s.empty())
    {
      long long y = *s.begin();
      if(y >= k * d + res + k) break;
      s.erase(y);
      tmp++;
    }
    res += tmp;
    ans++;
  }
  cout << ans << endl;
  return 0;
}