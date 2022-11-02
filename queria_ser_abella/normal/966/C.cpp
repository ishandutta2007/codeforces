#include <bits/stdc++.h>
#define maxn 300300
using namespace std;
#define pb push_back
#define pii pair<ll,ll>
#define pip pair<ll,pii>
#define debug
#define ll long long

ll v[maxn];
ll ans[maxn];
ll aux[maxn];

int up(ll x){
    int t = 0;
    while(x){
        x /= 2;
        t++;
    }
    return t;
}

main(){
    
    int n;
    scanf("%d",&n);
    
    for(int i=0;i<n;i++){
        scanf("%I64d",v+i);
    }
    
    sort(v,v+n);
    reverse(v,v+n);
    
    int cur = 0;
        
    for(int i=0;i<n;i++){
        if(i > 0 && up(v[i]) == up(v[i-1]))
            continue;
        int u = i;
        while(u < n && up(v[u]) == up(v[i]))
            u++;
        debug("%d ~ %d\n",i,u-1);
        ll x = 0;
        
        int pa = 0, pb = i, sz = 0;
        while(pa < i || pb < u){
            if(pa == i){
                x ^= v[pb];
                aux[sz++] = v[pb++];
            }
            else if(pb == u){
                x ^= ans[pa];
                aux[sz++] = ans[pa++];
            }
            else if((x^v[pb]) > x){
                x ^= v[pb];
                aux[sz++] = v[pb++];
            }
            else {
                x ^= ans[pa];
                aux[sz++] = ans[pa++];
            }
        }
        
        for(int j=0;j<sz;j++){
            debug("%lld ",aux[j]);
            ans[j] = aux[j];
        }
        debug("\n");
        
    }

    ll xx = 0;
    for(int i=0;i<n;i++){
        if((xx^ans[i]) < xx){
            printf("No\n");
            return 0;
        }
        xx ^= ans[i];
    }
    
    printf("Yes\n");
    
    for(int i=0;i<n;i++)
        printf("%I64d ",ans[i]);
        
}