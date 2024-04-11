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
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> pii;

const double EPS = 1e-9;
const int MAXN = (int) 1e5 + 10;

char s[MAXN];
int pos = 0;
int n;

void read () {
  printf("<");

  if  (s[pos] == '"') {
    for (pos++; s[pos] != '"'; pos++)
      printf("%c", s[pos]);
    pos++;
  } else {
    for (; pos < n && s[pos] != ' '; pos++)
      printf("%c", s[pos]);
  }

  puts(">");
}

int main() {
  gets(s);
  n = (int) strlen(s);

  for (; pos < n; pos++)
    if  (s[pos] != ' ') read();
  return 0;
}