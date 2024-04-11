#include<bits/stdc++.h>
using namespace std;
 
const int maxn=200007;
int n,k,a[maxn];
long long p,ans[maxn];
 

int main(){
    int t;
    scanf("%d",&t);
    while (t--){
        scanf("%d%lld%d",&n,&p,&k);
        for (int i=0;i<n;++i) scanf("%d",&a[i]);
        sort(a,a+n);   
        for (int i=1;i<k;++i) ans[i]=ans[i-1]+a[i-1];
        for (int i=k;i<=n;++i) ans[i]=ans[i-k]+a[i-1];
        int u=0;
        for (int i=1;i<=n;++i) if (ans[i]<=p) u=i;
        printf("%d\n",u);
    }
    return 0;
}