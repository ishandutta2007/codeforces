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

int a[110][110];
int sstr[110];
int sstb[110];

bool str[110];
bool stb[110];

bool wasstr[110];
bool wasstb[110];

int n, m;

void go_str(int id)
{
   if  (wasstr[id]) wasstr[id] = 0; else wasstr[id] = 1;
   sstr[id] = -sstr[id];

   forn(i, m)
    if  (str[id] == stb[i])
     sstb[i] -= 2 * a[id][i];
    else
     sstb[i] += 2 * a[id][i];

    str[id] ^= 1;
}

void go_stb(int id)
{
   if  (wasstb[id]) wasstb[id] = 0; else wasstb[id] = 1;
   sstb[id] = -sstb[id];

   forn(i, n)
    if  (str[i] == stb[id])
     sstr[i] -= 2 * a[i][id];
    else
     sstr[i] += 2 * a[i][id];

    stb[id] ^= 1;
}

int iter = 0;

bool go()
{
   // iter++;
   // if  (iter > 10000) return 0;

    bool ok = 1;
    forn(i, n)
     if  (sstr[i] < 0) { go_str(i); ok = 0; }

    forn(j, m)
     if  (sstb[j] < 0) { go_stb(j); ok = 0; }

    return 1 - ok;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> n >> m;
  memset(str, 0, sizeof str);
  memset(stb, 0, sizeof stb);
  memset(wasstr, 0, sizeof wasstr);
  memset(wasstb, 0, sizeof wasstb);

  forn(i, n)
   forn(j, m)
    scanf("%d", &a[i][j]), sstr[i] += a[i][j], sstb[j] += a[i][j];

  while (go());

  int r = 0;
  forn(i, n)
   r += (wasstr[i]);

  printf("%d ", r);
  forn(i, n)
   if  (wasstr[i]) printf("%d ", i + 1); printf("\n");

  r = 0;
  forn(i, m)
   r += wasstb[i];

  printf("%d ", r);
  forn(i, m)
   if  (wasstb[i]) printf("%d ", i + 1); printf("\n");

  return 0;
}