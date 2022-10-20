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
    for(int i = 0; i <= n; i++) a[i] = cnt[i] = 0;
    string ans = "";
    for(int i = 0; i < n; i++) ans.push_back('0');
    deque<int> dq;
    for(int i = 1; i <= n; i++)
    {
      cin >> a[i];
      cnt[a[i]]++;
      dq.push_back(a[i]);
    }
    int mx = 0;
    for(int i = 1; i <= n; i++)
    {
      if(cnt[i] == 0)
      {
        mx--;
        break;
      }
      if(cnt[i] != 1) break;
      if(dq.front() == i) dq.pop_front();
      else if (dq.back() == i) dq.pop_back();
      else break;
      mx = i;
    }
    mx = min(mx,n-1);
    for(int i = 1; i <= mx; i++) ans[n-1-i] = '1';
    if(cnt[1] >= 1)
    {
      ans[n-1] = '1';
    }
    else ans[n-1] = '0';
    bool check = 1;
    for(int i = 1; i <= n; i++)
    {
      if(cnt[i] != 1) check = false;
    }
    if(!check) ans[0] = '0';
    else ans[0] = '1';
    cout << ans << '\n';
  }
  return 0;
}