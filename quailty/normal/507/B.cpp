#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef double db;
const db eps=1e-11;
db dis(db x1,db y1,db x2,db y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main()
{
    db r,x,y,x0,y0;
    scanf("%lf%lf%lf%lf%lf",&r,&x,&y,&x0,&y0);
    db t=dis(x,y,x0,y0)/r/2;
    if(t<(int)t+eps)printf("%.0f\n",t);
    else printf("%.0f\n",t+0.5);
    return 0;
}