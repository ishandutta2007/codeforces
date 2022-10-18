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
int n; int a[300500];
pii res[100500];
int sz = 0;
int N;
int t[300500];
int w[300500];

void build(int v,int tl,int tr)
{
    if (tl == tr) { t[v] = a[tl]; w[v] = tl; return; }
    int tm = (tl + tr) >> 1;
    build(v+v,tl,tm); build(v+v+1,tm+1,tr);
    t[v] = t[v+v]; w[v] = w[v+v];
    if (t[v] > t[v+v+1]) t[v] = t[v+v+1], w[v] = w[v+v+1];
}

pii get_min(int v,int l,int r,int tl,int tr)
{
    if (l == tl && r == tr) return mp(t[v],w[v]); 
    int tm = (tl + tr) >> 1;
    if (tm < l) return get_min(v+v+1,l,r,tm+1,tr); else
        if (tm >= r) return get_min(v+v,l,r,tl,tm);
    pii ans1 = get_min(v+v,l,tm,tl,tm);
    pii ans2 = get_min(v+v+1,tm+1,r,tm+1,tr);
    
    if (ans1.f < ans2.f) return ans1; else return ans2;
}

void go(int l,int r,int d)
{
    if (l > r) return;
    pii m = get_min(1,l,r,0,N-1);
    m.f -= d;
    for (int i=0; i<m.f; i++ ) res[sz] = mp(l+1,r+1), sz++;
    
    go(l,m.s-1,d+m.f);
    go(m.s+1,r,d+m.f);
}

int main() {
  cin >> n;
  memset(a,0,sizeof(a));
  forn(i,n) scanf("%d",&a[i]);
  for (int i=0;;i++)
    if (1 << i > n)
    {
        N = 1 << i;
        break;
    }

  build(1,0,N-1);
  go(0,n-1,0);
  
  cout << sz << endl;
  forn(i,sz)
    printf("%d %d\n",res[i].f,res[i].s);
  return 0;
}