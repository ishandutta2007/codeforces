//HACK ME, PLEASE! ^_^
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

const double eps = 1e-9;
const int int_inf = 1 << 31 - 1;
const i64 i64_inf = 1ll << 63 - 1;
const double pi = acos(-1.0);

using namespace std;

int c[(int)1e6 + 100];
char s[(int)1e6 + 100];
int res = 0; int cnt = 1;

void upd(int len)
{
 if  (len < res) return;
 if  (len == res) cnt++; else res = len, cnt = 1;
}

void go(int l, int r)
{
 while (l >= 0 && s[r] && s[l] == '(' && s[r] == ')') c[l] = r, c[r] = l, l--, r++;
 l++; r--;
 upd(r - l + 1);

 bool was = 0;
 while (l > 0 && c[l - 1] != -1) l = c[l - 1], was = 1;
 while (s[r + 1] && c[r + 1] != -1) r = c[r + 1], was = 1;
 if  (was) go(l, r);
}

int main() {
  memset(c, -1, sizeof c);
  gets(s);

  for (int i = 0; s[i + 1]; i++)
   if  (s[i] == '(' && s[i + 1] == ')' && c[i] == -1)
      c[i] = i + 1, c[i + 1] = i, go(i, i + 1);

  cout << res << " " << cnt << endl;
  return 0;
}