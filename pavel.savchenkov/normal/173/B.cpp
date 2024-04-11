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

int d[1010][1010][4];
int n,m;
char a[1010][1010];
int dest[1010][1010][2];

struct ver
{
    int x,y,napr;
    ver(int _x=0,int _y=0,int _napr=0) { x=_x; y=_y; napr=_napr; }
};

void build()
{
    int now;
    forn(i,n)
    {
        now = -1;
        forn(j,m)
        {
            if (a[i][j] == '.') continue;
            d[i][j][0] = now;
            now = j;
        }
    }
        
    
    forn(i,n)
    {
        now = -1;
        ford(j,m)
        {
            if (a[i][j] == '.') continue;
            d[i][j][2] = now;
            now = j;
        }
    }
        
    forn(i,m)
    {
        now = -1;
        forn(j,n)
        {
            if (a[j][i] == '.') continue;
            d[j][i][3] = now;
            now = j;    
        }
    }
        
    
    forn(i,m)
    {
        now = -1;
        ford(j,n)
        {
            if (a[j][i] == '.') continue;
            d[j][i][1] = now;
            now = j;            
        }
    }
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  memset(d,-1,sizeof(d));
  cin >> n >> m; scanf("\n");
  forn(i,n) forn(j,m) forn(k,2) dest[i][j][k] = int_inf;
  forn(i,n) gets(a[i]);
//  forn(i,n) puts(a[i]);
  
  build();
  /*
  forn(i,n)
  {
    forn(j,m)
        cout << d[i][j][2] << " ";
    cout << endl;
  }
  */
  queue <ver> q;
  forn(i,m) if (a[n-1][i] == '#') q.push(ver(n-1,i,1)), dest[n-1][i][1] = 1;
  int ans = int_inf;
  
  while (!q.empty())
  {
    
    ver now = q.front(); q.pop();
    int i = now.x; int j = now.y; int napr = now.napr;
//  cout << i << " " << j << " " << napr << " res = " << dest[i][j] << endl;
    if (napr == 1)
    {
        if (d[i][j][0] != -1) 
            if (dest[i][d[i][j][0]][1] > dest[i][j][1]) dest[i][d[i][j][0]][1]=dest[i][j][1], q.push(ver(i,d[i][j][0],1));
        if (d[i][j][2] != -1)
            if (dest[i][d[i][j][2]][1] > dest[i][j][1]) dest[i][d[i][j][2]][1]=dest[i][j][1], q.push(ver(i,d[i][j][2],1));
        if (d[i][j][1] != -1)
            if (dest[d[i][j][1]][j][0] > dest[i][j][1]+1) dest[d[i][j][1]][j][0]=dest[i][j][1]+1, q.push(ver(d[i][j][1],j,0));
        if (d[i][j][3] != -1)
            if (dest[d[i][j][3]][j][0] > dest[i][j][1]+1) dest[d[i][j][3]][j][0]=dest[i][j][1]+1, q.push(ver(d[i][j][3],j,0));
    } else
    {
        if (d[i][j][0] != -1) 
            if (dest[i][d[i][j][0]][1] > dest[i][j][0]+1) dest[i][d[i][j][0]][1]=dest[i][j][0]+1, q.push(ver(i,d[i][j][0],1));
        if (d[i][j][2] != -1)
            if (dest[i][d[i][j][2]][1] > dest[i][j][0]+1) dest[i][d[i][j][2]][1]=dest[i][j][0]+1, q.push(ver(i,d[i][j][2],1));
        if (d[i][j][1] != -1)
            if (dest[d[i][j][1]][j][0] > dest[i][j][0]) dest[d[i][j][1]][j][0]=dest[i][j][0], q.push(ver(d[i][j][1],j,0));
        if (d[i][j][3] != -1)
            if (dest[d[i][j][3]][j][0] > dest[i][j][0]) dest[d[i][j][3]][j][0]=dest[i][j][0], q.push(ver(d[i][j][3],j,0));
    }
    
  }
  
  forn(i,m) if (a[0][i] == '#') ans = min(ans,min(dest[0][i][1],dest[0][i][0]));
 /* forn(i,n)
  {
    forn(j,m) if (dest[i][j]==int_inf) cout << "- "; else cout << dest[i][j] << " ";
    puts("");
  }*/
  if (ans == int_inf) puts("-1"); else cout << ans << endl;
  return 0;
}