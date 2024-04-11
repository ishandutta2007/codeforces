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

int dx[4] = { 1, 0, -1,  0 };
int dy[4] = { 0, 1,  0, -1 };

int X, Y;
int len = 0, prevlen = 0, dir = 0;

void get_next(int x, int y, int & nx, int & ny) {
  int l = len == prevlen ? len + 1 : len;

  nx = x + l * dx[dir];
  ny = y + l * dy[dir];

  dir = (dir + 1) % 4;
  prevlen = len;
  len = l;
}

int solve() {
  int x = 0, y = 0, cnt = 0;

  while (1) {
//    printf("in %d %d\n", x, y);
    
    if  (X == x && Y == y)
      return cnt;

    if  (x != 0 || y != 0) cnt++;

    int nx, ny;
    get_next(x, y, nx, ny);

    if  (x == nx) {
      if  (X == x && Y > min(ny, y) && Y < max(ny, y))
        return cnt;
    } else {
      if  (Y == y && X > min(nx, x) && X < max(nx, x))
        return cnt;
    }

    x = nx; y = ny; 
  }

  return 0;
}

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  scanf("%d %d", &X, &Y);

  printf("%d\n", solve());
  return 0;
}