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
std::map<int,int>M;
int b[1000010];
main(){
    int T=gi();
    while(T--){
        int n=gi(),m=0;
        M.clear();
        for(int i=1;i<=n;++i){int x=gi();++M[x];}
        for(auto i:M)
            if(i.second>3)b[++m]=i.first,b[++m]=i.first;
            else if(i.second>1)b[++m]=i.first;
        double ans=1e18;int p=0;
        for(int i=1;i<m;++i){
            ll C=b[i]*2+b[i+1]*2,S=b[i]*b[i+1];
            if(ans>(double)C/S*C)p=i,ans=(double)C/S*C;
        }
        printf("%lld %lld %lld %lld\n",b[p],b[p],b[p+1],b[p+1]);
    }
    return 0;
}