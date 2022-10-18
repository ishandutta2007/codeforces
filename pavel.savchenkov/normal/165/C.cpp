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
int sum[1000100];
int k;
i64 res = 0;
int n;

int main() {
//  freopen("input.txt","r",stdin);
  cin >> k; scanf("\n");
  sum[0] = 0;
  char c;
  for (int i=0; scanf("%c",&c) == 1; i++, n = i)
   if (c == '0') sum[i + 1] = sum[i]; else if (c == '1') sum[i + 1] = sum[i] + 1;
  n--;
  
  forn(i, n)
  {
   if (n - i < k) continue;
   if (sum[n] - sum[i] < k || sum[i + 1] - sum[i] > k) continue;
   int l = i; int r = n;
   while (l != r - 1)
   {
       int m = (l + r) >> 1;
       if (sum[m + 1] - sum[i] < k) l = m; else r = m;
   }
   if (sum[l + 1] - sum[i] < k) l++; 
   int rs = l;
   l = rs; r = n;
   while (l != r - 1)
   {
    int m = (l + r) >> 1;
    if (sum[m + 1] - sum[i] <= k) l = m; else r = m;
   }
   res += l - rs + 1;
//   cout << i << " " << rs << " " << l << endl;
  }
  
  cout << res << endl;
  return 0;
}