#include<stdio.h>
inline bool f(int x){if(x==1)return 0;for(int i=2;i<x;i++)if(x%i==0)return 0;return 1;}
int a,b;
inline int solve(){
    if(!f(a)||!f(b))return 0;
    for(int i=a+1;i<b;i++)if(f(i))return 0;
    return 1;
}
int main(){
    scanf("%d%d",&a,&b);puts(solve()?"YES":"NO");
}