#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef double db;
const db PI=acos(-1.0);
db get(db l,int n)
{
    db r=l/2/sin(PI/n);
    db h=sqrt(l*l-r*r);
    return n*r*r*sin(2*PI/n)/2*h/3;
}
int main()
{
    db l[3];
    for(int i=0;i<3;i++)
        scanf("%lf",&l[i]);
    db res=0.0;
    for(int i=3;i<=5;i++)
        res+=get(l[i-3],i);
    printf("%.10f\n",res);
    return 0;
}