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
const i64 mod = (int)1e9 + 7;

using namespace std;

int n;
int par[100500];
int len[100500];

int get_set(int v)
{
    if  (par[v] == v) return v;
    int ret = get_set(par[v]);
    len[v] = (len[v] + len[par[v]]) % mod;
    return par[v] = ret;
}

i64 ans = 0;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> n;
  forn(i, 100500)
   par[i] = i;


  forn(i, n)
  {
      int k;
      scanf("%d", &k);
      forn(j, k)
      {
       int v, x;
       scanf("%d%d", &v, &x);
       v--;
       int root = get_set(v);
       len[root] = (x + len[v]) % (int)mod;
       par[root] = i;
       i64 add = len[root] % mod;
       ans = (ans +  add + mod) % mod;
      }
  }

  forn(i, n)
   get_set(i);
  cout << ans << endl;

  return 0;
}