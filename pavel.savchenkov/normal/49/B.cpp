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
int a, b;
int base;

int main() {
  scanf("%d%d", &a, &b);
  base = 0;
  int A = a; int B = b;
  while (A)
   base = max(base, A % 10), A /= 10;
  while (B)
   base = max(base, B % 10), B /= 10;
  base++;
  
  int c = 0; int res = 0;
  while (a || b)
  {
   int sum = a % 10 + b % 10 + c;
   a /= 10; b /= 10;
   c = sum / base, res++;
  }
  if  (c) res++;
  
  printf("%d",res);
  return 0;
}