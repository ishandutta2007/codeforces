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
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pii pair <int,int>
#define sz(A) ((int)(A).size())
#define y1 qwertyuiopasdfghjklzxcvbnm
#define y0 ehfoiuvhefroerferjhfjkehfjke

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int INF = 2 * (int) 1e9 + 10;

string a[7] = { "Anka", "Chapay", "Cleo", "Troll", "Dracul", "Snowy", "Hexadecimal" };

int n;
int c[3];

bool g[10][10];

int d = INF;
int s = 0;

vector <int> v[3];

void upd(int D, int S) {
  if  (D < d) {
    d = D;
    s = S;
  }

  if  (D != d) return;

  if  (S <= s) return;

  d = D;
  s = S;
}

void go(int j) {
  
  if  (j == 7) {

    for (int i = 0; i < 3; i++)
      if  (v[i].empty()) return;

    int ma = -1; int mi = INF;
    for (int i = 0; i < 3; i++) {
      ma = max(c[i] / sz(v[i]), ma);
      mi = min(c[i] / sz(v[i]), mi);
    }
    int D = ma - mi;

    int S = 0;
    for (int i = 0; i < 3; i++)
      for (int ii = 0; ii < sz(v[i]); ii++)
        for (int jj = 0; jj < sz(v[i]); jj++)
          if  (g[v[i][ii]][v[i][jj]]) S++;

    upd(D, S);
    return;
  }

  for (int i = 0; i < 3; i++) {
    v[i].pb(j);
    go(j + 1);
    v[i].pop_back();
  }
}

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  scanf("%d\n", &n);

  memset(g, false, sizeof g);
  sort(a, a + 7);

  for (int i = 0; i < n; i++) {
    string p, q, tmp;
    cin >> p; cin >> tmp; cin >> q; scanf("\n");
    
    int P = lower_bound(a, a + 7, p) - a;
    int Q = lower_bound(a, a + 7, q) - a;
    
    g[P][Q] = true;
  }
              
  scanf("%d %d %d\n", &c[0], &c[1], &c[2]);
              
  go(0);      

  printf("%d %d\n", d, s);
  return 0;
}