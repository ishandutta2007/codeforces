#include<bits/stdc++.h>
#define N 1000009
using namespace std;

int n,b[N]; vector<int> a[N];
int main(){
    scanf("%d",&n);
    int i,mx=0;
    for (i=1; i<=n; i++){
        int t; scanf("%d",&t);
        while (t--){
            int x;
            scanf("%d",&x); a[i].push_back(x); b[i]=max(b[i],x);
        }
        mx=max(mx,b[i]);
    }
    long long ans=0;
    for (i=1; i<=n; i++) ans+=(long long)(mx-b[i])*a[i].size();
    printf("%lld\n",ans);
    return 0;
}