#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
const int SN = 1 << 21;
struct node{
    int ans;
    int pre;
    int suf;
    node(){
        ans = 0;
        pre = 0;
        suf = 0;
    }
};
int n;
char str[N];
int q;
int l , r;
node segtree[SN];
node combine(const node &l , const node &r){
    node ret;
    ret.ans = l.ans + r.ans + (min(l.pre , r.suf) << 1);
    ret.pre = l.pre + r.pre - min(l.pre , r.suf);
    ret.suf = l.suf + r.suf - min(l.pre , r.suf);
    return ret;
}
void build(int l , int r , int node){
    if(l == r){
        if(str[l] == '('){
            segtree[node].pre = 1;
        }
        else{
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
node query(int l , int r , int nod , int ql , int qr){
    if(l > qr || r < ql){
        return node();
    }
    if(l >= ql && r <= qr){
        return segtree[nod];
    }
    int mid = l + r >> 1;
    int lc = nod + nod;
    int rc = lc | 1;
    return combine(query(l , mid , lc , ql , qr) , query(mid + 1 , r , rc , ql , qr));
}
int main(){
    scanf("%s" , str + 1);
    n = strlen(str + 1);
    build(1 , n , 1);
    scanf("%d" , &q);
    while(q--){
        scanf("%d %d" , &l , &r);
        printf("%d\n" , query(1 , n , 1 , l , r).ans);
    }
}