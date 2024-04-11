#include "bits/stdc++.h"
using namespace std;
const int N = 3e5 + 5;
const int inf = 1e9 + 9;
const int SN = 1 << 20;
int n;
int arr[N];
int m;
int l , r , d;
struct data{
    long long lft;
    long long rgt;
    int ans;
    int sz;
    int preinc;
    bool preincrekt;
    int predec;
    int sufinc;
    int sufdec;
    bool sufdecrekt;
};
data segtree[SN];
long long lazy[SN];
data combine(data l , data r){
    data res;
    res.lft = l.lft;
    res.rgt = r.rgt;
    res.ans = max(l.ans , r.ans);
    res.preinc = l.preinc;
    res.predec = l.predec;
    res.sufinc = r.sufinc;
    res.sufdec = r.sufdec;
    res.preincrekt = l.preincrekt;
    res.sufdecrekt = r.sufdecrekt;
    res.sz = l.sz + r.sz;
    if(r.lft > l.rgt){
        res.ans = max(res.ans , l.sufinc + r.preinc);
        res.ans = max(res.ans , l.sufinc + r.predec);
    }
    if(l.rgt > r.lft){
        res.ans = max(res.ans , l.sufdec + r.predec);
        res.ans = max(res.ans , l.sufinc + r.predec);
    }
    if(l.preinc == l.sz){
        if(r.lft > l.rgt && (!l.preincrekt)){
            res.preinc = l.preinc + r.preinc;
            res.preincrekt = r.preincrekt;
        }
        if(l.preincrekt && r.lft < l.rgt){
            res.preinc = l.preinc + r.predec;
        }
        if(!l.preincrekt && r.lft < l.rgt){
            res.preincrekt = 1;
            res.preinc = l.preinc + r.predec;
        }
    }
    if(l.predec == l.sz){
        if(r.lft < l.rgt){
            res.predec = l.predec + r.predec;
        }
    }
    if(r.sufinc == r.sz){
        if(l.rgt < r.lft){
            res.sufinc = r.sufinc + l.sufinc;
        }
    }
    if(r.sufdec == r.sz){
        if(l.rgt > r.lft && (!r.sufdecrekt)){
            res.sufdec = r.sufdec + l.sufdec;
            res.sufdecrekt = l.sufdecrekt;
        }
        if(r.sufdecrekt && l.rgt < r.lft){
            res.sufdec = r.sufdec + l.sufinc;
        }
        if(!r.sufdecrekt && l.rgt < r.lft){
            res.sufdecrekt = 1;
            res.sufdec = r.sufdec + l.sufinc;
        }
    }
    return res;
}
//prefix decreasing normal , suffix increasing normal
void build(int l , int r , int node){
    lazy[node] = 0;
    if(l == r){
        segtree[node].lft = arr[l];
        segtree[node].rgt = arr[r];
        segtree[node].ans = 1;
        segtree[node].preinc = 1;
        segtree[node].sufinc = 1;
        segtree[node].predec = 1;
        segtree[node].sufdec = 1;
        segtree[node].sz = 1;
        segtree[node].preincrekt = 0;
        segtree[node].sufdecrekt = 0;
    }
    else{
        int mid = l + r >> 1;
        build(l , mid , node + node);
        build(mid + 1 , r , node + node + 1);
        segtree[node] = combine(segtree[node + node] , segtree[node + node + 1]);
    }
}
void push(int l , int r , int node){
    if(lazy[node]){
        segtree[node].lft += lazy[node];
        segtree[node].rgt += lazy[node];
        if(l != r){
            lazy[node + node] += lazy[node];
            lazy[node + node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}
void update(int l , int r , int node , int ql , int qr , int val){
    push(l , r , node);
    if(l > qr || r < ql){
        return;
    }
    if(l >= ql && r <= qr){
        lazy[node] += val;
        push(l , r , node);
        return;
    }
    int mid = l + r >> 1;
    update(l , mid , node + node , ql , qr , val);
    update(mid + 1 , r , node + node + 1 , ql , qr , val);
    segtree[node] = combine(segtree[node + node] , segtree[node + node + 1]);
}
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    build(1 , n , 1);
    scanf("%d" , &m);
    while(m--){
        scanf("%d %d %d" , &l , &r , &d);
        update(1 , n , 1 , l , r , d);
        printf("%d\n" , segtree[1].ans);
    }
}