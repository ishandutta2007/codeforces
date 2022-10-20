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
int a[maxn];
vector<int> c[maxn];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++)
  {
    int sq = sqrt(a[i]);
    for(int j = 2; j <= sq; j++)
    {
      if(a[i] % j) continue;
      int cnt = 0;
      while(a[i] % j == 0)
      {
        a[i] /= j;
        cnt++;
      }
      c[j].push_back(cnt);
    }
    if(a[i] > 1) c[a[i]].push_back(1);
  }
  long long ans = 1;
  for(int i = 2; i < maxn; i++)
  {
    if(c[i].size() < n-1) continue;
    sort(c[i].begin(),c[i].end());
    if(c[i].size() == n) for(int j = 0; j < c[i][1]; j++) ans *= i;
    else for(int j = 0; j < c[i][0]; j++) ans *= i;
  }
  cout << ans << endl;
  return 0;
}