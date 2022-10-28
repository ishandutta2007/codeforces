#include "bits/stdc++.h"
using namespace std;
const int N = 3e5 + 5;
const int K = 1e6 + 6;
int n;
int k;
int counter = 0;
long long ans = 0;
int arr[N];
int sum[N];
int segtree[1 << 20];
vector < int > pos[K];
vector < pair < int , int > > Q[N];
void build(int l , int r , int node){
    if(l == r){
        segtree[node] = l;
        return;
    }
    int mid = l + r >> 1;
    build(l , mid , node + node);
    build(mid + 1 , r , node + node + 1);
    if(arr[segtree[node + node]] > arr[segtree[node + node + 1]]){
        segtree[node] = segtree[node + node];
    }
    else{
        segtree[node] = segtree[node + node + 1];
    }
}
int query(int l , int r , int node , int ql , int qr){
    if(l > qr || r < ql){
        return -1;
    }
    if(l >= ql && r <= qr){
        return segtree[node];
    }
    int mid = l + r >> 1;
    int idx1 = query(l , mid , node + node , ql , qr);
    int idx2 = query(mid + 1 , r , node + node + 1 , ql , qr);
    if(idx1 == -1){
        return idx2;
    }
    if(idx2 == -1){
        return idx1;
    }
    if(arr[idx1] > arr[idx2]){
        return idx1;
    }
    return idx2;
}
void solve(int l , int r){
    if(l >= r){
        return;
    }
    ++counter;
    int idx = query(1 , n , 1 , l , r);
    if(r - idx > idx - l){
        for(int i = l ; i <= idx ; ++i){
            Q[r].emplace_back(make_pair(idx  , (sum[i - 1] + arr[idx]) % k));
        }
    }
    else{
        for(int i = idx ; i <= r ; ++i){
            Q[idx - 1].emplace_back(make_pair(l - 1 , (sum[i] - (arr[idx] % k) + k) % k));
        }
    }
    solve(l , idx - 1);
    solve(idx + 1 , r);
}
int main(){
    cin >> n >> k;
    sum[0] = 0;
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i];
        sum[i] = (sum[i - 1] + arr[i]) % k;
    }
    build(1 , n , 1);
    solve(1 , n);
    for(int i = 0 ; i <= n ; ++i){
        pos[sum[i]].emplace_back(i);
        for(auto it : Q[i]){
            ans += pos[it.second].end() - lower_bound(pos[it.second].begin() , pos[it.second].end() , it.first);
        }
    }
    cout << ans - counter;
}