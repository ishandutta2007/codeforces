

#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define rg register
#define il inline
#define vd void
#define sta static
il int gi(){
    rg int x=0,f=1;rg char ch=getchar();
    while(ch<'0'||ch>'9')f=ch=='-'?-1:f,ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}
using namespace std;
int main(){
    int n=gi(),k=gi(),ans=2e9,x;
    for(rg int i=1;i<=n;++i){
        x=gi();
        if(k%x==0)ans=min(ans,k/x);
    }
    printf("%d\n",ans);
    return 0;
}