#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef double db;
const db eps=1e-8;
int main()
{
    db a,v,l,d,w;
    scanf("%lf%lf%lf%lf%lf",&a,&v,&l,&d,&w);
    w=min(v,w);
    db len1=w*w/(2*a);
    db len2=v*v/(2*a)+(w*w-v*v)/(-2*a);
    db tv=0,res=0;
    if(len1>d-eps)
    {
        res+=sqrt(2*d/a);
        tv=sqrt(2*a*d);
    }
    else if(len2>d-eps)
    {
        tv=sqrt(a*d+w*w/2);
        res+=tv/a+(w-tv)/(-a);
        tv=w;
    }
    else
    {
        res+=v/a+(w-v)/(-a)+(d-len2)/v;
        tv=w;
    }
    db len=(v*v-tv*tv)/(2*a);
    if(len>l-d-eps)
        res+=(sqrt(tv*tv+2*a*(l-d))-tv)/a;
    else
        res+=(v-tv)/a+(l-d-len)/v;
    printf("%.10f\n",res);
    return 0;
}