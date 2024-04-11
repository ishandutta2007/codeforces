#include<bits/stdc++.h>
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
const int maxn = 2e5 + 50;
struct node{
    int op;
    int l,r,t;
    bool operator < (const node& x) const{
        if(l!=x.l) return l < x.l;
        return op < x.op;
    }
}e[maxn];
int cc[maxn];
int cnt = 0;
int n, m;
int last[maxn];
void init(){
    scanf("%d%d", &n, &m);
    cnt = 0;
    for(int i = 1; i <= n; ++i){
        e[i].op = -i;
        scanf("%d%d%d",&e[i].l, &e[i].r, &e[i].t);
        cc[++cnt] = e[i].t;
        last[i] = e[i].r;
    }
    for(int i = n+1; i <= n + m; ++i){
        e[i].op = i - n;
        scanf("%d%d%d",&e[i].l, &e[i].r, &e[i].t);
        cc[++cnt] = e[i].t;
    }
    sort(cc+1, cc+cnt+1);
    cnt = unique(cc+1, cc+cnt+1) - cc - 1;
}
int mx[maxn*4];
void up(int rt){
    int lid = mx[rt<<1];
    int rid = mx[rt<<1|1];
    if(lid == -1) mx[rt] = rid;
    else if(rid == -1) mx[rt] = lid;
    else if(last[lid] < last[rid]) mx[rt] = rid;
    else mx[rt] = lid;
    return;
}
void update(int rt, int l, int r, int pos, int id){
    if(l == r){
        if(mx[rt] == -1 || last[mx[rt]] < last[id]) mx[rt] = id;
        return;
    }
    if(pos <= mid) update(lson, pos, id);
    else update(rson, pos, id);
    up(rt);
}
int query(int rt, int l, int r, int pos, int val){
    if(mx[rt] == -1 || last[mx[rt]] < val) return -1;
    if(l == r){
        return mx[rt];
    }
    int ans = -1;
    if(pos <= mid) ans = query(lson, pos, val);
    if(ans != -1) return ans;
    return query(rson, pos, val);
}
int ans[maxn];
void sol(){
    memset(mx,-1,sizeof mx);
    sort(e+1,e+n+m+1);
    for(int i = 1; i <= n + m; ++i){
        //cout<<"op:"<<e[i].op<<endl;
        if(e[i].op > 0){
            int l = lower_bound(cc+1, cc+1+cnt, e[i].t) - cc;
            ans[e[i].op] = query(1, 1, cnt, l, e[i].r);
        }
        else{
            int id = -e[i].op;
            int l = lower_bound(cc+1, cc+1+cnt, e[i].t) - cc;
            update(1, 1, cnt, l, id);
        }
    }
    for(int i = 1; i <= m; ++i) printf("%d ",ans[i]);
}
int main(){
    init();sol();
}