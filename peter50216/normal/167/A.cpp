#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
double t[101000],v[101000];
double out[101000];
int main(){
    int n,i,j;
    double a,d;
    scanf("%d%lf%lf",&n,&a,&d);
    for(i=0;i<n;i++)scanf("%lf%lf",&t[i],&v[i]);
    for(i=0;i<n;i++){
        double tt;
        double dd=v[i]*v[i]/a/2;
        if(dd>=d){
            double s=sqrt(d/dd);
            tt=s*v[i]/a;
        }else{
            tt=v[i]/a+(d-dd)/v[i];
        }
        if(i==0){
            out[i]=t[i]+tt;
        }else{
            if(t[i]+tt<out[i-1])out[i]=out[i-1];
            else out[i]=t[i]+tt;
        }
    }
    for(i=0;i<n;i++)printf("%.10lf\n",out[i]);
}