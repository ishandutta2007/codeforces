#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int SN = 1 << 18;
int n;
int arr[N];
int segtree1[SN];
int segtree2[SN];
int ans = 1;
void build(int l , int r , int node){
    int mid = l + r >> 1;
    if(l == r){
        segtree1[node] = segtree2[node] = arr[mid];
    }
    else{
        build(l , mid , node + node);
        build(mid + 1 , r , node + node + 1);
        segtree1[node] = min(segtree1[node + node] , segtree1[node + node + 1]);
        segtree2[node] = max(segtree2[node + node] , segtree2[node + node + 1]);
    }
}
pair < int , int > query(int l , int r , int node , int ql , int qr){
    if(l > qr || r < ql){
        return make_pair(N , -N);
    }
    if(l >= ql && r <= qr){
        return make_pair(segtree1[node] , segtree2[node]);
    }
    int mid = l + r >> 1;
    auto tl = query(l , mid , node + node , ql , qr);
    auto tr = query(mid + 1 , r , node + node + 1 , ql , qr);
    return make_pair(min(tl.first , tr.first) , max(tl.second , tr.second));
}
int curl = 1;
int main(){
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i];
    }
    build(1 , n , 1);
    for(int i = 1 ; i <= n ; ++i){
        auto it = query(1 , n , 1 , curl , i);
        while(it.second - it.first > 1){
            ++curl;
            it = query(1 , n , 1 , curl , i);
        }
        ans = max(ans , i - curl + 1);
    }
    cout << ans;
}