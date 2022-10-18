//#pragma comment (linker, "/STACK:200000000") 
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <math.h>
#define pb push_back
#define i64 long long
#define foran(i,a,b) for (int i=a;i<(int)b;i++)
#define forn(i,n) for (int i=0;i<(int)n;i++)
#define ford(i,n) for (int i=(int)n-1;i>=0;i--)
const double eps = 1e-9;
const int inf = 2000000000;
const double pi = acos(-1.0);
using namespace std;
int n;
int a;
int rmin; int rmax;
int ans = 0;

int main() {
  cin >> n;
  forn(i,n) 
  {
   cin >> a;
   if (i == 0) { rmin = a; rmax = a; continue; }
   if (a < rmin) { ans++; rmin = a; }
   if (a > rmax) { ans++; rmax = a; }
  }

  cout << ans << endl;
  return 0;
}