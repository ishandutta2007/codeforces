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
#include <queue>

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

const double eps = 1e-9;
const int int_inf = 2000000000;
const i64 i64_inf = 1000000000000000000LL;
const double pi = acos(-1.0);
 
using namespace std;
int n;
int x[4000]; int y[4000];

bool t[4000][4000];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  memset(t,0,sizeof(t));
  cin >> n;
  forn(i,n)
    scanf("%d%d",&x[i],&y[i]), x[i]+=1000, y[i]+=1000, t[x[i]][y[i]] = 1;
  
  int res = 0;
  forn(i,n)
    foran(j,i+1,n)
    {
        int xx = ( x[i] + x[j] ) / 2;
        if ((x[i] + x[j]) % 2 == 1) continue;
        int yy = ( y[i] + y[j] ) / 2;
        if ((y[i] + y[j]) % 2 == 1) continue;
        res += t[xx][yy];
    }
    
  cout << res << endl;
  return 0;
}