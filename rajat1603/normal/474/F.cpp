#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int SN = 1 << 18;
struct data{
    int val;
    int cnt;
    data(int _val = 0 , int _cnt = 0){
        val = _val;
        cnt = _cnt;
    }
};
data combine(data a , data b){
    data res;
    res.val = __gcd(a.val , b.val);
    if(a.val == res.val){
        res.cnt += a.cnt;
    }
    if(b.val == res.val){
        res.cnt += b.cnt;
    }
    return res;
}
data segtree[SN];
int n;
int arr[N];
int q;
int l , r;
void build(int l , int r , int node){
    if(l == r){
        segtree[node] = data(arr[l] , 1);
    }
    else{
        int mid = l + r >> 1;
        build(l , mid , node + node);
        build(mid + 1 , r , node + node + 1);
        segtree[node] = combine(segtree[node + node] , segtree[node + node + 1]);
    }
}
data query(int l , int r , int node , int ql , int qr){
    if(l > qr || r < ql){
        return data();
    }
    if(l >= ql && r <= qr){
        return segtree[node];
    }
    int mid = l + r >> 1;
    return combine(query(l , mid , node + node , ql , qr) , query(mid + 1 , r , node + node + 1 , ql , qr));
}
int main(){
    scanf("%d", &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    build(1 , n , 1);
    scanf("%d" , &q);
    while(q--){
        scanf("%d %d" , &l , &r);
        printf("%d\n" , r - l + 1 - query(1 , n , 1 , l , r).cnt);
    }
}