#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<stdarg.h>
#include<time.h>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    double s;
    double a,b,c;
    double aa,bb,cc;
    scanf("%lf%lf%lf%lf",&s,&a,&b,&c);
    double q=0;
    if(a<0.5){
        aa=0;
    }else{
        q+=a;
    }
    if(b<0.5){
        bb=0;
    }else{
        q+=b;
    }
    if(c<0.5){
        cc=0;
    }else{
        q+=c;
    }
    if(q>0.5){
        q=s/q;
        if(a>0.5)aa=q*a;
        if(b>0.5)bb=q*b;
        if(c>0.5)cc=q*c;
    }
    printf("%.10lf %.10lf %.10lf\n",aa,bb,cc);
}