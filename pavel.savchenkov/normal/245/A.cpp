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
#define vi vector <int>
#define vii vector <pii>
#define f first
#define s second
#define foran(i,a,b) for (int i=a;i<(int)b;i++)
#define forn(i,n) for (int i=0;i<(int)n;i++)
#define ford(i,n) for (int i=(int)n-1;i>=0;i--)
#define sqr(x) ((x) * (x))
#define sz(A) ((int)(A).size())
#define y1 asxfdsfsdsjhfgidf
#define y0 dsfgdfggdfjdhriwurehiw

const double EPS = 1e-9;
const double PI = acos(-1.0);

using namespace std;

int all[2];
int good[2];
int n;

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  all[0] = all[1] = good[0] = good[1] = 0;
  cin >> n;
  forn(i, n) {
    int t, x, y;
    scanf("%d%d%d", &t, &x, &y);
    all[t - 1] += 10;
    good[t - 1] += x;
  }

  forn(i, 2)
    if  ((all[i] % 2 == 1 && all[i] / 2 < good[i]) || (all[i] % 2 == 0 && all[i] / 2 <= good[i]))
        puts("LIVE");
    else
        puts("DEAD");
  return 0;
}