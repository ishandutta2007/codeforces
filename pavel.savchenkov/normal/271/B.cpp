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
#define LL long long
#define uLL unsigned long long
#define mp make_pair
#define pii pair <int,int>
#define sz(A) ((int)(A).size())
#define y1 qwertyuiopasdfghjklzxcvbnm
#define y0 ehfoiuvhefroerferjhfjkehfjke

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MAXV = 2 * (int) 1e5 + 10;

bool pr[MAXV];
vector <int> p;
int n, m;

int str[600];
int stb[600];

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  memset(pr, true, sizeof pr);
  pr[1] = false;
  for (int i = 2; i < MAXV; i++)
    if  (pr[i]) {
      for (int j = 2 * i; j < MAXV; j += i)
        pr[j] = false;
      p.pb(i);
    }

  memset(str, 0, sizeof str);
  memset(stb, 0, sizeof stb);

  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      int a; 
      scanf("%d", &a);
      int v = *lower_bound(p.begin(), p.end(), a);
      str[i] += v - a;
      stb[j] += v - a;
    }

  int res = 2 * (int) 1e9;
  for (int i = 0; i < n; i++)
    res = min(res, str[i]);
  for (int j = 0; j < m; j++)
    res = min(res, stb[j]);

  printf("%d\n", res);
  return 0;
}