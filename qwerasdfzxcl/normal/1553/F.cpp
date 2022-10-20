#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
struct Seg1{
    ll lazy[600600];
    int sz;
    void init(int n) {sz = n;}
    void update(int l, int r, ll x){
        for (l += sz, r += sz;l<r;l>>=1, r>>=1){
            if (l&1) lazy[l++] += x;
            if (r&1) lazy[--r] += x;
        }
    }
    ll query(int x){
        ll ret = 0;
        for (x+=sz;x;x>>=1) ret += lazy[x];
        return ret;
    }
}tree1;
struct Seg2{
    ll tree[600600];
    int sz;
    void init(int n) {sz = n;}
    void update(int x, ll val){
        for (tree[x+=sz]+=val;x>1;x>>=1) tree[x>>1] = tree[x]+tree[x^1];
    }
    ll query(int l, int r){
        ll ret = 0;
        for (l+=sz, r+=sz;l<r;l>>=1, r>>=1){
            if (l&1) ret += tree[l++];
            if (r&1) ret += tree[--r];
        }
        return ret;
    }
}tree2;
int a[200200];

int main(){
    int n;
    scanf("%d", &n);
    for (int i=0;i<n;i++) scanf("%d", a+i);
    tree1.init(300300);
    tree2.init(300300);
    ll ans = 0, sum = 0;
    for (int i=0;i<n;i++){
        sum += a[i];
        for (int j=1;a[i]*j<300300;j++){
            tree1.update(a[i]*j, min(a[i]*(j+1), 300300), (ll)a[i]*j);
        }
        tree2.update(a[i], 1);
        ans += tree1.query(a[i]);
        for (int j=1;a[i]*j<300300;j++){
            ans += tree2.query(a[i]*j, min(a[i]*(j+1), 300300))*a[i]*j;
        }
        ans -= a[i];
        printf("%lld ", sum*(i+1)-ans);
    }
    return 0;
}