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

int n, k;

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  scanf("%d %d", &n, &k);

  if  (k > n) {
    puts("-1");
    return 0;
  }

  if  (k == 1) {
    if  (n == 1)
      puts("a");
    else
      puts("-1");
    return 0;
  }

  for (int i = 0; i < n; i++)
    if  (n - i <= k - 2)
      putchar('c' + (k - 2 - (n - i)));
    else if  (i % 2 == 0)
      printf("a");
    else
      printf("b");

  return 0;
}