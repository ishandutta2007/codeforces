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

vector <int> a;

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  
  int i = 1; char c;
  while (scanf("%c", &c) >= 1 && c != '\n') {
    if  (c == 'l')
      a.pb(i++);
    else {
      printf("%d\n", i++);
    }
  }

  for (int i = sz(a) - 1; i >= 0; i--)
    printf("%d\n", a[i]);
  puts("");

  return 0;
}