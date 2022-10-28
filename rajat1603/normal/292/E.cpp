#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 1;
const int SN = 1 << 18;
int segtree[SN];
int arr[N + N];
int x[N];
int y[N];
int k[N];
int n , q , type , idx;
void update(int l , int r , int node , int ql , int qr , int val){
    if(l > qr || r < ql){
        return;
    }
    if(l >= ql && r <= qr){
        segtree[node] = val;
        return;
    }
    int mid = (l + r) >> 1;
    int lc = node + node;
    int rc = lc | 1;
    update(l , mid , lc , ql , qr , val);
    update(mid + 1 , r , rc , ql , qr , val);
}
int query(){
    int ans = segtree[1];
    int l = 1;
    int r = n;
    int node = 1;
    int mid;
    while(l ^ r){
        mid = (l + r) >> 1;
        node += node;
        if(idx <= mid){
            r = mid;
        }
        else{
            l = mid + 1;
            node |= 1;
        }
        ans = max(ans , segtree[node]);
    }
    return ans;
}
int main(){
    //cin >> n >> q;
    scanf("%d %d" , &n , &q); //F**k you CF
    for(int i = 1 ; i <= n + n ; ++i){
        scanf("%d" , arr + i); //F**k you CF
        //cin >> arr[i];
    }
    x[0] = n;
    for(int i = 1 ; i <= q ; ++i){
        //cin >> type;
        scanf("%d" , &type); //F**k you CF
        if(type & 1){
            //cin >> x[i] >> y[i] >> k[i];
            scanf("%d %d %d" , x + i , y + i , k + i); //F**k you CF
            update(1 , n , 1 , y[i] , y[i] + k[i] - 1 , i);
        }
        else{
            //cin >> idx;
            scanf("%d" , &idx); //F**k you CF
            type = query();
            cout << arr[x[type] + idx - y[type]] << "\n";
        }
    }
}