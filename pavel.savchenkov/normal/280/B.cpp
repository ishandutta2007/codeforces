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
const int MAXN = (int) 1e5 + 10;

int n;
int s[MAXN];

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) 
    scanf("%d", &s[i]);

  int bit = 0;
  for (int j = 31; j >= 0; j--) {
    bool was1 = false, was2 = false;

    for (int i = 0; i < n; i++)
      if  (s[i] & (1 << j)) 
        was1 = true;
      else
        was2 = true;

    if  (was1 && was2) {
      bit = j;
      break;
    }
  }


  int res = 0;
  for (int i = 0; i < n; i++)
    if  (s[i] & (1 << bit)) {
 
      int ma = -1;
      for (int j = i - 1; j >= 0 && !(s[j] & (1 << bit)); j--) {
        ma = max(ma, s[j]);
        res = max(res, s[i] ^ ma);  
      }

      ma = -1;
      for (int j = i + 1; j < n && !(s[j] & (1 << bit)); j++) {
        ma = max(ma, s[j]);
        res = max(res, s[i] ^ ma);
      }

  }

  printf("%d\n", res);
  return 0;
}