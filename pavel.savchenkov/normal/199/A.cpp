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
#include <assert.h>

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
#define sqr(x) (x) * (x)
#define y1 fucking_y1

const double eps = 1e-9;
const int int_inf = 1 << 31 - 1;
const i64 i64_inf = 1ll << 63 - 1;
const double pi = acos(-1.0);
const int N = 47;

using namespace std;

int f[100];
int n;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  f[0] = 0; f[1] = 1;
  for (int i = 2; i < N; i++)
   f[i] = f[i - 1] + f[i - 2];
  cin >> n;

  forn(i, N)
   forn(j, N)
    forn(z, N)
     if  (f[i] + f[j] + f[z] == n)
     {
         printf("%d %d %d\n", f[i], f[j], f[z]);
         return 0;
     }

  puts("I'm too stupid to solve this problem");
  return 0;
}