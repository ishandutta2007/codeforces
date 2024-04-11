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
#include <cmath>

using namespace std;

#define pb push_back
#define f first
#define s second
#define mp make_pair 
#define sz(A) ((int)(A).size())
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> pii;

const double EPS = 1e-9;
const int MAXN = 60;
const int MOD = 1000000007;
const int INF = (int) 1e9;

int mul (int a, int b) {
  ll M = 1ll * a * b;
  M %= 1ll * MOD;
  return (int) M;
}

int add (int a, int b) {
  a += b;
  if  (a >= MOD) a -= MOD;
  return a;
}

int mpow (int a, int p) {
  int res = 1;
  while (p > 0) {
    if  (p & 1) res = mul(res, a);
    a = mul(a, a); p /= 2;
  }
  return res;
}



int n, k;
int d[MAXN][MAXN][2];
int cnt[MAXN][MAXN][2];
bool inq[MAXN][MAXN][2];
int overA, overB;

int f[MAXN];
int invf[MAXN];

int C (int n, int k) {
  int ret = mul(f[n], invf[n - k]);
  return mul(ret, invf[k]);
}

queue < pair <pii, int> > q;

void push (int a, int b, int s) {
  if  (inq[a][b][s]) return;

  inq[a][b][s] = true;
  q.push(mp(mp(a, b), s));
}

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  f[0] = 1; invf[0] = 1;
  for (int i = 1; i < MAXN; i++) {
    f[i] = mul(f[i - 1], i);
    invf[i] = mpow(f[i], MOD - 2);
  }

  scanf("%d %d", &n, &k);
  
  overA = overB = 0;
  for (int i = 0; i < n; i++) {
    int w; scanf("%d", &w);
    if  (w == 50) overA++; else overB++;
  }

  for (int i = 0; i <= overA; i++)
    for (int j = 0; j <= overB; j++)
      for (int s = 0; s <= 1; s++)
        d[i][j][s] = INF, cnt[i][j][s] = 0;


  d[overA][overB][0] = 0;
  cnt[overA][overB][0] = 1;


  push(overA, overB, 0);
  while (!q.empty()) {
    int a = q.front().f.f;
    int b = q.front().f.s;
    int s = q.front().s;
    inq[a][b][s] = false;
    q.pop();

    for (int ca = 0; ca <= a && ca * 50 <= k; ca++)
      for (int cb = 0; cb <= b && ca * 50 + cb * 100 <= k; cb++) {
        if  (ca == 0 && cb == 0) continue;

        int A = overA - a + ca;
        int B = overB - b + cb;

        if  (d[A][B][1 - s] < d[a][b][s] + 1) continue;

        if  (d[A][B][1 - s] > d[a][b][s] + 1)
          cnt[A][B][1 - s] = 0;

        d[A][B][1 - s] = d[a][b][s] + 1;
        cnt[A][B][1 - s] = add(cnt[A][B][1 - s], mul(mul(C(a, ca), C(b, cb)), cnt[a][b][s]));
        push(A, B, 1 - s);
      }

  }

  if  (d[overA][overB][1] == INF) {
    printf("-1\n0\n");
    return 0;
  }

  printf("%d\n%d\n", d[overA][overB][1], cnt[overA][overB][1]);

  return 0;
}