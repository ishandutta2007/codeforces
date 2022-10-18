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
struct p
{
    int x,y;
    p(int _x=0,int _y=0) { x=_x; y=_y; }
};
int len(p a,p b) { return (a.x - b.x) * (a.x-b.x) + (a.y-b.y) * (a.y-b.y); }
p c[3];

bool ok()
{
    if ( (c[1].x - c[0].x) * (c[2].y - c[0].y) -  (c[1].y - c[0].y) * (c[2].x - c[0].x) == 0) return 0;
    forn(i,3)
        if (len(c[i],c[(i+1)%3]) == len(c[(i+1)%3],c[(i+2)%3]) + len(c[(i+2)%3],c[i])) return 1;
    return 0;
}

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

string solve()
{
    if (ok()) return "RIGHT";
    forn(i,3)
     forn(j,4)
      {
        c[i].x += dx[j]; c[i].y += dy[j];
        if (ok()) return "ALMOST";
        c[i].x -= dx[j]; c[i].y -= dy[j];       
      }
    return "NEITHER";
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  forn(i,3) cin >> c[i].x >> c[i].y;
  
  cout << solve() << endl;
  return 0;
}