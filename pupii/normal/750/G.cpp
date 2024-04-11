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
ll p2[51];
il int Log2(ll n){
    int ret=0;while(n>1)n>>=1,++ret;
    return ret;
}
std::unordered_map<ll,ll>calced[51][51];
il ll dfs(int a,int b,ll n){
    if(n<0)return 0;
    if(a<b)std::swap(a,b);
    if(a<=0)return!n;
    if(p2[a+1]+p2[b+1]-a-b-4<n)return 0;
    if(calced[a][b].count(n))return calced[a][b][n];
    return calced[a][b][n]=dfs(a-1,b,n)+dfs(a-1,b,n-p2[a]+1);
}
int main(){
    p2[0]=1;for(int i=1;i<=50;++i)p2[i]=p2[i-1]<<1;
    ll n=gi(),ans=0;
    for(ll L=0;L<50;++L)
        for(ll R=0;R<50;++R)
            if(p2[L+1]+3*p2[R]-4<=n){
                ll p=(n-p2[R]+1)/(p2[L+1]+p2[R+1]-3);
                ans+=dfs(L-1,R-1,n-p2[R]+1-p*(p2[L+1]+p2[R+1]-3));
            }
    printf("%lld\n",ans);
    return 0;
}