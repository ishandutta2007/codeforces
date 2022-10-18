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
int a[40][40];
int str[40];
int stb[40];

int main() {
  // freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
  scanf("%d",&n);
  forn(i,n) forn(j,n) scanf("%d",&a[i][j]);
  memset(str,0,sizeof(str));
  memset(stb,0,sizeof(stb));
  forn(i,n)
	forn(j,n) { str[i] += a[i][j]; stb[j] += a[i][j]; }
	
  int res = 0;
  forn(i,n) forn(j,n) if (stb[j] > str[i]) res++;
  
  printf("%d",res);
  return 0;
}