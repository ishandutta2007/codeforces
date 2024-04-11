#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
using namespace std;

int x1,y11,r1;
int x2,y2,r2;
double x3,y3;
double dist;
int tmp;

int sqr(int a)
{
    return a*a;
}
int main()
{
    scanf("%d %d %d",&x1,&y11,&r1);
    scanf("%d %d %d",&x2,&y2,&r2);
    if (r2>r1)
    {
        tmp=r2;
        r2=r1;
        r1=tmp;
    }
    dist=sqrt(sqr(x1-x2)+sqr(y11-y2));
    if (dist >= r1 + r2)
        printf("%.15lf\n",(dist-r1-r2)/2.0);
    else if (r2+dist<=r1)
        printf("%.15lf\n",(r1-dist-r2)/2.0);
    else
        printf("0.0\n");
}