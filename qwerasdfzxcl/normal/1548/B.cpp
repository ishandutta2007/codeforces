#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
ll a[200200], b[200200];
struct Seg{
    ll tree[400400];
    int sz;
    void init(int n){
        sz = n;
        for (int i=sz+1;i<sz*2;i++) tree[i] = b[i-sz];
        for (int i=sz-1;i;i--) tree[i] = __gcd(tree[i<<1], tree[i<<1|1]);
    }
    ll query(int l, int r){
        ll ret = 0;
        for (l+=sz, r+=sz;l<r;l>>=1, r>>=1){
            if (l&1) ret = __gcd(ret, tree[l++]);
            if (r&1) ret = __gcd(ret, tree[--r]);
        }
        return ret;
    }
}tree;

ll myabs(ll x){
    if (x<0) return -x;
    return x;
}

void solve(){
    int n;
    scanf("%d", &n);
    for (int i=0;i<n;i++) scanf("%lld", a+i);
    for (int i=1;i<n;i++) b[i] = myabs(a[i] - a[i-1]);
    tree.init(n);
    int rans = 1;
    for (int i=1;i<n;i++) if (b[i]!=1) rans = 2;
    for (int i=1;i<n-1;i++){
        int l = i+1, r = n, ans = i;
        while(l<r){
            int m = (l+r)>>1;
            if (tree.query(i, m+1)!=1) ans = m, l = m+1;
            else r = m;
        }
        if (ans!=i) rans = max(rans, ans-i+2);
    }
    printf("%d\n", rans);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}