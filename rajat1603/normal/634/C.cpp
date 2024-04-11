#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
const int SN = 1 << 19;
int n , k , a , b , q;
int type , di , ai , pi;
int segtree1[SN];
int segtree2[SN];
void update(int l , int r , int node , int idx , int val){
    if(l == r){
        segtree1[node] += val;
        segtree2[node] += val;
        segtree1[node] = min(segtree1[node] , b);
        segtree2[node] = min(segtree2[node] , a);
    }
    else{
        int mid = l + r >> 1;
        if(idx <= mid){
            update(l , mid , node + node , idx , val);
        }
        else{
            update(mid + 1 , r , node + node + 1 , idx , val);
        }
        segtree1[node] = segtree1[node + node] + segtree1[node + node + 1];
        segtree2[node] = segtree2[node + node] + segtree2[node + node + 1];
    }
    //cout << l << " " << r << " " << segtree1[node] << " " << segtree2[node] << endl;
}
int query1(int l , int r , int node , int ql , int qr){
    if(l > qr || r < ql || qr < ql){
        return 0;
    }
    if(l >= ql && r <= qr){
        return segtree1[node];
    }
    int mid = l + r >> 1;
    return query1(l , mid , node + node , ql , qr) + query1(mid + 1 , r , node + node + 1 , ql , qr);
}
int query2(int l , int r , int node , int ql , int qr){
    if(l > qr || r < ql || qr < ql){
        return 0;
    }
    if(l >= ql && r <= qr){
        return segtree2[node];
    }
    int mid = l + r >> 1;
    return query2(l , mid , node + node , ql , qr) + query2(mid + 1 , r , node + node + 1 , ql , qr);
}
int main(){
    scanf("%d %d %d %d %d" , &n , &k , &a , &b , &q);
    for(int i = 1 ; i <= q ; ++i){
        scanf("%d" , &type);
        if(type == 1){
            scanf("%d %d" , &di , &ai);
            update(1 , n , 1 , di , ai);
        }
        else{
            scanf("%d" , &pi);
            int a1 = query1(1 , n , 1 , 1 , pi - 1);
            int a2 = query2(1 , n , 1 , pi + k , n);
            //cout << a1 << " " << a2 << endl;
            printf("%d\n" , a1 + a2);
        }
    }
}