#include <bits/stdc++.h>
#define pii pair<long long,long long>
using namespace std;
const int maxn = 2e5 + 5;
pii t[maxn];
long long easy = 0, hard = 0, a, b;
long long get_ans(long long x)
{
  if(x < 0) return -1e9;
  if(x/a < easy) return x/a;
  x -= a * easy;
  return easy + min(x / b, hard);
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int Testcase;
  cin >> Testcase;
  while(Testcase--)
  {
    easy = hard = 0;
    long long n,T;
    cin >> n >> T >> a >> b;
    for(int i = 0; i < n; i++)
    {
      cin >> t[i].second;
      if(t[i].second) hard++;
      else easy++;
    }
    for(int i = 0; i < n; i++) cin >> t[i].first;
    t[n].first = T+1;
    t[n].second = 0;
    n++;
    sort(t,t+n);
    long long ans = 0, times = 0;
    for(int i = 0; i < n; i++)
    {
      ans = max(ans, i + get_ans(t[i].first - 1 - times));
      if(t[i].second)
      {
        times += b;
        hard--;
      }
      else
      {
        times += a;
        easy--;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}