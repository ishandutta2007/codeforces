#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <iomanip>
#include <random>
#include <stack>
using namespace std;
#define int long long
#define pii pair<long long, long long>
const double pi = acos(-1);
const int maxn = 1e6 + 10;
const int mod = 998244353;
int x[maxn],y[maxn];
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while(T--)
  {
    int n,k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
      cin >> x[i] >> y[i];
    }
    bool found = 0;
    for(int i = 0; i < n; i++)
    {
      bool ok = 1;
      for(int j = 0; j < n; j++)
      {
        if(abs(x[i]-x[j]) + abs(y[i]-y[j]) > k) ok = false;
      }
      if(ok)
      {
        found = 1;
        break;
      }
    }
    if(found) cout << 1 << endl;
    else cout << -1 << endl;
  }
  return 0;
}