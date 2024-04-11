#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <deque>
#include <unordered_map>
#include <iomanip>
#include <random>
#include <stack>
using namespace std;
#define int long long
#define pii pair<long long, long long>
const double pi = acos(-1);
const int maxn = 3e5 + 10;
const int mod = 998244353;
int x[maxn],y[maxn];
int a[maxn],cnt[maxn];
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while(T--)
  {
    int n;
    cin >> n;
    for(int i = 0; i <= n+5; i++) cnt[i] = a[i] = 0;
    for(int i = 1; i <= n; i++)
    {
      cin >> a[i];
      cnt[a[i]]++;
    }
    bool check = 1;
    for(int i = 1; i <= n; i++)
    {
      if(cnt[i] > (n+1)/2) check = 0;
    }
    if(!check)
    {
      cout << -1 << endl;
      continue;
    }
    int pen = 0;
    for(int i = 2; i <= n; i++)
    {
      if(a[i] == a[i-1]) pen++;
    }
    for(int i = 1; i <= n; i++)
    {
      if(cnt[i] >= 2) cnt[i] = cnt[i] * 2 - 2;
    }
    for(int i = 2; i <= n; i++)
    {
      if(a[i] != a[i-1])
      {
        cnt[a[i]]--;
        cnt[a[i-1]]--;
      }
    }
    for(int i = 1; i <= n; i++) pen = max(pen, cnt[i]);
    if(n == 1) pen = 0;
    cout << pen << endl;
  }
  return 0;
}