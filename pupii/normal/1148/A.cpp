#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il ll gi(){
    ll x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch))f^=ch=='-',ch=getchar();
    while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
    return f?x:-x;
}
int main(){
int a=gi(),b=gi(),c=gi(),d=std::min(a,b);
printf("%lld\n",0ll+c*2+d*2+std::min(1,a-d)+std::min(1,b-d)); 
    return 0;
}