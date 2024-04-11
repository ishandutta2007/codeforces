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
const i64 i64_inf = 1ll << 63 - 1ll;
const double pi = acos(-1.0);

using namespace std;

vector <string> z[20];
pair <string, int> a[10];
int n, m;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  scanf("%d\n", &n);
  forn(i, n)
  {
      char c = getchar();
      string cur = "";
      while (c != ' ' && c != '\n')
      {
          cur += c;
          c = getchar();
      }
      a[i].f = cur;
      a[i].s = i;
  }

  scanf("%d\n", &m);
  forn(i, m)
  {
      int k; scanf("%d", &k);
      char c = getchar();
      forn(j, k)
      {
          c = getchar();
          string cur = "";
          while (c != ' ' && c != '\n')
          {
              cur += c; c = getchar();
          }
          z[i].pb(cur);
      }
  }

  /*
  forn(i, m)
  {
      forn(j, z[i].size())
       cout << z[i][j] << " ";
      puts("");
  }
  */
  sort(a, a + n);
  int maxp = -1;
  int id = -1;

  do
  {

      forn(i, m)
      {
          int j = 0;
          forn(ii, z[i].size())
           if  (z[i][ii] == a[j].f) j++;
          if  (j != n) continue;

          int x = 0;
          forn(ii, n)
           for (int jj = ii + 1; jj < n; jj++)
            x += (a[jj].s < a[ii].s);

          if  (n * (n - 1) / 2 - x + 1 > maxp || n * (n - 1) / 2 - x + 1 == maxp && i < id)
           {
               maxp = n * (n - 1) / 2 - x + 1;
               id = i;
           }

      }

  } while (next_permutation(a, a + n));

  if  (maxp == -1)
   puts("Brand new problem!");
    else
    {
        printf("%d\n", id + 1);
        printf("[:");
        forn(i, maxp)
         printf("|");
        printf(":]");
    }
  return 0;
}