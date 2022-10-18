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

int d[110][110][30];
int k, n;
char s[110];

int c[30][30];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  memset(d, 0, sizeof d);
  memset(c, 0, sizeof c);
  scanf("%s %d%d\n", &s, &k, &n);
  forn(i, n) { char c1, c2; scanf("%c %c", &c1, &c2); scanf("%d\n", &c[c1 - 'a'][c2 - 'a']); }

  int length = (int)strlen(s);
  int res = -INT_INF;

  for (int len = 0; s[len]; len++)
   for (int was = 0; was <= min(len + 1, k); was++)
    for (char last = 'a'; last <= 'z'; last++)
      d[len][was][last - 'a'] = -INT_INF;

  for (int len = 0; s[len]; len++)
   for (int was = 0; was <= min(len + 1, k); was++)
    for (char last = 'a'; last <= 'z'; last++)
     for (char next = 'a'; next <= 'z'; next++)
     {
         if  (len == 0)
             if  (was == 1 && s[0] != last || was == 0 && s[0] == last) d[len][was][last - 'a'] = 0;

         if  (d[len][was][last - 'a'] == -INT_INF) continue;

         if  (len == length - 1) res = max(res, d[len][was][last - 'a']);
         int nwas = (next == s[len + 1]) ? was : was + 1;
         d[len + 1][nwas][next - 'a'] = max(d[len + 1][nwas][next - 'a'], d[len][was][last - 'a'] + c[last - 'a'][next - 'a']);
     }

  printf("%d\n", res);
  return 0;
}