#include <bits/stdc++.h>

using namespace std;

#define ll long long

int get_depth(ll v) {
    for (int i = 63; i >= 0; i--) {
        if (v & (1LL << i)) {
            return i;
        }
    }
    
    return 0;
}

map<pair<ll, ll>, ll> add;

int main() {
    int q;
    scanf("%d", &q);
    
    for (int i = 0; i < q; i++) {
        int t;
        scanf("%d", &t);
        
        if (t == 1) {
            ll u, v, w;
            scanf("%lld%lld%lld", &u, &v, &w);
            
            int du = get_depth(u);
            int dv = get_depth(v);
            
            while (u != v) {
                if (du < dv) {
                    swap(u, v);
                    swap(du, dv);
                }
                
                add[{u, u / 2}] += w;
                u /= 2;
                du--;
            }
        } else {
            ll u, v;
            scanf("%lld%lld", &u, &v);
            
            int du = get_depth(u);
            int dv = get_depth(v);
            
            ll ans = 0;
            
            while (u != v) {
                if (du < dv) {
                    swap(u, v);
                    swap(du, dv);
                }
                
                ans += add[{u, u / 2}];
                u /= 2;
                du--;
            }
            
            printf("%lld\n", ans);
        }
    }
    
    return 0;
}