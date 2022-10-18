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
int n;
char s[2000];
int a[2000];

int main() {
  cin >> n; getchar();
  gets(s);
  a[0] = 1;
  for (int i=0; s[i]; i++)
   if (s[i] == 'R') a[i + 1] = a[i] + 1; else
    if (s[i] == '=') a[i + 1] = a[i]; else a[i + 1] = 1;
  
  for (int i=n-2; i>=0; i--)
   if (s[i] == 'L') a[i] = max(a[i], a[i + 1] + 1); else
    if (s[i] == '=') a[i] = a[i + 1];
  
  forn(i, n)
   cout << a[i] << " "; 
  return 0;
}