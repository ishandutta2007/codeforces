#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 300010;
const int maxr = 1e6+5;
int mx[maxr*16],val[maxr*16],a[maxn],b[maxn],u,v;
void pull(int id)
{
  mx[id] = max(mx[id*2], mx[id*2+1]) + val[id];
}
void push(int id)
{
  val[id*2] += val[id];
  val[id*2+1] += val[id];
  val[id] = 0;
  pull(id*2);
  pull(id*2+1);
  pull(id);
}
void add(int l,int r, int id,int amount)
{
  if(u <= l && r <= v)
  {
    val[id] += amount;
    pull(id);
    return;
  }
  push(id);
  int m = (l+r) / 2;
  if(u <= m) add(l,m,id*2,amount);
  if(v > m) add(m+1,r,id*2+1,amount);
  pull(id);
}
int query()
{
  if(mx[1] <= 0) return -1;
  int id = 1, l = 0, r = maxr;
  while(l != r)
  {
    int m = (l+r)/2;
    push(id);
    if(mx[id*2+1] > 0)
    {
      l = m+1;
      id = id*2+1;
    }
    else
    {
      r = m;
      id = id*2;
    }
  }
  return l;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  for(int i = 0; i < n; i++)
  {
    cin >> a[i];
    u = 1; v = a[i];
    add(0,maxr,1,1);
  }
  for(int i = 0; i < m; i++)
  {
    cin >> b[i];
    u = 1; v = b[i];
    add(0,maxr,1,-1);
  }
  int Q;
  cin >> Q;
  while(Q--)
  {
    int cmd,id,x;
    cin >> cmd >> id >> x;
    id--;
    if(cmd == 1)
    {
      u = 1; v = a[id];
      add(0,maxr,1,-1);
      v = x;
      add(0,maxr,1,1);
      a[id] = x;
    }
    else
    {
      u = 1; v = b[id];
      add(0,maxr,1,1);
      v = x;
      add(0,maxr,1,-1);
      b[id] = x;
    }
    cout << query() << '\n';
  }
  return 0;
}