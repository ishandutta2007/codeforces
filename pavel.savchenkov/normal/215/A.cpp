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
#include <cstdlib>
#include <memory.h>
#include <queue>
#include <assert.h>

#define pb push_back
#define i64 long long
#define ui64 unsigned long long
#define mp make_pair
#define pii pair <int,int>
#define vi vector <int>
#define vii vector <pii>
#define f first
#define s second
#define foran(i,a,b) for (int i=a;i<(int)b;i++)
#define forn(i,n) for (int i=0;i<(int)n;i++)
#define ford(i,n) for (int i=(int)n-1;i>=0;i--)
#define sqr(x) (x) * (x)
#define y1 fucking_y1

const double EPS = 1e-9;
const int INT_INF = 0x7FFFFFFF;
const i64 I64_INF = 0x7FFFFFFFFFFFFFFF;
const double PI = acos(-1.0);

using namespace std;

int ma = -1; int c = 0;
int n, m;
int a[100];
int b[100];

int main() {
//  freopen("in.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> n;
  forn(i, n) cin >> a[i];
  cin >> m;
  forn(i, m) cin >> b[i];

  forn(i, n)
   forn(j, m)
   {
    if  (b[j] % a[i] != 0 || (b[j] / a[i]) < ma) continue;
                                    
    if  (b[j] / a[i] == ma) c++; else c = 1, ma = b[j] / a[i]; 
   }

  printf("%d\n",c);
  return 0;
}