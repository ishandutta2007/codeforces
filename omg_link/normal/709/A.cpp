#include <stdio.h>
int n,b,d,x,r=0,ans=0;
int main(){
    scanf("%d%d%d",&n,&b,&d);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        if(x>b) continue;
        r+=x;
        if(r>d) ans++,r=0;
    }
    printf("%d\n",ans);
}