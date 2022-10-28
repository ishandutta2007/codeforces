#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
const int MAX = 1e6 + 6;
const int SN = 1 << 21;
const int NN = 1e6 + 1;
int n , q;
int arr[N];
int lll , rrr , x;
vector < int > segtree[SN];
vector < int > v[MAX];
void build(int l , int r , int node){
    if(l == r){
        segtree[node].swap(v[l]);
    }
    else{
        int mid = l + r >> 1;
        build(l , mid , node + node);
        build(mid + 1 , r , node + node + 1);
        size_t i = 0;
        size_t j = 0;
        size_t x = segtree[node + node].size();
        size_t y = segtree[node + node + 1].size();
        segtree[node].resize(x + y);
        while(i + j < x + y){
            if((j == y) || ((i != x) && (segtree[node + node][i] < segtree[node + node + 1][j]))){
                segtree[node][i + j] = segtree[node + node][i];
                ++i;
            }
            else{
                segtree[node][i + j] = segtree[node + node + 1][j];
                ++j;
            }
        }
    }
}
bool query(int l , int r , int node , int ql , int qr){
    if(l > qr || r < ql || ql > qr){
        return 0;
    }
    if(l >= ql && r <= qr){
        auto it = lower_bound(segtree[node].begin() , segtree[node].end() , lll);
        if(it != segtree[node].end() && (*it <= rrr)){
            printf("%d\n" , *it);
            return 1;
        }
        return 0;
    }
    int mid = l + r >> 1;
    return (query(l , mid , node + node , ql , qr) || query(mid + 1 , r , node + node + 1 , ql , qr));
}
int main(){
    scanf("%d %d" , &n , &q);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
        v[arr[i]].emplace_back(i);
    }
    build(1 , NN , 1);
    while(q--){
        scanf("%d %d %d" , &lll , &rrr , &x);
        if(!(query(1 , NN , 1 , 1 , x - 1) || query(1 , NN , 1 , x + 1 , NN))){
            printf("-1\n");
        }
    }
}