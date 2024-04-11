#ifdef LOCAL
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#else
#include <bits/stdc++.h>
#endif
using namespace std;
const int maxn = 3e5 + 5;
int a[maxn];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  set<int> s;
  int ans = 1;
  for(int i = 0; i <= n; i++) s.insert(i);
  cout << 1;
  for(int i = 1; i <= n; i++)
  {
    int x;
    cin >> x;
    if(s.count(x))
    {
      ans++;
      s.erase(x);
    }
    else
    {
      s.insert(x);
      ans--;
    }
    cout << ' ' <<  ans - (n - (*prev(s.end())));
  }
  cout << endl;
}