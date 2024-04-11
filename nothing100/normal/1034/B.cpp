#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,m;
LL ans;
int main(){
    scanf("%d%d",&n,&m);
    if (n>m) swap(n,m);
    if (n==1){
        if (m%6==4) printf("%d\n",m-2);
        else if (m%6==5) printf("%d\n",m-1);
        else printf("%d\n",m/6*6);
    }
    else if (n==2){
        if (m==2) printf("0\n");
        else if (m==3||m==7) printf("%lld\n",1LL*n*m-2);
        else printf("%lld\n",1LL*n*m);
    }
    else printf("%lld\n",1LL*n*m-(1LL*n*m)%2);
}