#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
 
const int N = 3e5 + 10;
int n;
 
const int init = 9999999;
 
vector < int >st (2 * N, init);
 
int fun (int a, int b)
{
  return min (a, b);
}
 
void build ()
{
  for (int i = n - 1; i > 0; i--)
    st[i] = fun (st[i << 1], st[i << 1 | 1]);
}
 
void update (int id, int val)
{
  for (st[id += n] = val; id > 1; id >>= 1)
    st[id >> 1] = fun (st[id], st[id ^ 1]);
}
 
int query (int l, int r)
{
  int res = init;
 
  r++;
 
  for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
      if (l & 1)
	res = fun (res, st[l++]);
      if (r & 1)
	res = fun (res, st[--r]);
    }
 
  return res;
}
 
void solve ()
{
  cin >> n;
 
  map < int, queue < int >>mp;
 
  int a[n], b[n], c[n], d[n];
 
  f (i, n) cin >> a[i];
  f (i, n) cin >> b[i];
 
  f (i, n) mp[a[i]].push (i);
 
  f (i, n) st[i + n] = a[i];
 
  build ();
 
  f (i, n) c[i] = a[i], d[i] = b[i];
 
  sort (c, c + n);
  sort (d, d + n);
 
  f (i, n) if (c[i] != d[i])
    {
      cout << "NO\n";
      return;
    }
 
  f (i, n)
  {
    int l = 0, r = mp[b[i]].front ();
 
    mp[b[i]].pop ();
 
    if (query (l, r) != b[i])
      {
	cout << "NO\n";
	return;
      }
 
 
    update (r, init);
 
  }
    
  cout << "YES\n";
}
 
signed main ()
{
  fast;
  int t = 1;
  cin >> t;
  while (t--)
    solve ();
}