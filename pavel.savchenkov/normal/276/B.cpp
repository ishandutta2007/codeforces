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

char s[1010];
int cnt[40];

int main() {
  gets(s);

  memset(cnt, 0, sizeof cnt);

  for (int i = 0; s[i]; i++)
    cnt[s[i] - 'a']++;

  int c = 0;
  for (int i = 0; i <= 'z' - 'a'; i++)
    if  (cnt[i] % 2 == 1) c++;

  if  (c % 2 == 0 && c > 0)
    puts("Second");
  else
    puts("First");
  return 0;
}