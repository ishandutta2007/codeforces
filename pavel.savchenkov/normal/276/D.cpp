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

ull l, r;

ull solve() {
  for (int p = 63; p >= 0; p--) {
    ull val = 1ll << p;
    if  (l <= val - 1ll && val <= r)
      return 2ll * val - 1ll;

    if  (val <= l) {
      l -= val;
      r -= val;
    }
  }

  return 0;
}

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  cin >> l >> r;

  cout << solve() << '\n';

  return 0;
}