#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL n,l,r,k,res;
LL fmi(LL x,LL y){
    return (n+x)*y+(r-l+1)+max(0LL,x-n+(r-l+1)-1);
}
LL fma(LL x,LL y){
    //printf("%lld %lld %lld\n",x,y,(n+x)*y+(r-l+1)+min(x,r-l+1));
    return (n+x)*y+(r-l+1)+min(x,r-l+1);
}
int main(){
    scanf("%lld%lld%lld%lld",&n,&l,&r,&k);
    res=-1;
    if (r<l) r+=n;
    if (n<=1000000){
        for (int i=0;i<=n;i++){
            LL tmp=k%(n+i);
            if (tmp==0) tmp=n+i;
            //printf("%d %lld\n",i,tmp);
            if (tmp>=r-l+1+max(0LL,i-n+(r-l+1)-1)&&tmp<=r-l+1+min(1LL*i,r-l+1)) res=i;
        }
    }
    else{
        for (int i=0;i<=k/n;i++){
            LL l1,r1,l2,r2,c1,c2,mid;
            l1=l2=0;r1=r2=n;
            c1=-1; c2=n+1;
            while (l1<=r1){
                mid=(l1+r1)>>1;
                if (fmi(mid,i)<=k){
                    c1=mid;
                    l1=mid+1;
                }
                else r1=mid-1;
            }
            while (l2<=r2){
                mid=(l2+r2)>>1;
                //printf("%lld\n",fma(mid,i)); 
                if (fma(mid,i)>=k){
                    c2=mid;
                    r2=mid-1;
                }
                else l2=mid+1;
            }
            //printf("%d %lld %lld\n",i,c1,c2);
            if (c2<=c1) res=max(res,c1);
        }
    }
    printf("%lld\n",res);
}