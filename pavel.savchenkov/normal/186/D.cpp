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
 
const double eps = 1e-12;
const int int_inf = 2000000000;
const i64 i64_inf = 1000000000000000000LL;
const double pi = acos(-1.0);
const int mod = 1000000007;
 
using namespace std;
double s;
double a, b, c;

double f(double x, double y, double z) {
 if (fabs(x) < eps && a) return log(0.0);
 if (fabs(y) < eps && b) return log(0.0);
 if (fabs(z) < eps && c) return log(0.0);
 return a * log(x) + b * log(y) + c * log(z);
}

double gety(double x) {
 double l = 0.0; double r = s - x;
 for (int it=0; it!=500; it++)
 {
    double m1 = l + (r - l) / 3.0;
    double m2 = r - (r - l) / 3.0;
    if ( f(x, m1, s - x - m1) > f(x, m2, s - x - m2)) r = m2; else l = m1;
 }
 return l;
}

double func(double x) {
 double y = gety(x);
 return f(x, y, s - x - y);
}
//74,75, 82-84

int main() {
  cin >> s >> a >> b >> c;
  double l = 0.0; double r = s;
  for (int it=0; it!=500; it++) {
   double m1 = l + (r - l) / 3.0;
   double m2 = r -  (r - l) / 3.0;
   if ( func(m1) > func(m2) ) r = m2; else l = m1; 
  }
  
//  printf("%.10lf\n", f(l, gety(l), s - l - gety(l)) );
  printf("%.10lf %.10lf %.10lf\n",l, gety(l), s - l - gety(l));
  return 0;
}