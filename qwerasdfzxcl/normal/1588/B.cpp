#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

ll query(int i, int j){
    printf("? %d %d\n", i, j);
    fflush(stdout);
    ll ret;
    scanf("%lld", &ret);
    return ret;
}

void ans(int i, int j, int k){
    printf("! %d %d %d\n", i, j, k);
    fflush(stdout);
}

ll Tri(ll x){
    if (x<=0) return -1;
    ll l = 1, r = 1e9+10;
    while(l<=r){
        ll m = (l+r)>>1;
        if (m*(m+1)/2==x) return m;
        else if (m*(m+1)/2<x) l = m+1;
        else r = m-1;
    }
    return -1;
}

ll my_sqrt(ll x){
    if (x==0) return 0;
    ll l = 1, r = 1e9+10;
    while(l<=r){
        ll m = (l+r)>>1;
        if (m*m==x) return m;
        else if (m*m<x) l = m+1;
        else r = m-1;
    }
    exit(1);
}

pair<ll, ll> solve2(ll b, ll c){
    ll tmp = my_sqrt(b*b-c*4);
    return {(-b-tmp)/2, (-b+tmp)/2};
}

void solve(){
    int n;
    scanf("%d", &n);
    ll mx = query(1, n);
    int l = 2, r = n-1, idx = -1;
    while(l<=r){
        int m = (l+r)>>1;
        ll q = query(1, m);
        if (Tri(q)!=-1 && q<mx) l = m+1, idx = m;
        else if (q==0) l = m+1;
        else r = m-1;
    }
    assert(idx!=-1);
    ll val = query(1, idx);
    ll val2 = query(1, idx-Tri(val)-1);

    if (val2==0){
        ans(idx-Tri(val)-1, idx, idx+Tri(mx-val));
    }
    else{
        int i = (idx-Tri(val)-1) - Tri(val2);
        ll len = idx-i+1;
        auto p = solve2(-(len), (ll)len*(len-1)/2-val);

        int j = i+p.second;
        if (query(1, j)!=p.second*(p.second-1)/2) j = i+p.first;

        ll tmp = query(1, j);
        ans(i, j, j+Tri(mx-tmp));
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}