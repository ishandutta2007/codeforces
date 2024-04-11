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

int cnt[15];

bool good(int x) {
  memset(cnt, 0, sizeof cnt);
  while (x) {
    cnt[x % 10]++;
    x /= 10;
  }

  for (int i = 0; i < 10; i++)
    if  (cnt[i] > 1) return false;
  return true;
}

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  int x; scanf("%d", &x);
  while (1) {
    x++;
    if  (good(x)) {
      printf("%d\n", x);
      return 0;
    }
  }

  return 0;
}