#ifdef LOCAL
#include <iostream>
#include <vector>
#else
#include <bits/stdc++.h>
#endif
using namespace std;
const int maxn = 4e5 + 5;
int a[maxn],l[maxn],r[maxn],t[maxn];
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
    for(int i = 0; i < k*2+3; i++) t[i] = l[i] = r[i] = 0;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n/2; i++)
    {
      t[a[i]+a[n-1-i]]--;
      if(a[i] > a[n-1-i]) swap(a[i],a[n-1-i]);
      r[a[n-1-i]+k+1]++;
      l[a[i]]++;
    }
    for(int i = 1; i <= k*2; i++) r[i] += r[i-1];
    for(int i = k*2-1; i >= 0; i--) l[i] += l[i+1];
    for(int i = 0; i <= k*2; i++) t[i] += l[i]+r[i];
    int mn = 2e9;
    for(int i = 0; i <= k*2; i++)
    {
      mn = min(mn, t[i]);
    }
    cout << mn + n/2 << endl;
  }
  return 0;
}