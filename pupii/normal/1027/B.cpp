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
    rg int x=0,f=1;rg char ch=getchar();
    while(ch<'0'||ch>'9')f=ch=='-'?-1:f,ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}
main(){
    int n=gi(),q=gi();
    if(n%2==0)
        while(q--){
        int x=gi(),y=gi();
            if((x+y)%2==0)printf("%lld\n",(n/2)*(x-1)+(y+1)/2);
            else printf("%lld\n",(n*n)/2+(n/2)*(x-1)+(y+1)/2);
        }
    else 
        while(q--){
            int x=gi(),y=gi();
            if((x+y)%2==0)
                if(x%2==0)printf("%lld\n",(x/2-1)*n+n/2+y/2+1);
                else printf("%lld\n",(x/2)*n+y/2+1);
            else
                if(x%2==0)printf("%lld\n",(n*n/2)+(x/2-1)*n+n/2+y/2+2);
                else printf("%lld\n",(n*n/2)+(x/2)*n+y/2+1);
        }
    return 0;
}