#include<stdio.h>
inline bool chk(int a){
    if(a<10)return a==4||a==7;
    return chk(a%10)&&chk(a/10);
}
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)if(n%i==0&&chk(i))break;
    if(i<=n)puts("YES");
    else puts("NO");
}