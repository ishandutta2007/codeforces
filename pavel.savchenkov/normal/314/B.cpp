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
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define foran(i, a, n) for (int i = int(a); i < int(n); i++)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> pii;

const double EPS = 1e-9;
const int MAXN = 100 * 110 + 10;

int b, d;
char a[MAXN];
char c[MAXN];
int A;
int C;

int add[110];
int blocks[110];

void calc (int i) {
  int j = 0; int ii = i;
  while (1) {
    if  (j == C)
      break;

    while (ii < (C + 1) * A && a[ii] != c[j]) ii++;
    
    ii++; j++;

    if  (ii == (C + 1) * A + 1)
      break;
  }

  ii--;

  if  (ii >= (C + 1) * A) {
    add[i] = int(1e9) + 100;
    blocks[i] = -1;
    return;
  }    

  if  (ii < A - 1 && ii + 1 + add[ii + 1] < A) {
    add[i] = ii + 1 + add[ii + 1] - i;
    blocks[i] = 1 + blocks[ii + 1];  
  } else {
    add[i] = ii - i;
    blocks[i] = 1;
  }
}

int main() {
  scanf("%d %d\n", &b, &d);
  gets(a);
  gets(c);
  A = int(strlen(a));
  C = int(strlen(c));

  for (int bl = 1; bl < C + 1; bl++)
    for (int i = bl * A; i < (bl + 1) * A; i++)
      a[i] = a[i - bl * A];
               
  ford(i, A)
    calc(i);  

  int cnt = 0;
  for (int i = 0; i < A * b; i = i + add[i % A] + 1) {
    if  (i + add[i % A] < A * b)
      cnt += blocks[i % A];
  }
             
  printf("%d\n", cnt / d);
  return 0;
}