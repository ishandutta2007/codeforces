#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <utility>
#include <math.h>
#include <cstdlib>
#include <memory.h>

#define pb push_back
#define i64 long long
#define mp make_pair
#define pii pair <int,int>
#define vi vector <int>
#define vii vector <pii>
#define f first
#define s second
#define foran(i,a,b) for (int i=a;i<(int)b;i++)
#define forn(i,n) for (int i=0;i<(int)n;i++)
#define ford(i,n) for (int i=(int)n-1;i>=0;i--)
/*----------------------------------------------------------------------------------------------*/

const double eps = 1e-9;
const int int_inf = 2000000000;
const i64 i64_inf = 1000000000000000000LL;
const double pi = acos(-1.0);
const i64 mod = 1000000007;

using namespace std;
i64 g[4][4];
i64 k;

void mul(i64 a[4][4], i64 b[4][4]){
	i64 t[4][4];
	forn(i,4)
	forn(j,4)
	{ 
		t[i][j] = 0;
		forn(k,4) t[i][j] = (t[i][j] + a[i][k] * b[k][j]) % mod;
	}
	forn(i,4) forn(j,4) a[i][j] = t[i][j];
}

void powm(i64 a[4][4],int p){
    i64 r[4][4];
	forn(i,4) forn(j,4) r[i][j] = 0;
	forn(i,4) r[i][i] = 1;
	
	while(p > 0)
	{
		if (p&1) mul(r,a);
		mul(a,a);
		p>>=1;
	}
	forn(i,4) forn(j,4) a[i][j] = r[i][j];
}

int main() {
  // freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
  cin >> k;
  forn(i,4) forn(j,4) g[i][j]=1ll; forn(i,4) g[i][i] = 0;
  powm(g,k);
  
  
  cout << g[3][3] << endl;
  return 0;
}