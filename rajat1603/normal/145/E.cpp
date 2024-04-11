#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
const int SN = 1 << 21;
int n , m;
char arr[N];
char type[8];
int l , r;
struct data{
    int cnt0;
    int cnt1;
    int ans1;
    int ans2;
    data(int _cnt0 = 0 , int _cnt1 = 0 , int _ans1 = 0 , int _ans2 = 0){
        cnt0 = _cnt0;
        cnt1 = _cnt1;
        ans1 = _ans1;
        ans2 = _ans2;
    }
    void combine(const data &l , const data &r){
        cnt0 = l.cnt0 + r.cnt0;
        cnt1 = l.cnt1 + r.cnt1;
        ans1 = max(l.ans1 + r.cnt1 , l.cnt0 + r.ans1);
        ans2 = max(l.cnt1 + r.ans2 , l.ans2 + r.cnt0);
    }
};
data segtree[SN];
bool lazy[SN];
void push(int l , int r , int node){
    if(lazy[node]){
        swap(segtree[node].cnt0 , segtree[node].cnt1);
        swap(segtree[node].ans1 , segtree[node].ans2);
        if(l != r){
            lazy[node + node] ^= 1;
            lazy[node + node + 1] ^= 1;
        }
        lazy[node] = 0;
    }
}
void build(int l , int r , int node){
    if(l == r){
        segtree[node] = data(arr[l] == '4' , arr[r] == '7' , 1 , 1);
    }
    else{
        int mid = l + r >> 1;
        build(l , mid , node + node);
        build(mid + 1 , r , node + node + 1);
        segtree[node].combine(segtree[node + node] , segtree[node + node + 1]);
    }
}
void update(int l , int r , int node , int ql , int qr){
    push(l , r , node);
    if(l > qr || r < ql){
        return;
    }
    if(l >= ql && r <= qr){
        lazy[node] = 1;
        push(l , r , node);
        return;
    }
    int mid = l + r >> 1;
    update(l , mid , node + node , ql , qr);
    update(mid + 1 , r , node + node + 1 , ql , qr);
    segtree[node].combine(segtree[node + node] , segtree[node + node + 1]);
}
int main(){
    scanf("%d %d" , &n , &m);
    scanf("%s" , arr + 1);
    build(1 , n , 1);
    while(m--){
        scanf("%s" , type);
        if(type[0] == 'c'){
            printf("%d\n" , segtree[1].ans1);
        }
        else{
            scanf("%d %d" , &l , &r);
            update(1 , n , 1 , l , r);
        }
    }
}