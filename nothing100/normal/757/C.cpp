#include<bits/stdc++.h>
#define MAXN 1000010
#define LL long long
#define mo1 1000000007LL
#define mo2 1000000003LL
#define mo3 233333333LL
#define jz1 239641LL
#define jz2 100007LL
#define jz3 438437LL
using namespace std;
struct has{
    LL hash1,hash2,hash3;
}h[MAXN];
int n,m;
LL a1,a2,a3,ans;
int cmp(has x,has y){
    if (x.hash1==y.hash1){
        if (x.hash2==y.hash2) return x.hash3<y.hash3;
        else return x.hash2<y.hash2;
    }
    else return x.hash1<y.hash1;
}
int main(){
    scanf("%d%d",&n,&m);
    a1=1;
    a2=1;
    a3=1;
    ans=1;
    for (int i=1;i<=n;i++){
        int tmp,tmpp;
        scanf("%d",&tmp);
        for (int j=0;j<tmp;j++){
            scanf("%d",&tmpp);
            tmpp--;
            h[tmpp].hash1=(h[tmpp].hash1+a1)%mo1;
            h[tmpp].hash2=(h[tmpp].hash2+a2)%mo2;
            h[tmpp].hash3=(h[tmpp].hash3+a3)%mo3;
        }
        a1=(a1*jz1)%mo1;
        a2=(a2*jz2)%mo2;
        a3=(a3*jz3)%mo3;
    }
    sort(h,h+m,cmp);
    int l=0,r;
    while (l<m){
        r=l;
        LL tmp=1;
        while ((r+1<m)&&(h[r+1].hash1==h[l].hash1)&&(h[r+1].hash2==h[l].hash2)&&(h[r+1].hash3==h[l].hash3)){
            r++;
            tmp=(tmp*(r-l+1))%mo1;
        }
        ans=(ans*tmp)%mo1;
        l=r+1;
    }
    printf("%I64d\n",ans);
}