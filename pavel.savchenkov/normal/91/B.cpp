#include <cstdio>
#include <string>
#include <algorithm>
#include <memory.h>
#include <iostream>
#define forn(i,n) for (int i=0;i<(int)n;++i)
using namespace std;
pair <int,int> a[110000];
int res[110000];
int n;

int main() {
 scanf("%d",&n);
 forn(i,n) { scanf("%d",&a[i].first); a[i].second = i; }
 sort(a,a+n);
 int m = -1;
 forn(i,n)
 {
  if (m > a[i].second) res[a[i].second] = m - a[i].second - 1; else res[a[i].second] = -1;
  if (a[i].first != a[i+1].first) m = max(m,a[i].second);
 }
 
 forn(i,n) printf("%d ",res[i]);
 return 0;
}