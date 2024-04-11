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
#define f first
#define s second
#define mp make_pair
#define pii pair <int,int>
#define sz(A) ((int)(A).size())
#define y1 qwertyuiopasdfghjklzxcvbnm
#define y0 ehfoiuvhefroerferjhfjkehfjke

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MAXN = (int) 1e5 + 10;
const LL INF = 10000000000000000LL;

using namespace std;

LL mul(int a, int b) {
  return 1LL * a * b;
}

LL d[MAXN];
int last[MAXN];
int timer = 0;
int n, q;

int v[MAXN];
int c[MAXN];

LL get_d(int C) {
  if  (last[C] == timer) return d[C];
  return -INF;
}

LL ans;

void put_d(int C, LL val) {
  if  (last[C] < timer)
    d[C] = val;
  else
    d[C] = max(d[C], val);
  last[C] = timer;
  ans = max(ans, d[C]);
}

void solve(int a, int b) {
  pair <LL, int> ma1 = make_pair(-INF, -1);
  pair <LL, int> ma2 = make_pair(-INF, -1);

  for (int i = 0; i < n; i++) {  
    if  (get_d(c[i]) != -INF)
      put_d(c[i], get_d(c[i]) + mul(v[i], a));

    put_d(c[i], mul(v[i], b));

    if  (ma1.f != -INF && ma1.s != c[i])
      put_d(c[i], ma1.f + mul(v[i], b));
    else if  (ma2.f != -INF && ma2.s != c[i])
      put_d(c[i], ma2.f + mul(v[i], b));

    if  (get_d(c[i]) > ma1.f && ma1.s != c[i]) {
      ma2 = ma1;
      ma1 = mp(get_d(c[i]), c[i]);
    } else if  (ma1.s == c[i]) {
      ma1.f = get_d(c[i]);
    } else if  (get_d(c[i]) > ma2.f)
      ma2 = mp(get_d(c[i]), c[i]);
  }      

}

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  for (int i = 0; i < n; i++)
    scanf("%d", &c[i]);

  memset(last, -1, sizeof last);
  
  for (int i = 0; i < q; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    ans = 0;
    solve(a, b);
    printf("%I64d\n", ans);
    timer++;
  }

  return 0;
}