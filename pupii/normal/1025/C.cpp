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
char S[200010];
int mx[200010];
main(){
    scanf("%s",S+1);
    int n=strlen(S+1);
    for(int i=1;i<=n;++i)S[i+n]=S[i];
    mx[1]=1;
    for(int i=2;i<=n*2;++i){
        if(S[i-1]!=S[i])mx[i]=mx[i-1]+1;
        else mx[i]=1;
    }
    int ans=0;
    for(int i=1;i<=n*2;++i)ans=std::max(ans,mx[i]);
    printf("%lld\n",std::min(ans,n));
    return 0;
}