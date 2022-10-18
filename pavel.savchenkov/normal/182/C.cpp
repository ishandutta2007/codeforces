//HACK ME, PLEASE! ^_^
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <utility>
#include <math.h>
#include <cstdlib>
#include <memory.h>
#include <queue>
 
#define pb push_back
#define i64 long long
#define mp make_pair
#define pii pair <int,int>
#define vi vector <int>
#define vii vector <pii>
#define f first
#define s second
#define foran(i,a,b) for (int i=a;i<(int)b;i++)
#define forn(i,n) for (int i=0;i<(int)n;i++)
#define ford(i,n) for (int i=(int)n-1;i>=0;i--)
 
const double eps = 1e-9;
const int int_inf = 2000000000;
const i64 i64_inf = 1000000000000000000LL;
const double pi = acos(-1.0);
const int mod = 1000000007;
 
using namespace std;
int a[100500];
int n,len,k;
multiset <int> s;
multiset <int> all;
i64 sum = 0;
i64 sums = 0;
i64 res = -1000000000000000000ll;
 
bool add(int x)
{
 if (k == 0 || x >= 0) return 1;
 if ((int)s.size() < k) {
  s.insert(x); sums += x;
  return 1; 
 }
 if (x > *s.rbegin()) return 0;
 sums -= *s.rbegin();
 all.insert( *s.rbegin() );
 s.erase( s.find( *s.rbegin() ) );
 s.insert(x);
 sums += x;
 return 1;
}
 
void del(int x)
{
 if (x >= 0 || k == 0) return;
 if (s.find(x) == s.end()) { all.erase( all.find(x) ); return; }

 sums -= x;
 s.erase( s.find(x) );
 if (all.empty()) return;
 s.insert(*all.begin());
 sums += *all.begin();
 all.erase( all.find( *all.begin() ) );
}
 
void solve()
{
  sum = 0; sums = 0; s.clear(); all.clear();
  forn(i,len)
  {
   sum += (i64)a[i];
   if (!add(a[i])) all.insert(a[i]);
  }
  res = max(res, sum - sums - sums);
 
  foran(i,1,n-len+1)
  {
   sum -= a[i-1]; sum += a[i+len-1];
   del(a[i-1]);
   if (!add(a[i+len-1])) all.insert(a[i+len-1]);
   res = max(res, sum - sums - sums);
  }
}
 
int main() {
  cin >> n >> len;
  forn(i,n) scanf("%d",&a[i]);
  cin >> k;
  k = min(k, len);
  solve();
  forn(i,n) a[i] = -a[i];
  solve();
 
  cout << res << endl;
  return 0;
}