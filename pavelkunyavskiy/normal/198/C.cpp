#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>
#define mp make_pair
#define pb push_back                     
#define setval(a,v) memset(a,v,sizeof(a))

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long ll;
typedef long double ld;


ld calc(ld d1,ld d2,ld d3,ld r){
    ld angC = acos((d1*d1 + d2*d2 - d3*d3)/(2*d1*d2));
    ld ang1 = acos(r/d1);
    ld ang2 = acos(r/d2);

    ld ans = 0;

    if (ang1 + ang2 < angC)
       ans = sqrt(d1*d1-r*r) + sqrt(d2*d2-r*r) + r*(angC - ang1 - ang2);
    else
       ans = d3;
    return ans;
}

ld xp,yp,vp;
ld x,y,v,r;

ld calc(ld tox,ld toy){
    ld d1 = sqrt(x*x + y*y);
    ld d2 = sqrt(tox*tox+toy*toy);
    ld d3 = sqrt((x-tox)*(x-tox) + (y-toy)*(y-toy));
    return calc(d1,d2,d3,r);
}

void get(ld& x,ld& y,ld t){
    ld ang = t*vp;
    ang /= sqrt(xp*xp+yp*yp);
    x = xp*cos(ang) - yp*sin(ang);
    y = xp*sin(ang) + yp*cos(ang);
}


int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  ld lf = 0;
  ld rg = 1e10;

  cin >> xp >> yp >> vp;
  cin >> x >> y >> v >> r;

  for (int i = 0; i < 1000; i++){
     ld mid = (lf+rg)/2;

     ld nx,ny;
     get(nx,ny,mid);

     if (calc(nx,ny) >= v*mid+(1e-10))
        lf = mid;
     else
        rg = mid;
  }


  cout.precision(15);
  cout << fixed << (lf+rg)/2 << endl;

      
  return 0;
}