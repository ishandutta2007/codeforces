#include <bits/stdc++.h>
#define maxn 300300
using namespace std;
#define pb push_back
#define pii pair<ll,ll>
#define pip pair<ll,pii>
#define debug 
#define ll long long

pip v[200200];

ll mul(ll a,ll b){
    a %= 476832147;
    b %= 476832147;
    return (a*b) % 476832147;
}

main(){
    int n;
    scanf("%d",&n);
    ll g = 0;
    for(int i=0;i<n;i++)
        scanf("%I64d%I64d%I64d",&v[i].first,&v[i].second.first,&v[i].second.second);
    sort(v,v+n);
    int t = 0;
    while(v[t].first == v[0].first && t < n)
        t++;
    if(n%t){
        printf("0\n");
        return 0;
    }
    ll s0 = 0;
    ll cur = 0;
    for(int i=0;i<n;i++){
        if(i%t == 0){
            cur = 0;
            for(int j=i;j<i+t;j++) cur += v[j].second.second;
            if(i == 0) s0 = cur;
        }
        g = __gcd(g,v[i].second.second);
        if(i < t)
            continue;
        if(v[i].second.first != v[i%t].second.first || mul(cur,v[i%t].second.second) != mul(s0,v[i].second.second)){
            printf("0\n");
            return 0;
        }
    }
    int ans = 0;
    for(ll i=1;i*i<=g;i++)
        if(g%i == 0){
            ans++;
            if(i*i != g)
                ans++;
        }
    printf("%d\n",ans);
}