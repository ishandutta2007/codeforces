#include<bits/stdc++.h>
#define eps 1e-7
using namespace std;
int n,k,res,tmp;
int main(){
    scanf("%d%d",&n,&k);
    res=k;
    for (int i=0;i<n;i++){
        scanf("%d",&tmp);
        res=__gcd(res,tmp);
    }
    printf("%d\n",k/res);
    for (int i=0;i<(k/res);i++) printf("%d ",i*res);
    return 0;
}