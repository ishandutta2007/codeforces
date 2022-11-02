#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
struct XD{
    double x,y;
    XD(double xx=0,double yy=0):x(xx),y(yy){}
    XD operator-(const XD& b)const{
	return XD(x-b.x,y-b.y);
    }
    double operator^(const XD& b){
	return x*b.y-y*b.x;
    }
    void input(){scanf("%lf%lf",&x,&y);}
}in[1010];
inline double ABS(double a){return a>0?a:-a;}
double l=1e10,r=-1e10;
int n;
void trys(double tmt){
    int j;
    XD pt(tmt,in[0].y);
    for(j=1;j<n;j++){
	int k=(j+1)%n;
	if(((pt-in[j])^(in[k]-in[j]))<-1e-7)break;
    }
    if(j==n){
	l=min(l,tmt);
	r=max(r,tmt);
    }
}
int main(){
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)in[i].input();
    if(in[0].x>in[1].x){
	for(i=0;i<n;i++){
	    in[i].x*=-1;
	    in[i].y*=-1;
	}
    }
    for(i=2;i<n-1;i++){
	double d1=ABS((in[1]-in[i+1])^(in[1]-in[i]));
	double d2=ABS((in[0]-in[i+1])^(in[0]-in[i]));
	trys(((double)in[0].x*d1+(double)in[1].x*d2)/(d1+d2));
    }
    trys(in[0].x);
    trys(in[1].x);
    //printf("%lf %lf %d %d\n",l,r,i,j);
    if(l>r)puts("0");
    else printf("%d\n",((int)floor(r+1e-7))-((int)floor(l-1e-7)));
}