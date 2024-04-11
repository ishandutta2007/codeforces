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
#define sqr(x) (x) * (x)

const double eps = 1e-9;
const int int_inf = 1 << 31 - 1;
const i64 i64_inf = 1ll << 63 - 1;
const double pi = acos(-1.0);
 
using namespace std;
int n;
int res = int_inf;
char s[2000];
char s1[2000];
char s2[2000];

int main() {
  scanf("%d\n", &n);
  if  (n == 1)
  {
   puts("0");
   return 0;
  }
  
  gets(s);
  for (int i = 0; s[i]; i++)
   s1[i] = s2[i] = s[i];
  
  int ans = 0;
  for (int i = 0; s[i + 1]; i++)
  {
   char need = (i & 1) ? '0' : '1';
   if  (s1[i] != need) { ans++; s1[i] = need; }
   need = '1' - need + '0';
   if  (s1[i + 1] != need) { ans++; s1[i + 1] = need; }
  }
  res = min(res, ans);
  
  ans = 0;
  for (int i = 0; s[i + 1]; i++)
  {
   char need = (i & 1) ? '1' : '0';
   if  (s2[i] != need) { ans++; s2[i] = need; }
   need = '1' - need + '0';
   if  (s2[i + 1] != need) { ans++; s2[i + 1] = need; }
  }
  
  printf("%d\n", min(res, ans));
  return 0;
}