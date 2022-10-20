#ifdef LOCAL
#include <iostream>
#include <vector>
#else
#include <bits/stdc++.h>
#endif
#define pii pair<int,int>
using namespace std;
const int maxn = 2e5 + 5;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while(T--)
  {
    int n,k;
    cin >> k >> n;
    n--;
    int x = n/(k-1);
    int ans = k*x+1;
    ans += n%(k-1);
    cout << ans << endl;
  }
  return 0;
}