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

typedef long long int64;
typedef long double ld;

#define abs(x) (((x)<0)?(-(x)):(x))

bool isint(ld x){   
    int tmp=int(x);
    for (int i=tmp-1;i<=tmp+1;i++){
        if (abs(i-x) < (1e-4)){
            return true;
        }
    }
    return false;
}



int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    ld x1,y1,x2,y2,x3,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    x2-=x1;
    x3-=x1;
    y2-=y1;
    y3-=y1;
    x1=y1=0;
    ld a1=x2;
    ld b1=y2;
    ld c1=(x2*x2+y2*y2)/2;
    ld a2=x3;
    ld b2=y3;
    ld c2=(x3*x3+y3*y3)/2;
    
    ld xc=(c1*b2-c2*b1)/(a1*b2-a2*b1);
    ld yc=(a1*c2-c1*a2)/(a1*b2-a2*b1);

    x1-=xc;y1-=yc; 
    x2-=xc;y2-=yc;
    x3-=xc;y3-=yc;
    
    ld ang1=atan2(y1,x1);
    ld ang2=atan2(y2,x2);
    ld ang3=atan2(y3,x3);
    
    ang2-=ang1;
    ang3-=ang1;
    
    while (ang2 < 0)
        ang2+=2*M_PI;
    
    while (ang3 < 0)
        ang3+=2*M_PI;
        
    while (ang2 > 2*M_PI)
        ang2-=2*M_PI;
    
    while (ang3 > 2*M_PI)
        ang3-=2*M_PI;
        
    ang2/=2*M_PI;
    ang3/=2*M_PI;
    

    for (int i=3;i<=100;i++){
        if (isint(i*ang2) && isint(i*ang3)){
            cout.precision(15);
            cout<<fixed<< 0.5*(x1*x1+y1*y1)*i*sin(2*M_PI/i) << endl;
            return 0;
        }
    }
    
    return 0;
}