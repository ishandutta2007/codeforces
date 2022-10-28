#include "bits/stdc++.h"
using namespace std;
const int N = 11;
const int M = 1e5 + 5;
const int SN = 1 << 18;
int n , m , q;
int arr[M][N];
struct data{
    int lft[N];
    int rgt[N];
    int ans;
};
int parent[N << 2];
int find(int node){
    if(parent[node] == node){
        return node;
    }
    return parent[node] = find(parent[node]);
}
int name[N << 2];
int when[N << 2];
int test;
void combine(data &res , const data &l , const data &r , int idx){
    for(int i = 1 ; i <= n * 4 ; ++i){
        parent[i] = i;
    }
    res.ans = l.ans + r.ans;
    for(int i = 1 ; i <= n ; ++i){
        if(arr[idx][i] == arr[idx + 1][i]){
            if(find(l.rgt[i]) != find(r.lft[i] + 2 * n)){
                parent[find(r.lft[i] + 2 * n)] = find(l.rgt[i]);
                --res.ans;
            }
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        res.lft[i] = find(l.lft[i]);
        res.rgt[i] = find(r.rgt[i] + 2 * n);
    }
    ++test;
    int cur = 0;
    for(int i = 1 ; i <= n ; ++i){
        int &l = res.lft[i];
        if(when[l] != test){
            when[l] = test;
            name[l] = ++cur;
        }
        l = name[l];
    }
    for(int i = 1 ; i <= n ; ++i){
        int &r = res.rgt[i];
        if(when[r] != test){
            when[r] = test;
            name[r] = ++cur;
        }
        r = name[r];
    }
}
data segtree[SN];
void build(int l , int r , int node){
    if(l == r){
        segtree[node].ans = 0;
        for(int j = 1 ; j <= n ; ++j){
            segtree[node].ans += arr[l][j] != arr[r][j - 1];
            segtree[node].lft[j] = segtree[node].rgt[j] = segtree[node].ans;
        }
    }
    else{
        int mid = l + r >> 1;
        build(l , mid , node + node);
        build(mid + 1 , r , node + node + 1);
        combine(segtree[node] , segtree[node + node] , segtree[node + node + 1] , mid);
    }
}
data query(int l , int r , int node , int ql , int qr){
    if(l >= ql && r <= qr){
        return segtree[node];
    }
    int mid = l + r >> 1;
    if(qr <= mid){
        return query(l , mid , node + node , ql , qr);
    }
    if(ql > mid){
        return query(mid + 1 , r , node + node + 1 , ql , qr);
    }
    data res;
    combine(res , query(l , mid , node + node , ql , qr) , query(mid + 1 , r , node + node + 1 , ql , qr) , mid);
    return res;
}
int main(){
    scanf("%d %d %d" , &n , &m , &q);
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j){
            scanf("%d" , &arr[j][i]);
        }
    }
    build(1 , m , 1);
    while(q--){
        int l , r;
        scanf("%d %d" , &l , &r);
        printf("%d\n" , query(1 , m , 1 , l , r).ans);
    }
}