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
const int INT_INF = 0x7FFFFFFE;
const i64 I64_INF = 0x7FFFFFFFFFFFFFFELL;
const double PI = acos(-1.0);

using namespace std;

pii team[300500];
int a[300010];
bool was[300010];
int n, k;

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  cin >> n;
  forn(i, 3*n)
   scanf("%d", &a[i]), a[i]--;
  memset(was, 0, sizeof was);

  forn(i, n)
  {
   int a, b, c; scanf("%d%d%d", &a, &b, &c);
   a--; b--; c--;
   team[a] = mp(b, c);
   team[b] = mp(a, c);
   team[c] = mp(a, b);
  }

  cin >> k; --k;

  forn(i, 3*n)
   if  (a[i] == k)
   {

    if  (was[a[i]])
    {
     forn(j, 3*n)
      if  (j != k) printf("%d ", j + 1);
     return 0;
    }

    vi r; if  (team[k].f > team[k].s) swap(team[k].f, team[k].s);

    forn(j, 3*n)
     if  (was[j]) r.pb(j);
    sort(r.begin(), r.end());

    r.insert(r.begin(), team[k].s);
    int j = 0;
    while (j + 1 < (int)r.size() && r[j + 1] < r[j] && was[r[j + 1]]) { swap(r[j], r[j + 1]); j++; }

    r.insert(r.begin(), team[k].f);
    j = 0;
    while (j + 1 < (int)r.size() && r[j + 1] < r[j] && was[r[j + 1]]) { swap(r[j], r[j + 1]); j++; }

    was[team[k].f] = was[team[k].s] = was[k] = 1;


    vi rr;
    forn(j, 3*n)
     if  (!was[j]) rr.pb(j);
    sort(rr.begin(), rr.end());

    forn(j, rr.size()) r.pb(rr[j]);

    vi :: iterator it = r.begin();

    while (*it != team[k].s) it++;
    it++;
    sort(it, r.end());

    forn(j, r.size())
     printf("%d ", r[j] + 1);

    return 0;

   }
   else
   if  (!was[a[i]])
    was[team[a[i]].f] = was[team[a[i]].s] = was[a[i]] = 1;

  return 0;
}