#include<stdio.h>
#include<math.h>
struct XD{
    double x,y,z;
    void input(){scanf("%lf%lf%lf",&x,&y,&z);}
    XD operator+(const XD& b)const{
	XD a;
	a.x=x+b.x;
	a.y=y+b.y;
	a.z=z+b.z;
	return a;
    }
};
XD a,v;
double r;
inline double MIN(double a,double b){return a<b?a:b;}
inline double solve(XD a,XD b,XD v,double r){//a speed v shortest time dis <=r
    //Assume t=0 no touch
    double c1,c2,c3;
    c1=v.x*v.x+v.y*v.y+v.z*v.z;
    c2=v.x*(a.x-b.x)*2+v.y*(a.y-b.y)*2+v.z*(a.z-b.z)*2;
    c3=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z)-r*r;
//    printf("%lf %lf %lf\n",c1,c2,c3);
    //(a.x+v.x*t-b.x)^2+... <=r*r -> c1t^2+c2t+c3<=0
    if(c2*c2-4*c1*c3<0)return 1e100;
    double s1=(-c2-sqrt(c2*c2-4*c1*c3))/(2*c1);
    if(s1<0)return 1e100;
    else return s1;
}
int main(){
    a.input();v.input();scanf("%lf",&r);
    int n,i;
    scanf("%d",&n);
    double mint=1e100;
    for(i=0;i<n;i++){
	XD cen;
	cen.input();
	double ri;
	scanf("%lf",&ri);
	mint=MIN(mint,solve(a,cen,v,r+ri));
	int q;
	scanf("%d",&q);
	while(q--){
	    XD dif;
	    dif.input();
	    mint=MIN(mint,solve(a,cen+dif,v,r));
	}
    }
    if(mint>1e99)puts("-1");
    else printf("%.10lf\n",mint);
}