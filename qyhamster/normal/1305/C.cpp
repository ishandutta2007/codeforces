#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  for(int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  long long ans = 1;
  if(n > m)
  {
    cout << 0 << endl;
  }
  else
  {
    for(int i = 0; i < n; i++)
    for(int j = i+1; j < n; j++)
    {
      ans = ans * (abs(a[i] - a[j]) % m) % m;
    }
    cout << ans << endl;
  }
  return 0;
}