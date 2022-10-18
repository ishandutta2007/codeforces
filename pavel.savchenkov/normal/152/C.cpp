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
const i64 mod = 1000000007;
using namespace std;
int a[200][200];
int n,m;
int was[1000];

int main() {
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
   cin >> n >> m;
   scanf("\n");
   memset(was,0,sizeof(was));
   
   forn(i,n)
   {
	forn(j,m)
	  a[i][j] = getchar();// cout << (char)a[i][j]; }
	scanf("\n");
	//cout << endl;
   }
   i64 ans = 1;
   
   forn(j,m)
   {
	forn(i,n) was[a[i][j]] = j + 1;
	int k = 0;
	REP(i,'A','Z'+1) if (was[i] == j + 1) k++;
	ans = (ans * k) % mod;
   }
   
   cout << ans;
   return 0;
}