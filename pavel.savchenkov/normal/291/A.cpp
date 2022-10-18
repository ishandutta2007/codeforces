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

int n;
int id[1010];

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", &id[i]);

  sort(id, id + n);
  id[n] = (int) 1e9 + 1;

  int res = 0; int cnt = 1;
  for (int i = 1; i <= n; i++)
    if  (id[i] != id[i - 1]) {
      if  (cnt > 2 && id[i - 1] > 0) {
        puts("-1");
        return 0;
      }

      if  (cnt == 2 && id[i - 1] != 0) res++;
      cnt = 1; 
    } else cnt++;

  printf("%d\n", res);

  return 0;
}