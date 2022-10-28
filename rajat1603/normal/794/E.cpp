#include "bits/stdc++.h"
using namespace std;
const int N = 3e5 + 5;
const int SN = 1 << 20;
int n;
int arr[N];
int val1[N];
int val2[N];
pair < int , int > segtree[SN];
pair < int , int > combine(pair < int , int > a , pair < int , int > b){
    return {max(a.first , b.first) , max(a.second , b.second)};
}
void build(int l , int r , int node){
    if(l == r){
        segtree[node] = {val1[l] , val2[r]};
    }
    else{
        int mid = l + r >> 1;
        build(l , mid , node + node);
        build(mid + 1 , r , node + node + 1);
        segtree[node] = combine(segtree[node + node] , segtree[node + node + 1]);
    }
}
pair < int , int > query(int l , int r , int node , int ql , int qr){
    if(l > qr || r < ql){
        return {0 , 0};
    }
    if(l >= ql && r <= qr){
        return segtree[node];
    }
    int mid = l + r >> 1;
    return combine(query(l , mid , node + node , ql , qr) , query(mid + 1 , r , node + node + 1 , ql , qr));
}
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    for(int i = 1 ; i <= n ; ++i){
        val1[i] = max(arr[i] , arr[i + 1]);
    }
    for(int i = 1 ; i <= n ; ++i){
        val2[i] = min(arr[i] , max(arr[i - 1] , arr[i + 1]));
    }
    build(1 , n , 1);
    for(int k = 0 ; k < n ; ++k){
        int siz = n - k;
        if(siz == 1){
            printf("%d\n" , *max_element(arr + 1 , arr + 1 + n));
        }
        else{
            if(siz & 1){
                printf("%d " , query(1 , n , 1 , siz + 1 >> 1 , n - siz + 1 + n >> 1).second);
            }
            else{
                printf("%d " , query(1 , n , 1 , siz + 1 >> 1 , n - siz + 1 + n >> 1).first);
            }
        }
    }
}