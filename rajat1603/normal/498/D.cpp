#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int SN = 1 << 18;
const int L = 60;
struct data{
    int ans[L];
};
int n;
int arr[N];
data segtree[SN];
int q;
char str[5];
int a , b;
void leaf(data &node , int val){
    for(int i = 0 ; i < L ; ++i){
        if(i % val){
            node.ans[i] = 1;
        }
        else{
            node.ans[i] = 2;
        }
    }
}
void combine(data &cur , const data &lft , const data &rgt){
    for(int i = 0 ; i < L ; ++i){
        cur.ans[i] = rgt.ans[(lft.ans[i] + i) % L] + lft.ans[i];
    }
}
void build(int l , int r , int node){
    if(l == r){
        leaf(segtree[node] , arr[l]);
    }
    else{
        int mid = l + r >> 1;
        build(l , mid , node + node);
        build(mid + 1 , r , node + node + 1);
        combine(segtree[node] , segtree[node + node] , segtree[node + node + 1]);
    }
}
void update(int l , int r , int node , int idx , int val){
    if(l == r){
        leaf(segtree[node] , val);
    }
    else{
        int mid = l + r >> 1;
        if(idx <= mid){
            update(l , mid , node + node , idx , val);
        }
        else{
            update(mid + 1 , r , node + node + 1 , idx , val);
        }
        combine(segtree[node] , segtree[node + node] , segtree[node + node + 1]);
    }
}
int query(int l , int r , int node , int ql , int qr , int cur){
    if(l > qr || r < ql){
        return cur;
    }
    if(l >= ql && r <= qr){
        return cur + segtree[node].ans[cur % L];
    }
    int mid = l + r >> 1;
    return query(mid + 1 , r , node + node + 1 , ql , qr , query(l , mid , node + node , ql , qr , cur));
}
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    build(1 , n , 1);
    scanf("%d" , &q);
    while(q--){
        scanf("%s %d %d" , str , &a , &b);
        if(str[0] == 'A'){
            printf("%d\n" , query(1 , n , 1 , a , b - 1 , 0));
        }
        else{
            update(1 , n , 1 , a , b);
        }
    }
}