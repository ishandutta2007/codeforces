#include<cstdio>
int main(){
    int n;scanf("%d",&n);
    long long g=(1ll+n)*n/2,sum=0,x;
    for(int i=1;i<=n;++i)scanf("%lld",&x),sum+=x;
    for(int i=1;i<=n;++i)printf("%lld ",i+(sum-g)/n+((sum-g)%n>=i));
}