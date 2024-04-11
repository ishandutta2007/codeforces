#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
long long seg[maxn*8],mx[maxn*8],a[maxn],p[maxn];
int u,v;
void pull(int id)
{
  mx[id] = max(mx[id*2],mx[id*2+1]) + seg[id];
}
void push(int id)
{
  seg[id*2] += seg[id];
  seg[id*2+1] += seg[id];
  seg[id] = 0;
  pull(id*2);
  pull(id*2+1);
  pull(id);
}
void add(int l,int r,int val,int id)
{
  if(u <= l && r <= v)
  {
    seg[id] += val;
    pull(id);
    return;
  }
  push(id);
  int m = (l + r) / 2;
  if(u <= m) add(l,m,val,id*2);
  if(v > m) add(m+1,r,val,id*2+1);
  pull(id);
  return;
}
int main()
{
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> p[i];
  for(int i = 1; i <= n; i++) cin >> a[i];
  int cur = p[1];
  for(int i = 1; i <= n; i++)
  {
     u = p[i];
     v = n;
     add(0, n, -a[i], 1);
  }
  long long ans = min(a[1],a[n]), sum = 0;
  for(int i = 1; i < n; i++)
  {
    sum += a[i];
    u = p[i];
    v = n;
    add(0, n, a[i]*2, 1);
    ans = min(ans, sum - mx[1]);
  }
  cout << ans << '\n';
  return 0;
}