#include <iostream>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
const int maxn = 200005;
pii p[maxn];
int t[maxn], in[maxn];
int bit[maxn];
void add(int x,int val)
{
  while(x < maxn)
  {
    bit[x] += val;
    x += (x&(-x));
  }
}
int query(int x)
{
  int ans = 0;
  while(x)
  {
    ans += bit[x];
    x -= (x&(-x));
  }
  return ans;
}
int main()
{
  long long n;
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> p[i].second >> p[i].first;
  sort(p,p+n);
  for(int i = 0; i < n; i++)
    t[i] = p[i].second;
  sort(t,t+n);
  for(int i = 0; i < n; i++)
  {
    p[i].second = lower_bound(t,t+n,p[i].second) - t + 1;
  }
  long long ans = 0;
  for(int i = 0; i < n; i++)
  {
    if(!in[p[i].second])
    {
      add(p[i].second,1);
    }
    in[p[i].second]++;
  }
  int lb = 0;
  for(int i = 0; i < n; i++)
  {
    long long l = query(p[i].second - 1) - query(lb) + 1, r = query(maxn - 2) - query(p[i].second) + 1;
    ans += l * r;
    in[p[i].second]--;
    if(in[p[i].second] == 0)add(p[i].second,-1);
    if(p[i].first == p[i+1].first)
    {
      lb = p[i].second;
    }
    else lb = 0;
  }
  cout << ans << endl;
  return 0;
}