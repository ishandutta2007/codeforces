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
int a[300010],b[300010];
main(){
    int n=gi(),S1=0;
    for(int i=1;i<=n;++i)a[i]=gi(),S1+=a[i];
    int m=gi(),S2=0;
    for(int i=1;i<=m;++i)b[i]=gi(),S2+=b[i];
    int x=1,y=1,ans=0,sum1=0,sum2=0;
    while(x<=n&&y<=m){
        if(sum1&&sum1==sum2)++ans,sum1=sum2=0;
        else if(sum1<sum2)sum1+=a[x++];
        else sum2+=b[y++];
    }
    if(S1!=S2)puts("-1");
    else printf("%lld\n",ans+1);
    return 0;
}