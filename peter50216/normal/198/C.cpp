// @author peter50216
// #includes {{{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<stdarg.h>
#include<time.h>
#include<ctype.h>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
// }}}
typedef long double ld;
const ld pi=acos((ld)-1);
inline ld get(){
    double x;
    scanf("%lf",&x);
    return x;
}
inline ld m(ld x){
    x-=(int)(x/(2*pi))*(2*pi);
    while(x>=2*pi)x-=2*pi;
    while(x<0)x+=2*pi;
    return x;
}
ld xp,yp,vp,x,y,v,r,d,rr,th,t2,s;
ld f(ld th){
    return sqrt(rr*rr+d*d-2*rr*d*cos(th));
}
ld bs(ld a,ld b){
    if(b<th)return 1e100;
    else if(a<th)a=th;
    if(f(a)/v<=(a-th)*rr/vp)return (a-th)*rr/vp;
    else if(f(b)/v>(b-th)*rr/vp)return 1e100;
    else{
        for(int k=0;k<100;k++){
            ld z=(a+b)/2;
            if(f(z)/v<=(z-th)*rr/vp)b=z;
            else a=z;
        }
        return (a-th)*rr/vp;
    }
}
int main(){
    xp=get();
    yp=get();
    vp=get();
    x=get();
    y=get();
    v=get();
    r=get();
    d=sqrt(x*x+y*y);
    rr=sqrt(xp*xp+yp*yp);
    th=m(atan2(yp,xp)-atan2(y,x));
    t2=acos(r/d)+acos(r/rr);
    s=sqrt(d*d-r*r)+sqrt(rr*rr-r*r);
    ld ans=1e100;

    ld d1=vp*(s/v)/rr+th-t2;
    d1=m(d1);
    ld dd1=d1/(1-r*vp/v/rr);
    ld tt1=dd1*r/v+s/v;
    ans=min(ans,tt1);

    ld d2=(2*pi-t2)-(vp*(s/v)/rr+th);
    d2=m(d2);
    ld dd2=d2/(1+r*vp/v/rr);
    ld tt2=dd2*r/v+s/v;
    ans=min(ans,tt2);
    for(int rot=0;rot<=30000;rot++){
        ans=min(ans,bs(2*pi-t2+2*pi*rot,2*pi+2*pi*rot));
        ans=min(ans,bs(2*pi*rot,t2+2*pi*rot));
    }
    printf("%.10lf\n",(double)ans);
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread