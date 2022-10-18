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
int n,m;
int a[100500];
int c[100500];
int d[100500];
bool k[100500];
int s = 0;

int main() {
 //  freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
  scanf("%d%d\n",&n,&m);
  memset(c,0,sizeof(c));
  memset(d,0,sizeof(d));
  memset(k,0,sizeof(k));
  
  for (int i=1; i<=n; i++)
  {
	char ch = getchar();
	int v; scanf("%d\n",&v);
    if (ch == '+') { c[v]++; a[i] = v; } else { d[v]++; a[i] = -v; s++; }
  }
  int z = 0;
  for (int i=1; i<=n; i++)
  {
	int tr = c[i] + s - d[i];
	//cout << i << " " << tr << endl;
	if (tr == m) { k[i] = 1; z++; } else k[i] = 0;
  }
  
  if (z == 1)
  {
	  
   for (int i=1;i<=n; i++)
   {
	 if (a[i] > 0)
		{ if (k[a[i]]) puts("Truth"); else puts("Lie"); }
	 else
		if (k[-a[i]]) puts("Lie"); else puts("Truth");
   }
   
  }
  
  else
  {
	  
   for (int i=1;i<=n;i++)
   { 
	 if (a[i] > 0)
         { if (k[a[i]]) puts("Not defined"); else puts("Lie"); }
	 else
		if (k[-a[i]]) puts("Not defined"); else puts("Truth");
   }
   
  }
  
  return 0;
}