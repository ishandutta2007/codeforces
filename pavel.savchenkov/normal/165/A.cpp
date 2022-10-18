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
vi x[3000];
vi y[3000];
int n;
int a[300]; int b[300];

int main() {
  cin >> n;
  forn(i, n)
  {
   scanf("%d%d",&a[i],&b[i]);
   a[i] += 1000; b[i] += 1000;
   x[a[i]].pb(b[i]);
   y[b[i]].pb(a[i]);
  }
  
  forn(i, 2012)
   sort(x[i].begin(), x[i].end()), sort(y[i].begin(),y[i].end());
   
  int res = 0;
  forn(i, n)
  {
   if (x[a[i]].empty() || y[b[i]].empty()) continue;
   if (x[a[i]][0] < b[i] && *x[a[i]].rbegin() > b[i] 
   && y[b[i]][0] < a[i] && *y[b[i]].rbegin() > a[i] ) res++;
  }
  
  cout << res << endl;
  return 0;
}