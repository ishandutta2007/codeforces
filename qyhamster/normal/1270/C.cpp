#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
long long a[maxn];
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
    long long x = 0, sum = 0;
    for(int i = 0; i < n; i++)
    {
      cin >> a[i];
      x = x ^ a[i];
      sum += a[i];
    }
    cout << 2 << '\n';
    sum += x;
    cout << x << " " << sum << '\n';
  }
  return 0;
}