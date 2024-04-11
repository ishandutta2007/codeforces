#include<cstdio>
int main(){int n,x,y,i=2;scanf("%d%d",&n,&x);for(;i<=n;i++){scanf("%d",&y);if((x-y<0?y-x:x-y)>1){return printf("NO\n"),0;}x=y;}printf("YES\n");}