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
const int MOD = (int) 1e9 + 9;

using namespace std;

void add(int & a, int b) {
  a += b;
  if  (a >= MOD) a -= MOD;
}

int d[2][2][32][32][32];
int nn, h;
int last[3];
int nlast[3];

int nxt(int hh) {
  if  (hh == 0 || hh == h - 1) return 0;
  return hh + 1;
}

void clear(int c) {
  for (int a = 0; a <= 1; a++)
    for (int l1 = 0; l1 < h; l1++)
      for (int l2 = l1; l2 < h; l2++)
        for (int l3 = l2; l3 < h; l3++)
          d[c][a][l1][l2][l3] = 0;
}

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  scanf("%d%d", &nn, &h);
  memset(d, 0, sizeof d);

  d[0][1][h != 1][h != 1][h != 1] = 1;
  int c = 0;
  int res = 0;                 

  for (int n = 1; n <= nn; n++, clear(c), c = 1 - c)
    for (int alive = 0; alive <= 1; alive++)
      for (int last1 = 0; last1 < h; last1++)
        for (int last2 = last1; last2 < h; last2++)
          for (int last3 = last2; last3 < h; last3++) {

            if  (n == nn && (alive || last1 || last2 || last3)) 
              add(res, d[c][alive][last1][last2][last3]);  
           

            int curd = d[c][alive][last1][last2][last3];
            last[0] = last1; last[1] = last2; last[2] = last3;

            for (int i = 0; i < 3; i++)
              nlast[i] = nxt(last[i]);
            sort(nlast, nlast + 3);
            add(d[1 - c][alive][nlast[0]][nlast[1]][nlast[2]], curd);

            for (int next = 0; next <= 2; next++) {
              int nalive = last[next] > 0;
              nlast[0] = alive;
              int i = 1;
              for (int j = 0; j < 3; j++)
                if  (j != next) nlast[i++] = nxt(last[j]);
              sort(nlast, nlast + 3);

              add(d[1 - c][nalive][nlast[0]][nlast[1]][nlast[2]], curd);            
            }
          }

  for (int i = 0; i < 2; i++)
    add(res, res);

  printf("%d\n", res);
  return 0;
}