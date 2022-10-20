#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <queue>
#define pii pair<long long,long long>
using namespace std;
const int maxn = 1e6 + 10;
const int maxr = 1e6 + 10;
const int MOD = 1000000007;
#define int long long
int a[maxn],b[maxn], c[maxn];
int mp[maxr];
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  for(int i = 1; i < maxr; i++)
  {
    mp[i] = i;
  }
  for(int j = 2; j < 1005; j++)
  {
    int d = j*j;
    for(int i = d; i < maxr; i += d)
    {
      while(mp[i] % d == 0) mp[i] /= d;
    }
  }
  int T;
  cin >> T;
  while(T--)
  {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
      cin >> a[i];
      a[i] = mp[a[i]];
      c[a[i]]++;
    }
    int mx = 0, mx2 = 0, sum = 0;
    for(int i = 0; i < n; i++)
    {
      mx = max(mx, c[a[i]]);
      if(c[a[i]] % 2)
      {
        if(a[i] == 1) sum += c[a[i]];
        mx2 = max(mx2, c[a[i]]);
        c[a[i]] = 0;
      }
      else
      {
        sum += c[a[i]];
        c[a[i]] = 0;
      }
    }
    mx2 = max(mx2, sum);
    int Q;
    cin >> Q;
    while(Q--)
    {
      int w;
      cin >> w;
      if(w == 0) cout << mx << '\n';
      else cout << mx2 << '\n';
    }
    for(int i = 0; i < n; i++) c[a[i]] = 0;
  }
}