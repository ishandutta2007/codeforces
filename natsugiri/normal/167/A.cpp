#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int n;
double a,d;
double t[100000],v[100000];
double sec[100000];
int main(){
  scanf("%d%lf%lf",&n,&a,&d);
  for(int i=0;i<n;i++)scanf("%lf%lf",t+i,v+i);
  for(int i=0;i<n;i++){
    double tm=v[i]/a;
    double y=a/2.0*tm*tm;
    if(y>d)sec[i]=sqrt(2.0*d/a)+t[i];
    else sec[i]=tm+(d-y)/v[i]+t[i];
  }
  for(int i=1;i<n;i++)
    sec[i]=max(sec[i],sec[i-1]);
  for(int i=0;i<n;i++)
    printf("%.20f\n",sec[i]);


  return 0;
}