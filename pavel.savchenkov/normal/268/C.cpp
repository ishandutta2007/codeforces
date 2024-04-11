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

#define pb push_back
#define LL long long
#define uLL unsigned long long
#define mp make_pair
#define pii pair <int,int>
#define sz(A) ((int)(A).size())
#define y1 qwertyuiopasdfghjklzxcvbnm
#define y0 ehfoiuvhefroerferjhfjkehfjke

const double EPS = 1e-9;
const double PI = acos(-1.0);

using namespace std;

int n, m;
int res = 0;

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  cin >> n >> m;

  int x = 0; int y = m;
  while (x <= n && y >= 0) {
    x++; y--; res++;    
  }

  printf("%d\n", res);
  x = 0; y = m;
  while (x <= n && y >= 0)
    printf("%d %d\n", x++, y--);
   
  return 0;
}