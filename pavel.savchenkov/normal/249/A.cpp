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
#define all(A) ((A).begin(), (A).end())
#define y1 asxfdsfsdsjhfgidf
#define y0 dsfgdfggdfjdhriwurehiw

const double EPS = 1e-9;
const double PI = acos(-1.0);

using namespace std;

double y1, y2, yw, xb, yb, r;

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  cin >> y1 >> y2 >> yw >> xb >> yb >> r;
  yw -= r;
  y2 = yw + (yw - y2);
  y1 = yw + (yw - y1);
  swap(y1, y2);

//  printf("%.10lf %.10lf\n", y1, y2);

  double L = y1 + 1e-10; double R = y2; int it = 0;
  while (it < 1000) {
        it++;
        double M = (L + R) * 0.5;

        double b = M;
        double k = - fabs(b - yb) / fabs(xb);
        double b1 = fabs(b) - r * sqrt(k * k + 1.0);
        if  (b1 > y1 + 1e-9) R = M; else L = M;
  }

  double b = R;
  double k = - fabs(b - yb) / fabs(xb);
  double b1 = fabs(b) + r;

//  printf("%.10lf %.10lf\n", k, b1);
  if  (b1 + 1e-9 > y2) { puts("-1"); return 0; }

  double xw = (yw - b) / k;
  printf("%.20lf\n", fabs(xw));
  return 0;
}