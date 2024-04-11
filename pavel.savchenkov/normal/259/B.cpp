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

int a[4][4];

bool ok() {
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      if  (a[i][j] > 100000 || a[i][j] <= 0) return false;

  int sum = a[0][0] + a[0][1] + a[0][2];

  for (int i = 0; i < 3; i++) {
    int csum = 0;
    for (int j = 0; j < 3; j++)
      csum += a[i][j];

    if  (csum != sum) return false;

    csum = 0;
    for (int j = 0; j < 3; j++)
      csum += a[j][i];

    if  (csum != sum) return false;
  }

  if  (a[0][0] + a[1][1] + a[2][2] != sum) return false;
  if  (a[2][0] + a[1][1] + a[0][2] != sum) return false;

  return true;                                            
}

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      scanf("%d", &a[i][j]);

  for (int i = 1; i <= 100000; i++) {
    a[0][0] = i;
    int sum = 0;
    for (int j = 0; j < 3; j++)
      sum += a[0][j];

    a[1][1] = sum - a[1][0] - a[1][2];
    a[2][2] = sum - a[2][0] - a[2][1];

    if  (ok()) {
      for (int j = 0; j < 3; j++, puts(""))
        for (int k = 0; k < 3; k++)
          printf("%d ", a[j][k]);
      return 0;
    }
  }

  return 0;
}