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
#define LL long long
#define uLL unsigned long long
#define mp make_pair
#define pii pair <int,int>
#define vi vector <int>
#define vii vector <pii>
#define f first
#define s second
#define foran(i,a,b) for (int i=a;i<(int)b;i++)
#define forn(i,n) for (int i=0;i<(int)n;i++)
#define ford(i,n) for (int i=(int)n-1;i>=0;i--)
#define sqr(x) ((x) * (x))
#define y1 fucking_y1

const double EPS = 1e-9;
const int INT_INF = 2 * (int)1e9;
const LL LL_INF = 8 * (LL)1e18;
const double PI = acos(-1.0);

using namespace std;

int n;
int l[100500];
int r[100500];

bool is_min[100500];
bool is_max[100500];

int mi = INT_INF;
int ma = 0;

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  cin >> n;
  forn(i, n) {
    scanf("%d%d", &l[i], &r[i]);
    ma = max(r[i], ma);
    mi = min(l[i], mi);
  }

  memset(is_min, 0, sizeof is_min);
  memset(is_max, 0, sizeof is_max);

  forn(i, n) {
    if  (mi == l[i]) is_min[i] = 1;
    if  (ma == r[i]) is_max[i] = 1;
  }

  forn(i, n)
    if  (is_min[i] && is_max[i]) {
        printf("%d\n", i + 1);
        return 0;
    }

  puts("-1");
  return 0;
}