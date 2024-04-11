#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <memory.h>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

using namespace std;

#define ll long long
#define pb push_back

const int MAXN = 10010;
const int MAXN2 = 2 * MAXN;
const int N = 1010;
const int mod = (int) 1e9 + 7;

int res = 0;
int n;

int a[N];
int cnt1[MAXN2];
int cnt2[MAXN2];
int cntTmp[MAXN2];
int cntTmp2[MAXN2];

void doit(int fr, int to) {
  if (to <= fr)
    return;
  for (int i =0 ; i < MAXN2; i++)
    cntTmp[i] = cnt1[i] = cnt2[i] = 0;
  int med = (to + fr) >> 1;
  cntTmp[MAXN] = 1;
  for (int pos = med; pos >= fr; pos--) {
    for (int j = 0; j < MAXN2; j++)
      cntTmp2[j] = 0;
    int val = a[pos];
    for (int j = 0; j < MAXN2; j++)
      if (cntTmp[j] != 0) {
        if (j + val < MAXN2) {
          cntTmp2[j + val] += cntTmp[j];
          if (cntTmp2[j + val] >= mod)
            cntTmp2[j + val] -= mod;
        }
        if (j - val >= 0) {
          cntTmp2[j - val] += cntTmp[j];
          if (cntTmp2[j - val] >= mod)
            cntTmp2[j - val] -= mod;
        }
      }
    for (int j = 0; j < MAXN2; j++) {
      cnt1[j] += cntTmp2[j];
      if (cnt1[j] >= mod)
        cnt1[j] -= mod;
      cntTmp[j] = cntTmp2[j];
    }
  }

  for (int j = 0; j < MAXN2; j++)
    cntTmp[j] = 0;
  cntTmp[MAXN] = 1;
  for (int pos = med + 1; pos <= to; pos++) {
    for (int j = 0; j < MAXN2; j++)
      cntTmp2[j] = 0;
    int val = a[pos];
    for (int j = 0; j < MAXN2; j++)
      if (cntTmp[j] != 0) {
        if (j + val < MAXN2) {
          cntTmp2[j + val] += cntTmp[j];
          if (cntTmp2[j + val] >= mod)
            cntTmp2[j + val] -= mod;
        }
        if (j - val >= 0) {
          cntTmp2[j - val] += cntTmp[j];
          if (cntTmp2[j - val] >= mod)
            cntTmp2[j - val] -= mod;
        }
      }
    for (int j = 0; j < MAXN2; j++) {
      cnt2[j] += cntTmp2[j];
      if (cnt2[j] >= mod)
        cnt2[j] -= mod;
      cntTmp[j] = cntTmp2[j];
    }
  }

  for (int i = 0; i < MAXN2; i++) {
    int realVal = i - MAXN;
    int needVal = -realVal;
    int needVal2 = needVal + MAXN;
    if (needVal2 >= 0 && needVal2 < MAXN2) {
      int v1 = cnt1[i];
      int v2 = cnt2[needVal2];
      res = (res + v1 * 1LL * v2) % mod;
    }
  }

  doit(fr, med);
  doit(med + 1, to);
}


int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int tmp;
    scanf("%d", &tmp);
    a[i] = tmp;
  }
  doit(0, n -1);
  cout << res << endl;
  return 0;
}