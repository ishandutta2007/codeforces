#include <bits/stdc++.h>
#define pii pair<long long, int>
using namespace std;
const int maxn = 1e6 + 5;
int a[maxn];
long long s[maxn];
double ans[maxn];
pii cand[maxn];
int cnt = 0;
void pop(){cnt--;}
inline void push(pii x)
{
  cand[cnt++] = x;
}
inline pii top()
{
  return cand[cnt-1];
}
inline pii pretop()
{
  return cand[cnt-2];
}
int main()
{
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++)
  {
    scanf("%d", &a[i]);
    s[i] = s[i-1] + a[i];
  }
  push(make_pair(0,0));
  double mean = 0.0;
  for(int i = 1; i <= n; i++)
  {
    while(top().second != 0 && (double)(s[i] - top().first) / (i - top().second) < (double)(top().first - pretop().first) / (top().second - pretop().second)) pop();
    push(make_pair(s[i],i));
  }
  while(top().second != 0)
  {
    pii hold = top();
    pop();
    for(int i = hold.second; i > top().second; i--)
    {
      ans[i] = (double)(hold.first - top().first) / (hold.second - top().second);
    }
  }
  for(int i = 1; i <= n; i++)
    printf("%.10lf\n",ans[i]);
  return 0;
}