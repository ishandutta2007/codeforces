#include<bits/stdc++.h>
#define LL long long
#define mo 1000000007
using namespace std;
LL n,m;
LL get(LL x){
    LL tmp=1;
    for (int i=2;i<=floor(sqrt(x))+1;i++){
        if (x%i==0){
            x/=i;
            tmp*=(i-1);
            while (x%i==0){
                x/=i;
                tmp*=i;
            }
        }
    }
    if (x!=1) tmp*=(x-1);
    return tmp;
}
int main(){
    scanf("%lld%lld",&n,&m);
    m=(m+1)/2;
    for (int i=0;i<m;i++){
        n=get(n);
        if (n==1) break;
    }
    printf("%lld\n",n%mo);
    return 0;
}