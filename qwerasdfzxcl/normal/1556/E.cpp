#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
struct node{
    ll px, sn, sum, mx, mn, l, r, pn, sx;
    node(){}
    node(ll _px, ll _sn, ll _sum, ll _mx, ll _mn, ll _pn, ll _sx): px(_px), sn(_sn), sum(_sum), mx(_mx), mn(_mn), pn(_pn), sx(_sx) {}
};
node combine(node x, node y){
    node ret;

    ret.px = max(x.px, x.sum+y.px);
    ret.pn = min(x.pn, x.sum+y.pn);
    ret.sn = min(y.sn, y.sum+x.sn);
    ret.sx = max(y.sx, y.sum+x.sx);
    ret.sum = x.sum+y.sum;
    ret.mx = max(x.mx, y.mx);
    ret.mn = min(x.mn, y.mn);

    ret.mx = max(ret.mx, x.sx+y.px);
    ret.mn = min(ret.mn, x.sn+y.pn);
    return ret;
}
ll a[100100];
struct Seg{
    node tree[400400];

    void init(int i, int l, int r){
        if (l==r){
            tree[i] = node(a[l], a[l], a[l], a[l], a[l], a[l], a[l]);
            return;
        }
        int m = (l+r)>>1;
        init(i<<1, l, m); init(i<<1|1, m+1, r);
        tree[i] = combine(tree[i<<1], tree[i<<1|1]);
    }
    node query(int i, int l, int r, int s, int e){
        if (r<s || e<l) return node(0, 0, 0, 0, 0, 0, 0);
        if (s<=l && r<=e) return tree[i];
        int m = (l+r)>>1;
        return combine(query(i<<1, l, m, s, e), query(i<<1|1, m+1, r, s, e));
    }
}tree;

int main(){
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i=0;i<n;i++) scanf("%lld", a+i);
    for (int i=0;i<n;i++){
        ll x;
        scanf("%lld", &x);
        a[i] -= x;
    }
    tree.init(1, 0, n-1);
    while(q--){
        int l, r;
        scanf("%d %d", &l, &r);
        auto ans = tree.query(1, 1, n, l, r);
        if (ans.sum!=0 || ans.px>0 || ans.sn<0) printf("-1\n");
        else printf("%lld\n", max(ans.mx, -ans.mn));
    }
    return 0;
}