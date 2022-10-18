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
const i64 i64_inf = 1ll << 63 - 1;
const double pi = acos(-1.0);

using namespace std;

int n;
string name; int ma = -100500;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> n;

  forn(i, n)
  {
      char c = '.'; string s = ""; scanf("\n");
      while (1)
      {
          c = getchar();
          if  (c == ' ') break;
          s += c;
      }
      int score = 0;
      int p; scanf("%d", &p); score += p * 100;
      scanf("%d", &p); score -= p * 50;
      forn(j, 5)
       scanf("%d", &p), score += p;

      if  (score < ma) continue;
      ma = score; name = s;
  }

  cout << name;
  return 0;
}