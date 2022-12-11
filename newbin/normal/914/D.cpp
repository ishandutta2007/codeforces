#include<bits/stdc++.h>
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
const int maxn = 5e5 + 50;
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b,a%b);
}
int n;
int a[maxn];
int g[maxn*4];
void build(int rt, int l, int r)
{
    if(l == r){
        g[rt] = a[l];return;
    }
    build(lson);
    build(rson);
    g[rt] = gcd(g[rt<<1], g[rt<<1|1]);
    return;
}
void update(int rt, int l, int r, int i, int x){
    if(l == r) {
        g[rt] = x;return;
    }
    if(i <= mid) update(lson, i, x);
    else update(rson, i, x);
    g[rt] = gcd(g[rt<<1], g[rt<<1|1]);
    return;
}
int cnt = 0;
void query(int rt, int l, int r, int L, int R, int x){
    if(cnt > 1) return;
    if(L <= l && r <= R){
        if(g[rt]%x == 0) return;
        if(l == r){
            cnt++;
        }
        else {
            query(lson, L, R, x);
            query(rson, L, R, x);
        }
        return;
    }
    if(L <= mid) query(lson, L, R, x);
    if(R > mid) query(rson, L, R, x);
    return;
}
void init()
{
    scanf("%d",&n);
    for(int i = 1; i <= n; ++i) scanf("%d",&a[i]);
    build(1, 1, n);
}
void sol()
{
    int q;
    scanf("%d",&q);
    while(q--){
        int op;
        scanf("%d",&op);
        if(op == 1){
            int l, r, x;
            scanf("%d%d%d",&l, &r, &x);
            cnt = 0;
            query(1, 1, n, l, r, x);
            if(cnt <= 1) printf("YES\n");
            else printf("NO\n");
        }
        else {
            int i,x;
            scanf("%d%d",&i, &x);
            update(1, 1, n, i, x);
        }
    }
}
int main(){
    init();sol();
}