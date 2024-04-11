#include<bits/stdc++.h>
#define il inline
#define vd void
#define int long long
#define ll long long
il int gi(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}
main(){
    ll a=gi(),b=gi(),c=gi(),d=gi(),g=std::__gcd(c,d);
    c/=g,d/=g;
    printf("%lld\n",std::min(a/c,b/d));
    return 0;
}