#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
double solve(double v0,double a,double d,double vm,double vl){
    double tt=(vl-v0)/a;
    double dd=(v0+vl)*tt/2;
    if(dd>=d){
	return (-v0+sqrt(v0*v0+2*a*d))/a;
    }else{
	double ttt=(vm-vl)/a;
	double ddd=dd+(vl+vl+ttt*a)*ttt;
	if(ddd>=d){
	    d-=dd;
	    d/=2;
	    return (-vl+sqrt(vl*vl+2*a*d))/a*2+tt;
	}else{
	    return tt+ttt*2+(d-ddd)/vm;
	}
    }
}
int main(){
    double a,v,l,d,w;
    scanf("%lf%lf%lf%lf%lf",&a,&v,&l,&d,&w);
    double t1=solve(0,a,d,v,min(v,w));
    double t2=solve(min(t1*a,min(v,w)),a,l-d,v,v);
    printf("%.12lf\n",t1+t2);
}