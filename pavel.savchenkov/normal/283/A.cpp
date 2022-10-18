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

int n;
vector <int> a;
vector <int> add;
ll sum = 0;

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  a.pb(0); add.pb(0);

  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    int t; scanf("%d", &t);

    if  (t == 1) {
      int a, x; scanf("%d %d", &a, &x);
      sum += 1ll * a * x;
      add[a - 1] += x;  
    } else if  (t == 2) {
      int k; scanf("%d", &k);
      sum += 1ll * k;
      a.pb(k);
      add.pb(0);
    } else {
      int m = sz(a);
      sum -= 1ll * (a[m - 1] + add[m - 1]);
      a.pop_back(); add[m - 2] += add[m - 1]; add.pop_back();
    }

    printf("%.10lf\n", (double) sum / sz(a));
  }

  return 0;
}