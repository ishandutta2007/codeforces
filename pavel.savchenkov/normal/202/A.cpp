#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <utility>
#include <math.h>
#include <cstdlib>
#include <memory.h>
#include <queue>
#include <assert.h>

#define pb push_back
#define i64 long long
#define mp make_pair
#define pii pair <int,int>
#define vi vector <int>
#define vii vector <pii>
#define f first
#define s second
#define foran(i,a,b) for (int i=a;i<(int)b;i++)
#define forn(i,n) for (int i=0;i<(int)n;i++)
#define ford(i,n) for (int i=(int)n-1;i>=0;i--)
#define sqr(x) (x) * (x)
#define y1 fucking_y1

const double eps = 1e-9;
const int int_inf = 1 << 31 - 1;
const i64 i64_inf = 1ll << 63 - 1ll;
const double pi = acos(-1.0);

using namespace std;

string s;
int n;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  getline(cin, s);
  int n = (int)s.length();
  string res = "";
  res += s[0];

  for (int mask = 1; mask <= (1 << n) - 1; mask++)
  {
      string cur = "";
      forn(i, n)
       if  (mask & 1 << i) cur += s[i];

      bool ok = 1;
      forn(i, cur.length())
       if  (cur[i] != cur[(int)cur.length() - i - 1]) ok = 0;
      if  (!ok) continue;

      res = max(res, cur);
  }

  cout << res << "\n";
  return 0;
}