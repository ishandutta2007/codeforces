//HACK ME, PLEASE! ^_^
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
const i64 i64_inf = 1000000000000000000ll;
const double pi = acos(-1.0);

using namespace std;
int d[(1 << 22) + 100];
int full = (1 << 22) - 1;

int n;
int a[1000500];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  memset(d,-1,sizeof(d));
  cin >> n;
  forn(i, n)
    scanf("%d",&a[i]), d[full ^ a[i]] = a[i];
  
    
  ford(mask, full + 10) {
    if (d[mask] == -1) continue;
    forn(i, 23)
        if (mask & (1 << i)) d[mask - (1 << i)] = d[mask];
  }
    
  forn(i, n)
    printf("%d ",d[a[i]]);
  return 0;
}