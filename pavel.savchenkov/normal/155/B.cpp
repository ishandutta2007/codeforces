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
bool was[1050];
pair <int,int> a[1050];
int n;

bool cmp(pair <int,int> a, pair <int,int> b)
{
 if (a.second != b.second) return a.second > b.second;
 return a.first > b.first; 
}

int main() {
  cin >> n;
  forn(i,n) cin >> a[i].first >> a[i].second;
  sort(a,a+n,cmp);
  int ans = 0; int can = 1;
  
  forn(i,n)
   if (can == 0) break; else
    { ans += a[i].first; can += a[i].second - 1; }
  
  cout << ans << endl;
  return 0;
}