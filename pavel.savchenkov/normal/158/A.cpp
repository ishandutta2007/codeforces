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
int a[100];

int main() {
  //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
  int n,k; int ans = 0;
  scanf("%d%d",&n,&k);
  forn(i,n) scanf("%d",&a[i]);
  forn(i,n) if (a[i]>=a[k-1] && a[i]>0) ans++;
  
  cout << ans << endl;
  return 0;
}