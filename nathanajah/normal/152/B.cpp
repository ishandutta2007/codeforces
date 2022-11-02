#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
#include <set>
#include <queue>
using namespace std;

long long n,m;
long long x,y;
long long k,i;
long long vx,vy;
long long bx,by;
long long tbanyak;
long long banyak;

int main()
{
    cin >> n >> m;
    cin >> x >> y;
    cin >> k;
    for (i=0;i<k;i++)
    {
        cin >> vx >> vy;
        if (vx>0)
            bx=(n-x)/vx;
        if (vx==0)
            bx=2000000000000000LL;
        if (vx<0)
            bx=(1-x)/vx;
        if (vy>0)
            by=(m-y)/vy;
        if (vy==0)
            by=2000000000000000LL;
        if (vy<0)
            by=(1-y)/vy;
        tbanyak=min(by,bx);
        banyak=banyak+tbanyak;
        x=x+(vx*tbanyak);
        y=y+(vy*tbanyak);
    }
    cout << banyak << "\n";
}