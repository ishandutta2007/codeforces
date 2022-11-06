#include <cstdio>

double max(double a,double b){ return a>b?a:b; }
double min(double a,double b){ return a<b?a:b; }

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    if(a<b){
        puts("-1"); return 0;
    }
    double ans=(1e9);
    
    a-=b;
    // x >= b.
    // x=0.5a/k
    int l=0, r=int(1e9)+1, m;
    
    while(l+1<r){
        m=(l+r)/2;
        if(a >= 2ll*m*b) l=m;
        else r=m;
    }
    if(l!=0) ans=min(ans,0.5*a/l);
    
    a+=2*b;
    // x >= b.
    // x=0.5a/k
    l=0, r=int(1e9)+1;
    while(l+1<r){
        m=(l+r)/2;
        if(a >= 2ll*m*b) l=m;
        else r=m;
    }
    if(l!=0) ans=min(ans,0.5*a/l);
    
    printf("%.10f",ans);
    return 0;
}