#include<bits/stdc++.h>
#define LL long long
using namespace std;
int a,b,c;
double x,y,x2,y2;
double dis;
int main(){
    scanf("%d%d%d",&a,&b,&c);
    scanf("%lf%lf%lf%lf",&x,&y,&x2,&y2);
    dis=abs(x-x2)+abs(y-y2);
    if (a!=0&&b!=0){
        double x3,y3,x4,y4;
        x3=1.0*(1LL*b*y+c)/-a;
        y3=1.0*(1LL*a*x+c)/-b;
        x4=1.0*(1LL*b*y2+c)/-a;
        y4=1.0*(1LL*a*x2+c)/-b;
        dis=min(dis,fabs(x3-x)+fabs(x4-x2)+sqrt((x3-x4)*(x3-x4)+(y-y2)*(y-y2)));
        dis=min(dis,fabs(x3-x)+fabs(y4-y2)+sqrt((x3-x2)*(x3-x2)+(y-y4)*(y-y4)));
        dis=min(dis,fabs(y3-y)+fabs(x4-x2)+sqrt((x-x4)*(x-x4)+(y3-y2)*(y3-y2)));
        dis=min(dis,fabs(y3-y)+fabs(y4-y2)+sqrt((x-x2)*(x-x2)+(y3-y4)*(y3-y4)));
    }
    printf("%.10f\n",dis);
}