#include<stdio.h>
int c[5];
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        int a;
        scanf("%d",&a);
        c[a]++;
    }
    int ans=c[4];
    ans+=c[3];
    if(c[3]<=c[1])c[1]-=c[3];
    else c[1]=0;
    ans+=c[2]/2;
    c[2]%=2;
    if(c[2]){
        ans+=c[2];
        if(c[1]>=2)c[1]-=2;
        else c[1]=0;
    }
    ans+=(c[1]+3)/4;
    printf("%d\n",ans);
}