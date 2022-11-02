#include<bits/stdc++.h>
#define LL long long
#define mo 998244353
using namespace std;
int n,qz[1000010],ny[1000010],ans;
int ksm(int x,int y){
    int res=1;
    while (y){
        if (y&1) res=1LL*res*x%mo;
        x=1LL*x*x%mo;
        y=y>>1;
    }
    return res;
}
int main(){
    scanf("%d",&n);
    qz[0]=1;
    for (int i=1;i<=n;i++) qz[i]=1LL*qz[i-1]*i%mo;
    ny[n]=ksm(qz[n],mo-2);
    for (int i=n;i;i--) ny[i-1]=1LL*ny[i]*i%mo;
    ans=qz[n];
    for (int i=1;i<=n-1;i++) ans=(ans+1LL*qz[n]*ny[n-i]%mo*(qz[n-i]-1))%mo;
    ans=(ans+mo)%mo;
    printf("%d\n",ans);
}