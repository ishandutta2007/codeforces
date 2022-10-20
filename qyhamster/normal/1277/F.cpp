#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
const int maxn = 4e5 + 5;
int d[maxn];
priority_queue<pii> pq;
vector<int> ans[maxn];
int a[maxn];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  long long mx = 0;
  for(int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  sort(a,a+n);
  int cnt = 1;
  a[n] = 2e9;
  for(int i = 0; i < n; i++)
  {
    if(a[i] == a[i+1]) cnt++;
    else
    {
      pq.push(make_pair(cnt,a[i]));
      cnt = 1;
    }
  }
  for(int i = 1; i <= n; i++)
  {
    for(long long j = (long long)i * i; j <= n; j += i)
    {
      d[j] = i;
    }
  }
  for(int i = n; i >= 0; i--)
  {
    if(pq.top().first <= d[i])
    {
      cout << i << '\n';
      cout << d[i] << " " << i/d[i] << '\n';
      for(int j = 0; j < d[i]; j++) ans[j].resize(i/d[i]);
      int x = 0, y = 0;
      while(!pq.empty())
      {
        int F = pq.top().first, S = pq.top().second;
        pq.pop();
        for(int j = 0; j < F; j++)
        {
          ans[x][y] = S;
          x++; y++;
          if(x >= d[i])
          {
            y -= d[i] - 1;
            if(y < 0) y += i/d[i];
            x -= d[i];
          }
          if(y >= i/d[i]) y -= i/d[i];
        }
      }
      for(int j = 0; j < d[i]; j++)
      {
        for(int k = 0; k < i/d[i]; k++)
        cout << ans[j][k] << " ";
        cout << '\n';
      }
      break;
    }
    pii x = pq.top();
    pq.pop();
    x.first--;
    if(x.first > 0) pq.push(x);
  }
  return 0;
}