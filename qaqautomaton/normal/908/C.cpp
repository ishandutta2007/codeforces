#include<bits/stdc++.h>
using namespace std;
int n,r;
int x[1024];
double y[1024];
template<class T>void chkmax(T &a,T b){
    a=a<b?b:a;
}
const double eps=1e-8;
double msqrt(double s){
    if(s<-eps)return -1e9;
    if(s<eps)return 0;
    return sqrt(s);
}
int main(){
    scanf("%d%d",&n,&r);
    for(int i=1;i<=n;++i){
        scanf("%d",x+i);
        y[i]=r;
        for(int j=1;j<i;++j){
            chkmax(y[i],y[j]+msqrt(double(r*r*4-(x[i]-x[j])*(x[i]-x[j]))));
        }
        printf("%.10lf%c",y[i],i==n?'\n':' ');
    }
    return 0;
}