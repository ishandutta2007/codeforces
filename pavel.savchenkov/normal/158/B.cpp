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
int ans;
int k[5];
int n;

int main() {
  // freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
  scanf("%d",&n); memset(k,0,sizeof(k)); int a;
  forn(i,n)  { scanf("%d",&a); k[a]++; }
  ans = k[4];
  ans += k[2]/2;
  k[2] = k[2] % 2;
  
  int d = min(k[1],k[3]); ans += d; k[1] -= d; k[3] -= d;
  ans += k[3];
  
  if (k[2] == 1) 
  { 
	  if (k[1]>0) k[1]--;
      if (k[1]>0) k[1]--;
      ans += k[2];
      ans += (k[1]+3)/4;	  
  } else ans += (k[1]+3)/4;
  
  cout << ans << endl;
  return 0;
}