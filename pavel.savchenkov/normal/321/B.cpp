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
const int MAXN = 110;

int n, m;
int a[MAXN];
int b[MAXN];
char buf[10];
bool used[MAXN];
vector <int> att;
vector <int> def;

int kill_all () {
  memset (used, false, sizeof used);
  int ans = 0;
  int covered = 0;

  for (int i = 0; i < sz(def); i++)
    for (int j = 0; j < m; j++)
      if  (!used[j] && b[j] > a[def[i]]) {
        used[j] = true;
        covered++;
        break;
      }

  for (int i = sz(att) - 1; i >= 0; i--)
    for (int j = m - 1; j >= 0; j--)
      if  (!used[j] && b[j] >= a[att[i]]) {
        used[j] = true;
        ans += b[j] - a[att[i]];
        covered++;
        break;
      }

  if  (covered < n)
    return ans;

  for (int i = 0; i < m; i++)
    if  (!used[i])
      ans += b[i];

  return ans; 
}

int kill_attack (int cnt) {
  memset (used, false, sizeof used);
  int ans = 0;

  for (int i = cnt - 1; i >= 0; i--)
      for (int j = m - 1; j >= 0; j--)
        if  (!used[j] && b[j] >= a[att[i]]) {
          used[j] = true;
          ans += b[j] - a[att[i]];
          break;
        }

  return ans;
}

int main() {
  scanf("%d %d\n", &n, &m);

  for (int i = 0; i < n; i++) {
    scanf("%s %d\n", buf, &a[i]);
    if  (buf[0] == 'A')
      att.pb(i);
    else
      def.pb(i); 
  }

  for (int i = 0; i < m; i++)
    scanf("%d", &b[i]);

  for (int i = 0; i < sz(att); i++)
    for (int j = i + 1; j < sz(att); j++)
      if  (a[att[i]] > a[att[j]])
        swap(att[i], att[j]);

  for (int i = 0; i < sz(def); i++)
    for (int j = i + 1; j < sz(def); j++)
      if  (a[def[i]] > a[def[j]])
        swap(def[i], def[j]);

  sort(b, b + m);

  int ans = 0;
  for (int cnt = 1; cnt <= sz(att); cnt++)
    ans = max(ans, kill_attack(cnt));

  printf("%d\n", max(kill_all(), ans));
  return 0;             
}