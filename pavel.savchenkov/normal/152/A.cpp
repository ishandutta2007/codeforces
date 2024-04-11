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
#define REP(i,a,b) for (int (i)=(a);(i)<(b);i++)
#define forn(i,b) for (int (i)=0;i<(b);i++)
const double eps = 1e-9;
const int inf = 2000000000;
const double pi = acos(-1.0);
using namespace std;

int main() {
  // freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   int n,m;
   cin >> n >> m;
   int a[n][m];
   scanf("\n");
   forn(i,n)
   {
	forn(j,m) a[i][j] = getchar();
	scanf("\n");
   }
   
   bool w[n];
   memset(w,false,sizeof(w));
   
   forn(j,m)
   {
	int m = -1;
	forn(i,n) if (a[i][j] > m) m = a[i][j];
	forn(i,n) if (a[i][j] == m) w[i] = true;
   }
   
   int res = 0;
   forn(i,n) if (w[i]) res++;
   cout << res << endl;
   return 0;
}