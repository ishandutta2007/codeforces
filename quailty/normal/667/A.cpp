#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef double db;
const db PI=acos(-1.0);
int main()
{
    db d,h,v,e;
    scanf("%lf%lf%lf%lf",&d,&h,&v,&e);
    v/=PI*(d/2.0)*(d/2.0);
    if(v<e)printf("NO\n");
    else printf("YES\n%.12f\n",h/(v-e));
    return 0;
}