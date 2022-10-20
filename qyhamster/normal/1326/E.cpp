#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
int a[maxn],p[maxn],inv[maxn],rmv[maxn],invp[maxn],u,v;
int seg[maxn*8],tag[maxn*8];
void pull(int id)
{
  seg[id] = min(seg[id*2],seg[id*2+1]) + tag[id];
}
void push(int id)
{
  tag[id*2] += tag[id];
  tag[id*2+1] += tag[id];
  tag[id] = 0;
  pull(id*2);
  pull(id*2+1);
  pull(id);
}
void add(int l,int r,int id,int val)
{
  if(u <= l && r <= v)
  {
    tag[id] += val;
    pull(id);
    return;
  }
  push(id);
  int mid = (l+r)/2;
  if(u <= mid) add(l,mid,id*2,val);
  if(v > mid) add(mid+1,r,id*2+1,val);
  pull(id);
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++)
  {
    cin >> a[i];
    inv[a[i]] = i;
  }
  for(int i = 0; i < n; i++)
  {
    cin >> p[i];
  }
  int ans = n;
  u = 1;
  v = inv[n];
  add(1,n,1,-1);
  for(int i = 0; i < n; i++)
  {
    while(seg[1] >= 0)
    {
      ans--;
      u = 1;
      v = inv[ans];
      add(1,n,1,-1);
    }
    cout << ans << " ";
    u = 1;
    v = p[i];
    add(1,n,1,1);
  }
  cout << '\n';
  return 0;
}