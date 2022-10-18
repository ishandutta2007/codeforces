//#pragma comment (linker, "/STACK:200000000") 
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
#define pb push_back
#define i64 long long
const double eps = 1e-9;
const int inf = 2000000000;
const double pi = acos(-1.0);

using namespace std;

bool was[1001][1001][2];
double d[1001][1001][2];

double go(int ww,int bb,bool h)
{
    if (ww<0 || bb<0) return 0.0;
    if (was[ww][bb][h]) return d[ww][bb][h];
    was[ww][bb][h] = true;
    if (ww == 0) return d[ww][bb][h] = 0.0;
    if (bb == 0) return d[ww][bb][h] = 1.0;

    double w = (double)ww; double b = (double)bb;
    
    if (!h) return d[ww][bb][h] = w/(w+b) + (1 - go(w,b-1,1))*(b/(w+b));
    
    return d[ww][bb][h] = w/(w+b) +  ((1-go(w,b-2,0))*(b-1)/(w+b-1) + (1-go(w-1,b-1,0))*w/(w+b-1)) * (b/(w+b));
};

int main() {
   int w,b; cin >> w >> b;
   memset(was,false,sizeof(was));
   printf("%.10lf",go(w,b,0));
   return 0;
}