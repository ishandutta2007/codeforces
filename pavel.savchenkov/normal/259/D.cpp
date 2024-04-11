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
const int MOD = 1000000007;

using namespace std;

bool luck(int x) {
  return x == 7 || x == 4;
}

int dp[12][12][3];
int d[12];
int m[10];
int lenm;

int add(int a, int b) {
  a += b;
  while (a > MOD) a -= MOD;
  return a;
}

int mul(int a, int b) {
  LL M = 1LL * a * b;
  M %= (LL)MOD;
  return (int)M;
}

int go(int i, int cnt) {
  if  (i == 6) return 1;
  int res = 0;
  
//  printf("in %d cnt = %d\n", i, cnt);

  for (int c = 0; c < cnt; c++) {
    d[c]--;
    res = add(res, mul(d[c] + 1, go(i + 1, cnt - c)));
    d[c]++;
  }

  return res;
}

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  int M; scanf("%d", &M);
  lenm = 0;
  while (M > 0) {
    m[lenm++] = M % 10;
    M /= 10; 
  }
  reverse(m, m + lenm);

  memset(dp, 0, sizeof dp);
  memset(d, 0, sizeof d);

  if  (m[0] == 7 && lenm == 1) {
    dp[1][0][0] = 4;
    dp[1][1][0] = 1;
    dp[1][1][1] = 1;
    dp[1][0][1] = 1;
  } else {
    for (int i = 1; i < m[0]; i++)
      dp[1][luck(i)][0]++;
    dp[1][luck(m[0])][1]++;

    for (int i = m[0] + 1; i < 10; i++)
      dp[1][luck(i)][2]++;
  }

  for (int len = 1; len <= lenm; len++)
    for (int cnt = 0; cnt <= len; cnt++)
      for (int e = 0; e < 3; e++) {
        
        if  (len < lenm || e <= 1)
            d[cnt] += dp[len][cnt][e];

        for (int next = 0; next < 10; next++) {
          int ncnt = cnt + (luck(next));
          int ne;
          if  (e == 1) {
            if  (next == m[len]) 
              ne = 1;
            else if  (next < m[len])
              ne = 0;
            else
              ne = 2;
          } else ne = e;

          dp[len + 1][ncnt][ne] += dp[len][cnt][e];
        }

     }

//  for (int i = 0; i <= 9; i++)
//    printf("cnt = %d -> %d\n", i, d[i]);

  int res = 0;
  for (int cnt = 1; cnt <= 9; cnt++) {
    d[cnt]--;    
    res = add(res, mul(d[cnt] + 1, go(0, cnt)));
    d[cnt]++;
  }

  printf("%d\n", res);

  return 0;
}