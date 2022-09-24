#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

int n;
double  a, b, m;
double vx, vy, vz;


int main(){

  scanf("%lf%lf%lf%lf%lf%lf", &a, &b, &m, &vx, &vy, &vz);
  double t=-m/vy, x, z;
  x=t*vx+a/2.0; z=t*vz;
  int p=(int)(x/a/2), q=(int)fabs(z/b/2);
  x-=p*a*2;
  z-=q*b*2;
  if (x<0) x+=2*a;
  if (z<0) z+=2*b;
  if (x>a) x=2*a-x;
  if (z>b) z=2*b-z;
  printf("%.16f %.16f\n", x, z);
  return 0;
}