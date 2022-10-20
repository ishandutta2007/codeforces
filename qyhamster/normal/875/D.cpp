#ifdef LOCAL
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <stack>
#else
#include <bits/stdc++.h>
#endif
#define pii pair<int,int>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn];
long long l[maxn],r[maxn];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n;
  cin >> n;
  long long ans = n*(n-1)/2;
  for(int i = 1; i <= n; i++) cin >> a[i];
  a[0] = a[n+1] = 2147483647;
  stack<pii> s;
  for(int i = 1; i <= n+1; i++)
  {
    while(!s.empty())
    {
      if((s.top().first & a[i]) != a[i] || s.top().first == a[i])
      {
        r[s.top().second] = i;
        s.pop();
      }
      else break;
    }
    s.push({a[i],i});
  }
  while(!s.empty()) s.pop();
  for(int i = n; i >= 0; i--)
  {
    while(!s.empty())
    {
      if((s.top().first & a[i]) != a[i])
      {
        l[s.top().second] = i;
        s.pop();
      }
      else break;
    }
    s.push({a[i],i});
  }
  for(int i = 1; i <= n; i++)
  {
    //cout << l[i] << " " << r[i] << endl;
    ans -= (i-l[i]-1) * (r[i]-i-1) + (r[i]-l[i]-2);
  }
  cout << ans << endl;
  return 0;
}