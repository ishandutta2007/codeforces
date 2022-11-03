// It is made by XZZ
#include<bits/stdc++.h>
#define int long long
#define il inline
#define rg register
#define vd void
#define sta static
typedef long long ll;
using namespace std;
il int gi(){
    rg int x=0;rg char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x;
}
main(){
    int q=gi();
    while(q--){
        int x=gi(),y=gi(),k=gi(),a=x%2,b=y%2;
        int mn=std::min(x,y),mx=std::max(x,y);
        if(k<mx)puts("-1");
        else{
            k-=mn;
            if(a==b)
                if(k%2==0)printf("%lld\n",k+mn);
                else printf("%lld\n",k+mn-2);
            else printf("%lld\n",k+mn-1);
        }
    }
    return 0;
}