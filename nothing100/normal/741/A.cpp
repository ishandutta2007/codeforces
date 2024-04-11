#include<bits/stdc++.h>
#define MAXN 200010
#define inf 1e+15
using namespace std;
int n,a[110],vis[110];
long long ans;
long long gcd(long long x,long long y){
    if (y==0) return x;
    return gcd(y,x%y);
}
int find(int x,int y){
    if (vis[x]){
        if (x==y) return 1;
        return -1;
    }
    vis[x]=1;
    int tmp=find(a[x],y);
    if (tmp==-1) return -1;
    return tmp+1;
}
int main(){
    scanf("%d",&n);
    ans=1;
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++)
    if (!vis[i]){
        vis[i]=1;
        long long tmp=find(a[i],i);
        if (tmp==-1){
            printf("%d\n",-1);
            return 0;
        }
        if (!(tmp&1)) tmp/=2;
        ans=ans*tmp/gcd(ans,tmp);
    }
    printf("%lld\n",ans);
    return 0;
}