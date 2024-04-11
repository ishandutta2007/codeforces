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


int main() {
  // freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   int v1,v2,t,f,c;
   cin >> v1 >> v2 >> t >> f >> c; 
   if (v2 <= v1) { cout << "0" << endl; return 0; }
   double d = t*v1; int res = 0;
   
   while (true)
   {
    d = (d*v2)/(v2-v1);
    if (d > c - eps) break;
    res++;
    d+=((d/v2) + f)*v1;
   }
   cout << res << endl;
   return 0;
}