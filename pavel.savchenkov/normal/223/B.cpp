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
const int INT_INF = 1 << 31 - 1;
const i64 I64_INF = 1ll << 63 - 1ll;
const double PI = acos(-1.0);

using namespace std;

vi ids[30];
vi f[30];

char s[200500];
char t[200500];
int n, m;
int to[200500];

void put(char c, int l, int r)
{
//    printf("%c %d %d\n", c, l, r);
    c -= 'a';
    int id1 = lower_bound(ids[c].begin(), ids[c].end(), l) - ids[c].begin();
    int id2 = upper_bound(ids[c].begin(), ids[c].end(), r) - ids[c].begin();
    if  (id1 == (int)ids[c].size() || id2 == 0) return;
    id2--;
    f[c][id1] = max(id2, f[c][id1]);
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  gets(s); n = (int)strlen(s);
  gets(t); m = (int)strlen(t);
  s[n] = 'z' + 1; n++; s[n] = '\n';
  t[m] = 'z' + 1; m++; t[m] = '\n';
  forn(i, n)
   ids[s[i] - 'a'].pb(i), f[s[i] - 'a'].pb(-1);

  int j = 0;
  for (int i = 0; i < n && j < m; i++)
   if  (s[i] == t[j]) to[j] = i, j++;

//  forn(i, m)
//   cout << to[i] << ' ';
  if  (j != m) { puts("No"); return 0; }

  int previd = n;
  for (int i = m - 1; i > 0; i--)
  {
 //     printf("previd = %d\n", previd);
      int id =
       lower_bound(ids[ t[i] - 'a' ].begin(), ids[ t[i] - 'a' ].end(), previd)
        - ids[ t[i] - 'a' ].begin();

 //     printf("id = %d\n", id);
      if  (!id) { puts("No"); return 0; }
      previd = ids[ t[i] - 'a' ][id - 1];
      put(t[i - 1], to[i - 1], ids[ t[i] - 'a' ][id - 1] - 1);
  }
  if  (m > 1) put(t[m - 1], to[m - 2], n - 1);

  bool ok = 1;
  for (int c = 0; c <= 'z' - 'a'; c++)
  {
     int r = -1;
     forn(i, f[c].size())
     {
         r = max(r, f[c][i]);
         if  (i > r) ok = 0;
     }
  }

  puts(ok ? "Yes" : "No");
  return 0;
}