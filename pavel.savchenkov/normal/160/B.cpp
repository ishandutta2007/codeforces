//#pragma comment (linker, "/STACK:200000000") 
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <utility>
#include <math.h>
#include <cstdlib>
#include <memory.h>
#define pb push_back
#define i64 long long
#define foran(i,a,b) for (int i=a;i<(int)b;i++)
#define forn(i,n) for (int i=0;i<(int)n;i++)
#define ford(i,n) for (int i=(int)n-1;i>=0;i--)
const double eps = 1e-9;
const int int_inf = 2000000000;
const i64 i64_inf = 1000000000000000000LL;
const double pi = acos(-1.0);
using namespace std;
int n; int k[2][20];

bool go(int to,int from)
{
    int c[2][20];
    forn(j,2) forn(i,11) c[j][i] = k[j][i];
    forn(i,11)
        forn(j,k[from][i])
        {
            foran(m,i+1,11)
                if (c[to][m] > 0) { c[to][m]--; c[from][i]--; break; }
        }
    
    forn(j,2) forn(i,11) if (c[j][i] != 0) return 0;
    return 1;
}

int main() {
  //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
  scanf("%d",&n); 
  forn(j,2) forn(i,11) k[j][i] = 0;
  
  
  forn(j,2)
   forn(i,n) { int c; scanf("%1d",&c); k[j][c]++; }
   
  if (go(1,0) || go(0,1)) cout << "YES"; else cout << "NO";
  
  return 0;
}