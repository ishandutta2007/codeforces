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
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define foran(i, a, n) for (int i = int(a); i < int(n); i++)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> pii;

const double EPS = 1e-9;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

int id (char c) {
  if  (c == 'U')
    return 0;
  if  (c == 'D')
    return 1;
  if  (c == 'L')
    return 2;
  if  (c == 'R')
    return 3;

  assert(false);
  return 4;
}

int a, b;
char s[110];

bool check (ll sx, ll sy) {
  if  (ll(a) == sx && ll(b) == sy)
    return true;
            
  ll x = sx;
  ll y = sy;

  for (int i = 0; s[i]; i++) {
    x += 1ll * dx[id(s[i])];
    y += 1ll * dy[id(s[i])];

    if  (x == ll(a) && y == ll(b)) {
//      cout << sx << ' ' << sy << '\n';
      return true;
    } 
  }

  return false;
}

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  scanf("%d %d\n", &a, &b);
  gets(s);
     
  int Dx = 0;
  int Dy = 0;

  for (int i = 0; s[i]; i++) {
    Dx += dx[id(s[i])];
    Dy += dy[id(s[i])];
  }     

//  printf("Dx = %d Dy = %d\n", Dx, Dy);

  int cnt = 1000;
  if  (Dx != 0)
    cnt = abs(a) / abs(Dx);
  else if  (Dy != 0)
    cnt = abs(b) / abs(Dy);
        
  for (int C = max(0, cnt - 1000); C <= cnt + 1000; C++)
    if  (check(1ll * C * Dx, 1ll * C * Dy)) {
      puts("Yes");
      return 0;
    }

  puts("No");
  return 0;
}