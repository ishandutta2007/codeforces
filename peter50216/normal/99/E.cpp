#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
double a,b,l;
double pi=acos((double)-1);
inline double solve(){
    if(a>b)swap(a,b);
    if(l<=a)return l;
    else if(l<=b)return a;
    else{
	double th=atan(cbrt(a/b));
	double maxl=b/cos(th)+a/sin(th);
	if(l>maxl+1e-7)return -1000;
	double ll=0,rr=pi/2;
	for(int k=0;k<50;k++){
	    double mm=(ll+rr)/2;
	    double d=-a*sin(mm)+b*cos(mm)-l*cos(2*mm);
	    if(d<0)ll=mm;
	    else rr=mm;
	}
	return a*cos(ll)+b*sin(ll)-l*sin(2*ll)/2;
    }
}
int main(){
    scanf("%lf%lf%lf",&a,&b,&l);
    double t=solve();
    if(t>=0)printf("%.7lf\n",solve());
    else puts("My poor head =(");
}