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
const int MAXN = (int) 1e5 + 10;

int n, k;
int a[MAXN];

int get_pos(LL x) {
  if  (x > (LL) 1e9) return -1;

  int pos = lower_bound(a, a + n, (int)x) - a;

  if  (pos == n || a[pos] != (int)x)
    return -1; 
   
  return pos;
}

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  sort(a, a + n);

  if  (k == 1) {
    printf("%d\n", n);
    return 0;
  }

  int res = 0;
  for (int i = 0; i < n; i++) {
    if  (a[i] % k == 0 && get_pos(a[i] / k) != -1) continue;

    int len = 1; int j = i;
    while (1) {
      j = get_pos(1LL * a[j] * k);
      if  (j == -1) break;
      len++;
    }
    
    res += (len + 1) / 2;
  }

  printf("%d\n", res);
  return 0;
}