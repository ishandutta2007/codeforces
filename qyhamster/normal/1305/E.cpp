#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int INF = 5e8;
int a[maxn];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,k;
  cin >> n >> k;
  for(int i = 1; i <= n; i++) a[i] = i;
  int top = (n/2 - 1) * (n/2);
  if(n&1) top += n/2;
  if(k > top)
  {
    cout << -1 << endl;
    exit(0);
  }
  k = top - k;
  for(int i = n; i > 1; i--)
  {
    if(!k) break;
    while(k)
    {
      if(a[i] > a[i-1] + a[i-2])
      {
        a[i] = INF + i * n * 2;
        break;
      }
      else
      {
        a[i] += 2;
        k--;
        if(a[i] > a[i-1] + a[i-2])
        {
          a[i] = INF + i * n * 2;
          break;
        }
      }
    }
  }
  for(int i = 1; i <= n; i++) cout << a[i] << " "; cout << endl;
  return 0;
}