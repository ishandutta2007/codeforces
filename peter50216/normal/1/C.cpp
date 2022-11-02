#include<stdio.h>
#include<math.h>
typedef long double ld;
struct XD{
    ld x,y;
    XD(ld xx=0,ld yy=0):x(xx),y(yy){}
    void input(){
	double xx,yy;
	scanf("%lf%lf",&xx,&yy);
	x=xx;y=yy;
    }
    XD operator-(const XD& b)const{
	return XD(x-b.x,y-b.y);
    }
    ld operator*(const XD& b)const{
	return x*b.x+y*b.y;
    }
    ld len2()const{
	return x*x+y*y;
    }
}in[3],cen;
const ld pi=acos((ld)-1);
const ld eps=1e-5;
inline ld isz(ld a){return a>-eps&&a<eps;}
inline bool isint(ld x){
    int xx=(int)x;
    return isz(x-xx)||isz(x-xx-1)||isz(x-xx+1);
}
int main(){
    int i;
    for(i=0;i<3;i++)in[i].input();
    ld x0=in[0].x;
    ld x1=in[1].x;
    ld x2=in[2].x;
    ld y0=in[0].y;
    ld y1=in[1].y;
    ld y2=in[2].y;
    //-2x0x+x0^2-2y0y+y0^2=
    ld a1=-2*x0+2*x2,b1=-2*y0+2*y2,c1=-(x0*x0+y0*y0-x2*x2-y2*y2);
    ld a2=-2*x1+2*x2,b2=-2*y1+2*y2,c2=-(x1*x1+y1*y1-x2*x2-y2*y2);
    ld det=a1*b2-a2*b1;
    cen.x=(c1*b2-c2*b1)/det;
    cen.y=(a1*c2-a2*c1)/det;
//    printf("%.3lf %.3lf\n",(double)cen.x,(double)cen.y);
    ld r2=(in[0]-cen).len2();
    ld an1=acos(((in[0]-cen)*(in[1]-cen))/r2)/2/pi;
    ld an2=acos(((in[0]-cen)*(in[2]-cen))/r2)/2/pi;
    for(i=3;i<=100;i++){
	ld b1=an1*i;
	ld b2=an2*i;
//	if(i<5)printf("%d %.8lf %.8lf\n",i,(double)b1,(double)b2);
	if(isint(b1)&&isint(b2))break;
    }
    printf("%.8lf\n",(double)(i*r2*sin(2*pi/i)/2));
}