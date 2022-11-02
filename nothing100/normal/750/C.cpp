#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,lev[200000],ch[200000];
LL x,y;
int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d%d",&ch[i],&lev[i]);
    y=1000000000000000LL;
    x=-y;
    for (int i=0;i<n;i++){
        if (lev[i]==1) x=max(1900LL,x);
        else y=min(y,1899LL);
        if (x>y){
            printf("Impossible\n");
            return 0;
        }
        y+=ch[i];
        x+=ch[i];
    }
    if (y>100000000000000LL) printf("Infinity\n");
    else printf("%lld\n",y);
}