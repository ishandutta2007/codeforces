#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef double db;
const db eps=1e-9;
int main()
{
    db a,b,c;
    scanf("%lf%lf%lf",&a,&b,&c);
    if(a>eps)printf("%.20f\n%.20f\n",(-b+sqrt(b*b-4*a*c))/(2*a),(-b-sqrt(b*b-4*a*c))/(2*a));
    else if(a<-eps)printf("%.20f\n%.20f\n",(-b-sqrt(b*b-4*a*c))/(2*a),(-b+sqrt(b*b-4*a*c))/(2*a));
    else printf("%.20f\n%.20f\n",-c/b,-c/b);
    return 0;
}