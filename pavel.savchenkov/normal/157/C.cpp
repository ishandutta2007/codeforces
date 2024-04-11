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
string s;
string t;

int main() {
  // freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
  getline(cin,s);
  getline(cin,t);
  int ans = inf;
  s = string(2100,'*') + s + string(2100,'*');
  int n = (int)s.length();
  int m = (int)t.length();
  
  forn(i,n)
  {
    int res = 0;
    if (i + m > n) res = i + m - n;
    foran(j,i,min(n,i+m)) if (s[j] != t[j - i]) res++;
    ans = min(res,ans);
  }
  
  printf("%d",ans);
  return 0;
}