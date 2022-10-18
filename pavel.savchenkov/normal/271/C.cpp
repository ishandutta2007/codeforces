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

int n, k;

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  scanf("%d%d", &n, &k);

  if  (3 * k > n) {
    puts("-1");
    return 0;
  }

  for (int i = 1; i <= k; i++)
    printf("%d %d ", i, i);

  for (int i = 1; i <= k; i++)
    printf("%d ", i);

  for (int i = 0; i < n - 3 * k; i++)
    printf("1 ");

  return 0;
}