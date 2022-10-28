#include "bits/stdc++.h"
using namespace std;
const int N = 3e5 + 5;
const int SN = 1 << 20;
struct data{
    int ans;
    bool pre;
    bool suf;
    data(){
        ans = 0;
        pre = 0;
        suf = 0;
    }
};
int n , q;
char str[N] = {NULL};
data segtree[SN];
data combine(data &l , data &r){
    data ret;
    ret.ans = l.ans + r.ans;
    ret.pre = l.pre;
    ret.suf = r.suf;
    if(l.suf && r.pre){
        ++ret.ans;
    }
    return ret;
}
void build(int l , int r , int node){
    if(l == r){
        if(str[l] == '.'){
            segtree[node].pre = 1;
            segtree[node].suf = 1;
        }
    }
    else{
        int mid = l + r >> 1;
        int lc = node + node;
        int rc = lc | 1;
        build(l , mid , lc);
        build(mid + 1 , r , rc);
        segtree[node] = combine(segtree[lc] , segtree[rc]);
    }
}
void update(int l , int r , int node , int idx ,  char val){
    if(l == r){
        if(val == '.'){
            segtree[node].ans = 0;
            segtree[node].pre = 1;
            segtree[node].suf = 1;
        }
        else{
            segtree[node].ans = 0;
            segtree[node].pre = 0;
            segtree[node].suf = 0;
        }
    }
    else{
        int mid = l + r >> 1;
        int lc = node + node;
        int rc = lc | 1;
        if(idx <= mid){
            update(l , mid , lc , idx , val);
        }
        else{
            update(mid + 1 , r , rc , idx , val);
        }
        segtree[node] = combine(segtree[lc] , segtree[rc]);
    }
}
int main(){
    scanf("%d %d" , &n , &q);
    scanf("%s" , str + 1);
    build(1 , n , 1);
    while(q--){
        int idx;
        char ar[5] = {NULL};
        scanf("%d %s" , &idx , ar);
        update(1 , n , 1 , idx , ar[0]);
        printf("%d\n" , segtree[1].ans);
    }
}