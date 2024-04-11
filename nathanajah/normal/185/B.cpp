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
#include <map>
#include <set>
using namespace std;

double s,a,b,c;
double x,y,z;
int main()
{
    scanf("%lf",&s);
    scanf("%lf %lf %lf",&a,&b,&c);
    if (a+b+c==0)
        printf("0.0 0.0 0.0\n");
    else
    {
        x=(a/(a+b+c))*s;
        y=(b/(a+b+c))*s;
        z=(c/(a+b+c))*s;
        printf("%.13lf %.13lf %.13lf\n",x,y,z);
    }
}