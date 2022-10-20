#ifdef LOCAL
#include <iostream>
#include <vector>
#include <cmath>
#else
#include <bits/stdc++.h>
#endif
#define pii pair<int,int>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn], s[maxn];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while(T--)
  {
    int n,k;
    cin >> n >> k;
    bool has_k = 0;
    for(int i = 1; i <= n; i++)
    {
      cin >> a[i];
      if(a[i] == k) has_k = 1;
    }
    if(!has_k)
    {
      cout << "no" << '\n';
      continue;
    }
    if(n == 1)
    {
      if(a[1] == k) cout << "yes" << '\n';
      else cout << "no" << '\n';
      continue;
    }
    if(n == 2)
    {
      if(a[1] < k || a[2] < k) cout << "no" << '\n';
      else cout << "yes" << '\n';
      continue;
    }
    int yes = 0;
    for(int i = 2; i < n; i++)
    {
      int cnt = 0;
      if(a[i] >= k) cnt++;
      if(a[i-1] >= k) cnt++;
      if(a[i+1] >= k) cnt++;
      if(cnt > 1) yes = 1;
    }
    if(yes) cout << "yes" << '\n';
    else cout << "no" << '\n';
  }
  return 0;
}