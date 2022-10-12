#include<cmath>
#include<cstdio>
using namespace std;

double solve(double a, double b, double c){
//  printf("%lf %lf %lf\n",a,b,c);
    return (-b+sqrt(b*b-a*c))/a;
}

int main(){
    double x1,y1,x,y,V,k,vx,vy,ux,uy,t;
    scanf("%lf %lf %lf %lf",&x1,&y1,&x,&y); y-=y1; x-=x1;
    scanf("%lf %lf",&V,&k);
    scanf("%lf %lf",&vx,&vy);
    scanf("%lf %lf",&ux,&uy);
    t=solve(V*V-vx*vx-vy*vy,(x*vx+y*vy),-x*x-y*y);
    if(k-t>1e-12)return 0*printf("%.15lf\n",t);
    t=solve(V*V-ux*ux-uy*uy,(ux*x+uy*y+k*ux*(ux-vx)+k*uy*(uy-vy)),-(x+k*(ux-vx))*(x+k*(ux-vx))-(y+k*(uy-vy))*(y+k*(uy-vy)));
    printf("%.15lf\n",t);
    return 0;
}