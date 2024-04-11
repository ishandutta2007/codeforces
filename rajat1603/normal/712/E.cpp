#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int SN = 1 << 18;
int n , q;
int a[N];
int b[N];
int type , l , r;
typedef pair < pair < double , double > , pair < double , double > > mat;
typedef pair < double , double > vec;
mat segtree[SN];
mat unrekt(mat res){
    if(max(max(res.first.first , res.first.second) , max(res.second.first , res.second.second)) > 1e9){
        res.first.first /= 1e9;
        res.first.second /= 1e9;
        res.second.first /= 1e9;
        res.second.second /= 1e9;
    }
    return res;
}
mat operator * (mat a , mat b){
    return unrekt(mat{{a.first.first * b.first.first + a.first.second * b.second.first , a.first.first * b.first.second + a.first.second * b.second.second} , {a.second.first * b.first.first + a.second.second * b.second.first , a.second.first * b.first.second + a.second.second * b.second.second}});
}
vec operator * (mat a , vec b){
    return vec{a.first.first * b.first + a.first.second * b.second , a.second.first * b.first + a.second.second * b.second};
}
void build(int l , int r , int node){
    if(l == r){
        segtree[node] = mat{{1 , 0} , {1 , 1.0 * (b[l] - a[r]) / a[l]}};
    }
    else{
        int mid = l + r >> 1;
        build(l , mid , node + node);
        build(mid + 1 , r , node + node + 1);
        segtree[node] = segtree[node + node] * segtree[node + node + 1];
    }
}
void update(int l , int r , int node , int idx){
    if(l == r){
        segtree[node] = mat{{1 , 0} , {1 , 1.0 * (b[l] - a[r]) / a[l]}};
    }
    else{
        int mid = l + r >> 1;
        if(idx <= mid){
            update(l , mid , node + node , idx);
        }
        else{
            update(mid + 1 , r , node + node + 1 , idx);
        }
        segtree[node] = segtree[node + node] * segtree[node + node + 1];
    }
}
mat query(int l , int r , int node , int ql , int qr){
    if(l > qr || r < ql || ql > qr){
        return mat{{1 , 0} , {0 , 1}};
    }
    if(l >= ql && r <= qr){
        return segtree[node];
    }
    int mid = l + r >> 1;
    return query(l , mid , node + node , ql , qr) * query(mid + 1 , r , node + node + 1 , ql , qr);
}
int main(){
    scanf("%d %d" , &n , &q);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d %d" , a + i , b + i);
    }
    build(1 , n , 1);
    while(q--){
        scanf("%d" , &type);
        if(type == 1){
            int i;
            scanf("%d" , &i);
            scanf("%d %d" , a + i , b + i);
            update(1 , n , 1 , i);
        }
        else{
            scanf("%d %d" , &l , &r);
            vec ans = query(1 , n , 1 , l , r - 1) * vec{a[r] , b[r]};
            printf("%.6lf\n" , ans.first / ans.second);
        }
    }
}