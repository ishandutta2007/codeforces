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
const int mod = (int)1e9 + 7;

using namespace std;

string s1, s2;
int n, k;

i64 A, dpA, B, dpB;

bool good(int id)
{
 for (int i = id; i < id + n; i++)
  if  (s1[i] != s2[i - id]) return 0;
 return 1;
}

int main() {
  getline(cin, s1);
  getline(cin, s2);
  cin >> k;
  n = (int)s1.length();
  s1 += s1;
  forn(i, n)
   if  (good(i)) A++; else B++;
  
  dpA = dpB = 0;
  if  (good(0)) dpA = 1; else dpB = 1;
  
  forn(i, k)
  {
   i64 old_dpA = dpA;
   dpA = (dpA * (A - 1) + dpB * A) % mod;
   dpB = (dpB * (B - 1) + old_dpA * B) % mod;
  }
  
  printf("%d\n", dpA);
  return 0;
}