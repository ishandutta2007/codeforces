#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    
    int nt;
    scanf("%d",&nt);
    while(nt--){
        ll x,y,p,q;
        scanf("%lld%lld%lld%lld",&x,&y,&p,&q);
        if(p == q){
            if(x == y)
                printf("0\n");
            else
                printf("-1\n");
            continue;
        }
        if(p == 0){
            if(x == 0)
                printf("0\n");
            else
                printf("-1\n");
            continue;
        }
        ll lo = 1, hi = 1e9+100;
        while(lo != hi){
            ll mid = (lo+hi)/2;
            p *= mid;
            q *= mid;
            ll has = q-y, nd = p-x;
            if(nd >= 0 && nd <= has)
                hi = mid;
            else
                lo = mid+1;
            p /= mid;
            q /= mid;
        }
        printf("%lld\n",q*lo-y);
    }
}