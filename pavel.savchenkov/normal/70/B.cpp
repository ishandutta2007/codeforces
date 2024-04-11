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

const double EPS = 1e-9;
const int INT_INF = 1 << 31 - 1;
const i64 I64_INF = 1ll << 63 - 1ll;
const double PI = acos(-1.0);

using namespace std;

int readSentence()
{
  char c = getchar();
  if  (c == '\n') return -1;
  int len = (c == ' ') ? 0 : 1;

  while (1)
  {
      c = getchar();
      len++;
      if  (c == '.' || c == '!' || c == '?') break;
  }

  return len;
}

int res, n;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  scanf("%d\n", &n);
  int cur = 0; int res = 0;

  while (1)
  {
     int len = readSentence();
     if  (len > n) { puts("Impossible"); return 0; }
     if  (len == -1) break;

     if  (!cur)
      if  (len <= n) cur = len + 1; else res++;
     else
      if  (cur + len + 1 <= n) cur += 1 + len;
       else if  (cur + len <= n) cur = 0, res++; else res++, cur = len + 1;
  }

  printf("%d\n", (cur == 0) ? res : res + 1);
  return 0;
}