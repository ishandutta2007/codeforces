#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
const int SN = 1 << 19;
const long long inf = 1e16;
int d , n , m;
pair < int , long long > arr[N];
pair < long long , int > segtree[SN];
void build(int l , int r , int node){
    if(l == r){
        segtree[node] = make_pair(arr[l].second , r);
    }
    else{
        int mid = l + r >> 1;
        build(l , mid , node + node);
        build(mid + 1 , r , node + node + 1);
        segtree[node] = min(segtree[node + node] , segtree[node + node + 1]);
    }
}
pair < long long , int > query(int l , int r , int node , int ql , int qr){
    if(l > qr || r < ql || qr < ql){
        return make_pair(inf , 0);
    }
    if(l >= ql && r <= qr){
        return segtree[node];
    }
    int mid = l + r >> 1;
    auto x1 = query(l , mid , node + node , ql , qr);
    auto x2 = query(mid + 1 , r , node + node + 1 , ql , qr);
    return min(x1 , x2);
}
long long solve(int l, int r){
    int x1 = arr[l].first;
    int x2 = arr[r].first;
    if(x2 - x1 <= n){
        return 0;
    }
    auto idx = query(1 , m , 1 , l + 1 , r - 1);
    if(idx.first >= inf){
        return inf;
    }
    long long res = 0;
    long long val = 0;
    if(arr[idx.second].first - x1 <= n){
        val = n - (arr[idx.second].first - x1);
    }
    else{
        res += solve(l , idx.second);
    }
    if(x2 - arr[idx.second].first <= n){
        res += max(0LL , (x2 - arr[idx.second].first - val) * idx.first);
    }
    else{
        res += (n - val) * idx.first;
        res += solve(idx.second , r);
    }
    return res;
}
int main(){
    scanf("%d %d %d" , &d , &n , &m);
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d %lld" , &arr[i].first , &arr[i].second);
    }
    arr[0] = make_pair(0 , 1e9);
    arr[m + 1] = make_pair(d , 1e9);
    sort(arr + 1 , arr + 1 + m);
    build(1 , m , 1);
    long long ans = solve(0 , m + 1);
    if(ans >= inf){
        ans = -1;
    }
    cout << ans;
}