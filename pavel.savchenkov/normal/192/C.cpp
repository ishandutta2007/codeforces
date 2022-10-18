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
#define sqr(x) (x) * (x)

const double eps = 1e-9;
const int int_inf = 1 << 31 - 1;
const i64 i64_inf = 1ll << 63 - 1;
const double pi = acos(-1.0);

using namespace std;

int d[30][30];
int n;
char s[500100][20];
int len[500100];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  scanf("%d\n", &n);
  forn(i, n)
   gets(s[i]), len[i] = (int)strlen(s[i]);

   forn(j, 30)
    forn(k, 30)
     d[j][k] = -int_inf;

  int res = 0;

  forn(i, n)
  {
    int beg = s[i][0] - 'a';
    int end = s[i][len[i] - 1] - 'a';

    for (int first = 0; first < 'z' - 'a' + 1; first++)
    {
     d[first][end] = max(d[first][end], d[first][beg] + len[i]);
     if  (end == first) res = max(res, d[first][end]);
    }
    d[beg][end] = max(len[i], d[beg][end]);
    if  (beg == end) res = max(res, d[beg][end]);
//    cout << res << endl;
  }

  cout << res << "\n";
  return 0;
}