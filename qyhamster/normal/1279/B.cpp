#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
long long a[maxn];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while(T--)
  {
    long long n,s;
    cin >> n >> s;
    long long sum = 0;
    for(int i = 0; i < n; i++)
    {
      cin >> a[i];
      sum += a[i];
    }
    if(sum <= s)
    {
      cout << 0 << '\n';
      continue;
    }
    long long cand = 0, mx = 0;
    for(int i = 0; i < n; i++)
    {
      s -= a[i];
      if(a[i] > mx)
      {
        mx = a[i];
        cand = i+1;
      }
      if(s < 0)
      {
        cout << cand << '\n';
        break;
      }
    }
  }
  return 0;
}