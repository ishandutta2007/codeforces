#include <bits/stdc++.h>
using namespace std;
double po(double x,int n){
    if(x==0)return 0;
    if(n==1)return x;
    if(n==0)return 1;
    if(n%2==0){
        double t=po(x,n/2);
        return t*t;
    }else{
        double t=po(x,(n-1)/2);
        return t*t*x;
    }
}
int main(){
    int n,m;
    double ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        ans=ans+
        1.0*i*(po(1.0*i/n,m)-po(1.0*(i-1)/n,m));
    }
    printf("%.20f",ans);
    return 0;
}