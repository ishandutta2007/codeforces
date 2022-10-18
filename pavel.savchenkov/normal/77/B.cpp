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

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  int t;
  scanf("%d", &t);

  while (t--) {
    double a, b; scanf("%lf %lf", &a, &b);

    double s = a * b + a * a / 8.0;
 
    if  (4.0 * b <= a) 
      s -= (a / 4.0 - b) * (a - 4.0 * b) * 0.5;

    s /= 2.0 * a * b;

    if  (b == 0)
      printf("1.0000000000000000000000\n");
    else if  (a == 0)
      printf("0.500000000000000000000\n");
    else
      printf("%.20lf\n", s); 
  }

  return 0;
}