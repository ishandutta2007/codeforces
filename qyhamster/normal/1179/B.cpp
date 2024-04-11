#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  for(int i = 1; i <= n/2; i++)
  {
    for(int j = 1; j <= m; j++)
    {
      cout << i << " " << j << '\n';
      cout << n + 1 - i << " " << m + 1 - j << "\n";
    }
  }
  if(n&1)
  {
    for(int i = 1; i <= m/2; i++) {
      cout << (n+1)/2 << " " << i << '\n';
      cout << (n+1)/2 << " " << m + 1 - i << '\n';
    }
    if(m&1) cout << (n+1)/2 << " " << (m+1)/2 << '\n';
  }
  return 0;
}