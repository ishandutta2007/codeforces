#include <cstdio>
#include <iostream>
#include <vector>
#include <memory.h>
#include <string.h>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) int((a).size())
#define forn(i, n) for (int i=0; i<(n); ++i)
#define foreach(it, a) for (__typeof((a).begin()) it=(a).begin(); it!=(a).end(); ++it)

typedef unsigned long long ll;
typedef long double ld;
typedef pair<int,int> pii;

ll a, b;
int f[70][2];
int g[70][2];

void print(ll x)
{
  forn (i, 64) printf("%d", (x&(ll(1)<<i))>>i); puts("");
}

int solve(int i, int c)
{
  if (i >= 64) return c == 0;
  int& res = f[i][c];
  if (res != -1) return res;
  res = 0;
  ll q = (a&(ll(1)<<i))>>i;
 // printf("%d %c = %d %d\n", i, c, q, (b & (ll(1) <<i))>>i);
  if (b & (ll(1)<<i))
  {

    if ((1+c)%2 == q)
    {
      if (solve(i+1, (1+c)/2)) return res = 1;
    }
  }
  else
  {
    if (c % 2 == q)
    {
      if (solve(i+1, c/2)) return res = 1;
    }
    if ((c+2) % 2 == q)
    {
      if (solve(i+1, (c+2)/2)) return res = 1;
    }
  }
//  ghgfh
  return res;
}

ll make(int i, int c)
{
  if (i >= 64) return 0;
  ll res = 0;
  ll q = (a&(ll(1)<<i))>>i;
  if (b & (ll(1) << i))
  {
    if ((1+c)%2 == q)
    {
      if (solve(i+1, (1+c)/2))
      {
        return 1 + 2*make(i+1, (1+c)/2);
      }
    }
  }
  else
  {
    if (c % 2 == q)
    {
      if (solve(i+1, c/2)) return 0 + 2*make(i+1, c/2);
      if (solve(i+1, (c+2)/2)) return 1 + 2*make(i+1, (c+2)/2);
    }
  }
  return res;
}


int main()
{
  cin >> a >> b;
  memset(f, 0xff, sizeof(f));
  if (!solve(0, 0))
  {
    printf("-1\n");
    return 0;
  }
  ll x = make(0, 0);
  ll y = b ^ x;
  if (x > y) swap(x, y);
  cout << x << " " << y << endl;

  return 0;
}